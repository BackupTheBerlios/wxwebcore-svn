/*
 * Copyright (c) 2005 Kevin Ollivier
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 *
 */

/*
 * Copyright (C) 2004 Apple Computer, Inc.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE COMPUTER, INC. ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL APPLE COMPUTER, INC. OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. 
 */

#import "KWQWidget.h"

#import "KWQKHTMLPart.h"
#import "KWQLogging.h"
#import "KWQView.h"
#import "KWQWindowWidget.h"
#import "WebCoreBridge.h"
#import "WebCoreFrameView.h"
#import "WebCoreView.h"
#import "khtmlview.h"
#import "render_canvas.h"
#import "render_replaced.h"
#import "render_style.h"

#include <wx/defs.h>
#include <wx/window.h>

using khtml::RenderWidget;


class KWQWidgetPrivate
{
public:
    QStyle *style;
    QFont font;
    QPalette pal;
    wxWindow *view;
    bool visible;
    bool mustStayInWindow;
    bool removeFromSuperviewSoon;
};

QWidget::QWidget() : data(new KWQWidgetPrivate)
{
    static QStyle defaultStyle;
    data->style = &defaultStyle;
    data->view = NULL;
    data->visible = true;
    data->mustStayInWindow = false;
    data->removeFromSuperviewSoon = false;
}

QWidget::QWidget(wxWindow *view) : data(new KWQWidgetPrivate)
{
    static QStyle defaultStyle;
    data->style = &defaultStyle;
    data->view = view;
    data->visible = true;
    data->mustStayInWindow = false;
    data->removeFromSuperviewSoon = false;
}

QWidget::~QWidget() 
{
	if (data->view)
		data->view->Destroy();

    delete data;
}

QSize QWidget::sizeHint() const 
{
    // May be overriden by subclasses.
	// NOTE: Not sure if we should use wxWidgets' handling or not...
    return QSize(0,0);
}

void QWidget::resize(int w, int h) 
{
    setFrameGeometry(QRect(pos().x(), pos().y(), w, h));
}

void QWidget::setActiveWindow() 
{
	if (data->view)
		data->view->SetFocus();
}

void QWidget::setEnabled(bool enabled)
{
	if (data->view)
		data->view->Enable(true);
}

bool QWidget::isEnabled() const
{
    return data->view->IsEnabled();
}

long QWidget::winId() const
{
    return (long)this;
}

int QWidget::x() const
{
    return frameGeometry().topLeft().x();
}

int QWidget::y() const 
{
    return frameGeometry().topLeft().y();
}

int QWidget::width() const 
{ 
    return frameGeometry().size().width();
}

int QWidget::height() const 
{
    return frameGeometry().size().height();
}

QSize QWidget::size() const 
{
    return frameGeometry().size();
}

void QWidget::resize(const QSize &s) 
{
    resize(s.width(), s.height());
}

QPoint QWidget::pos() const 
{
    return frameGeometry().topLeft();
}

void QWidget::move(int x, int y) 
{
    setFrameGeometry(QRect(x, y, width(), height()));
}

void QWidget::move(const QPoint &p) 
{
    move(p.x(), p.y());
}

QRect QWidget::frameGeometry() const
{
    QRect rect;
	if (data->view)
		rect = QRect(data->view->GetRect());
	else
		rect = QRect(0, 0, 0, 0);

    return rect;
}

int QWidget::baselinePosition(int height) const
{
    return height;
}

bool QWidget::hasFocus() const
{
	if (!data->view)
		return false;

    wxWindow *hasFocus = wxWindow::FindFocus();
	if (hasFocus == data->view)
		return true;

    return false;
}

void QWidget::setFocus()
{
    if (hasFocus()) {
        return;
    }

	data->view->SetFocus();
}

void QWidget::clearFocus()
{
    if (!hasFocus()) {
        return;
    }
    
    KWQKHTMLPart::clearDocumentFocus(this);
}

bool QWidget::checksDescendantsForFocus() const
{
    return false;
}

QWidget::FocusPolicy QWidget::focusPolicy() const
{
    // This provides support for controlling the widgets that take 
    // part in tab navigation. Widgets must:
    // 1. not be hidden by css
    // 2. be enabled

    RenderWidget *widget = const_cast<RenderWidget *>
	(static_cast<const RenderWidget *>(eventFilterObject()));
    if (widget->style()->visibility() != khtml::VISIBLE)
        return NoFocus;

    if (!isEnabled())
        return NoFocus;
    
    //TODO: is there a way for wxWidgets to check if it can focus?   
    
    return TabFocus;
}

const QPalette& QWidget::palette() const
{
    return data->pal;
}

void QWidget::setPalette(const QPalette &palette)
{
    data->pal = palette;
}

QStyle &QWidget::style() const
{
    return *data->style;
}

void QWidget::setStyle(QStyle *style)
{
    // According to the Qt implementation 
    /*
    Sets the widget's GUI style to \a style. Ownership of the style
    object is not transferred.
    */
    data->style = style;
}

QFont QWidget::font() const
{
    return data->font;
}

void QWidget::setFont(const QFont &font)
{
    data->font = font;
}

void QWidget::constPolish() const
{
}

bool QWidget::isVisible() const
{    
	if (data->view)
		return data->view->IsShown();
	else
		return false;
}

void QWidget::setCursor(const QCursor &cur)
{
	if (data->view)
		data->view->SetCursor(cur.handle());
}

QCursor QWidget::cursor()
{
	if (data->view)
		return QCursor(data->view->GetCursor());
	else
		return QCursor();
}

void QWidget::unsetCursor()
{
    setCursor(QCursor());
}

bool QWidget::event(QEvent *)
{
    return false;
}

void QWidget::show()
{
    if (!data || !data->view || data->visible)
        return;

    data->visible = true;

    data->view->Show(true);
}

void QWidget::hide()
{
    if (!data || !data->view || !data->visible)
        return;

    data->visible = false;

    data->view->Show(false);
}

void QWidget::setFrameGeometry(const QRect &rect)
{
	if (data->view)
		data->view->SetSize(rect);
}

QPoint QWidget::mapFromGlobal(const QPoint &p) const
{
    wxPoint bp(0,0);

	if (data->view)
		data->view->ScreenToClient(&bp);

    return QPoint(bp);
}

wxWindow *QWidget::getView() const
{
    return data->view;
}

void QWidget::setView(NSView *view)
{
	// we'll leave this func in for now, but we should be able to just create
	// the view from the constructor in all cases. Being able to dynamically switch
	// widgets could get messy, and I doubt there's a need for it
}

// NOTE: The below are methods Apple added for their WebCore port. Most of them
// are Cocoa specific and won't be needed, but I'm leaving these in until we convert
// the classes that call these functions. At that time, I'll determine whether we
// should implement these functions, or just write a separate implementation.

/*
void QWidget::lockDrawingFocus()
{
    ;
    [getView() lockFocus];
    ;
}

void QWidget::unlockDrawingFocus()
{
    ;
    //TODO: NYI this is a Cocoa addition
    ;
}

void QWidget::disableFlushDrawing()
{
    // It's OK to use the real window here, because if the view's not
    // in the view hierarchy, then we don't actually want to affect
    // flushing.
    ;
    //TODO: NYI this is a Cocoa addition
    ;
}

void QWidget::enableFlushDrawing()
{
    // It's OK to use the real window here, because if the view's not
    // in the view hierarchy, then we don't actually want to affect
    // flushing.
    ;
    //TODO: NYI this is a Cocoa addition
    ;
}

void QWidget::setDrawingAlpha(float alpha)
{
    ;
    //TODO: NYI this is a Cocoa addition
    ;
}

void QWidget::paint(QPainter *p, const QRect &r)
{
    if (p->paintingDisabled()) {
        return;
    }
    //TODO: NYI this is a Cocoa addition
}

void QWidget::sendConsumedMouseUp()
{
    khtml::RenderWidget *widget = const_cast<khtml::RenderWidget *>
	(static_cast<const khtml::RenderWidget *>(eventFilterObject()));

    //TODO: NYI this is a Cocoa addition 
}

void QWidget::setIsSelected(bool isSelected)
{
    //TODO: NYI this is a Cocoa addition 
}

void QWidget::addToSuperview(NSView *superview)
{
    ;

    ASSERT(superview);
    NSView *subview = getOuterView();
    ASSERT(![superview isDescendantOf:subview]);
    if ([subview superview] != superview)
        [superview addSubview:subview];
    data->removeFromSuperviewSoon = false;

    ;
}

void QWidget::removeFromSuperview()
{
    if (data->mustStayInWindow)
        data->removeFromSuperviewSoon = true;
    else {
        ;
        [getOuterView() removeFromSuperview];
        ;
        data->removeFromSuperviewSoon = false;
    }
}

void QWidget::beforeMouseDown(NSView *view)
{
    ASSERT([view conformsToProtocol:@protocol(KWQWidgetHolder)]);
    QWidget *widget = [(NSView <KWQWidgetHolder> *)view widget];
    if (widget) {
        ASSERT(view == widget->getOuterView());
        ASSERT(!widget->data->mustStayInWindow);
        widget->data->mustStayInWindow = true;
    }
}

void QWidget::afterMouseDown(NSView *view)
{
    ASSERT([view conformsToProtocol:@protocol(KWQWidgetHolder)]);
    QWidget *widget = [(NSView <KWQWidgetHolder> *)view widget];
    if (!widget) {
        ;
        [view removeFromSuperview];
        ;
    } else {
        ASSERT(widget->data->mustStayInWindow);
        widget->data->mustStayInWindow = false;
        if (widget->data->removeFromSuperviewSoon)
            widget->removeFromSuperview();
    }
}

void QWidget::setDeferFirstResponderChanges(bool defer)
{
    deferFirstResponderChanges = defer;
    if (!defer) {
        QWidget *r = deferredFirstResponder;
        deferredFirstResponder = 0;
        if (r) {
            r->setFocus();
        }
    }
}
*/