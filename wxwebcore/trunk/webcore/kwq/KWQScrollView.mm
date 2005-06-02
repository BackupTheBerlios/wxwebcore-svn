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

#import "KWQScrollView.h"

#import "KWQLogging.h"
#import "WebCoreFrameView.h"

/*
    This class implementation does NOT actually emulate the Qt QScrollView.
    It does provide an implementation that khtml will use to interact with
    WebKit's WebFrameView documentView and our NSScrollView subclass.

    QScrollView's view is a NSScrollView (or subclass of NSScrollView)
    in most cases. That scrollview is a subview of an
    WebCoreFrameView. The WebCoreFrameView's documentView will also be
    the scroll view's documentView.
    
    The WebCoreFrameView's size is the frame size.  The WebCoreFrameView's documentView
    corresponds to the frame content size.  The scrollview itself is autosized to the
    WebCoreFrameView's size (see QWidget::resize).
*/

QWidget* QScrollView::viewport() const
{
    return const_cast<QScrollView *>(this);
}

int QScrollView::visibleWidth() const
{
	if (m_scrollWin)
		return m_scrollWin->GetSize().GetWidth();
    return 0;
}

int QScrollView::visibleHeight() const
{
	if (m_scrollWin)
		return m_scrollWin->GetSize().GetHeight();
    
    return 0;
}

int QScrollView::contentsWidth() const
{
	if (m_scrollWin)
		return m_scrollWin->GetVirtualSize().GetWidth();

    return 0;
}

int QScrollView::contentsHeight() const
{
	if (m_scrollWin)
		return m_scrollWin->GetVirtualSize().GetHeight();

    return 0;
}

int QScrollView::contentsX() const
{
	int x = 0;
	if (m_scrollWin)
		m_scrollWin->GetViewStart(x, NULL);
		
    return x;
}

int QScrollView::contentsY() const
{
	int y = 0;
	if (m_scrollWin)
		m_scrollWin->GetViewStart(NULL, y);
		
    return y;
}

int QScrollView::childX(QWidget* w)
{
    return w->x();
}

int QScrollView::childY(QWidget* w)
{
    return w->y();
}

void QScrollView::scrollBy(int dx, int dy)
{
    setContentsPos(contentsX() + dx, contentsY() + dy);
}

void QScrollView::setContentsPos(int x, int y)
{
    x = (x < 0) ? 0 : x;
    y = (y < 0) ? 0 : y;
	
	if (m_scrollWin)
		m_scrollWin->Scroll(x, y);
}

void QScrollView::setVScrollBarMode(ScrollBarMode vMode)
{
// FIXME: Is there any way to implement this in wx?
#if 0
    NSView* view = getView();

    KWQ_BLOCK_EXCEPTIONS;
    if ([view conformsToProtocol:@protocol(WebCoreFrameView)]) {
        NSView<WebCoreFrameView>* frameView = (NSView<WebCoreFrameView>*)view;
        [frameView setVerticalScrollingMode: (WebCoreScrollBarMode)vMode];
    }
    KWQ_UNBLOCK_EXCEPTIONS;
#endif
}

void QScrollView::setHScrollBarMode(ScrollBarMode hMode)
{
#if 0
    NSView* view = getView();

    KWQ_BLOCK_EXCEPTIONS;
    if ([view conformsToProtocol:@protocol(WebCoreFrameView)]) {
        NSView<WebCoreFrameView>* frameView = (NSView<WebCoreFrameView>*)view;
        [frameView setHorizontalScrollingMode: (WebCoreScrollBarMode)hMode];
    }
    KWQ_UNBLOCK_EXCEPTIONS;
#endif
}

void QScrollView::setScrollBarsMode(ScrollBarMode mode)
{
#if 0
    NSView* view = getView();

    KWQ_BLOCK_EXCEPTIONS;
    if ([view conformsToProtocol:@protocol(WebCoreFrameView)]) {
        NSView<WebCoreFrameView>* frameView = (NSView<WebCoreFrameView>*)view;
        [frameView setScrollingMode: (WebCoreScrollBarMode)mode];
    }
    KWQ_UNBLOCK_EXCEPTIONS;
#endif
}

QScrollView::ScrollBarMode
QScrollView::vScrollBarMode() const
{
#if 0
    NSView* view = getView();

    KWQ_BLOCK_EXCEPTIONS;
    if ([view conformsToProtocol:@protocol(WebCoreFrameView)]) {
        NSView<WebCoreFrameView>* frameView = (NSView<WebCoreFrameView>*)view;
        return (ScrollBarMode)[frameView verticalScrollingMode];
    }
    KWQ_UNBLOCK_EXCEPTIONS;
#endif
    return Auto;
}

QScrollView::ScrollBarMode
QScrollView::hScrollBarMode() const
{
#if 0
    NSView* view = getView();

    KWQ_BLOCK_EXCEPTIONS;
    if ([view conformsToProtocol:@protocol(WebCoreFrameView)]) {
        NSView<WebCoreFrameView>* frameView = (NSView<WebCoreFrameView>*)view;
        return (ScrollBarMode)[frameView horizontalScrollingMode];
    }
    KWQ_UNBLOCK_EXCEPTIONS;
#endif
    return Auto;
}

bool QScrollView::hasVerticalScrollBar() const
{
	if (m_scrollWin)
		return m_scrollWin->HasScrollbar(wxVERTICAL);

    return false;
}

bool QScrollView::hasHorizontalScrollBar() const
{
	if (m_scrollWin)
		return m_scrollWin->HasScrollbar(wxHORIZONTAL);

    return false;
}

void QScrollView::suppressScrollBars(bool suppressed,  bool repaintOnUnsuppress)
{
#if 0
    NSView* view = getView();

    KWQ_BLOCK_EXCEPTIONS;
    if ([view conformsToProtocol:@protocol(WebCoreFrameView)]) {
        NSView<WebCoreFrameView>* frameView = (NSView<WebCoreFrameView>*)view;
        [frameView setScrollBarsSuppressed: suppressed
                       repaintOnUnsuppress: repaintOnUnsuppress];
    }
    KWQ_UNBLOCK_EXCEPTIONS;
#endif
}

void QScrollView::addChild(QWidget* child, int x, int y)
{
    ASSERT(child != this);
	
	if (!m_scrollWin)
		return;
    
    // we don't need to do the offscreen position initialization that KDE needs
    if (x != -500000)
	child->move(x, y);

	if (child->getView()->GetParent())
		child->getView()->Reparent(m_scrollWin);
	else
		m_scrollWin->AddChild(child.getView());
}

void QScrollView::removeChild(QWidget* child)
{
    if (m_scrollWin)
		m_scrollWin->RemoveChild(child->getView());
}

void QScrollView::resizeContents(int w, int h)
{
    int _w = w;
    int _h = h;

	resize (_w, _h);
}

void QScrollView::updateContents(int x, int y, int w, int h, bool now)
{
    updateContents(QRect(x, y, w, h), now);
}

void QScrollView::updateContents(const QRect &rect, bool now)
{
    KWQ_BLOCK_EXCEPTIONS;

    if (!m_scrollWin)
		return;
		
	m_scrollWin->RefreshRect(rect);
	
	if (now)
		m_scrollWin->Update();
}

void QScrollView::repaintContents(int x, int y, int w, int h, bool erase)
{
    m_scrollWin->RefreshRect(wxRect(x, y, w, h), erase);
}

QPoint QScrollView::contentsToViewport(const QPoint &p)
{
    int vx, vy;
    contentsToViewport(p.x(), p.y(), vx, vy);
    return QPoint(vx, vy);
}

// NB, for us "viewport" means the NSWindow's coord system, which is origin lower left

void QScrollView::contentsToViewport(int x, int y, int& vx, int& vy)
{
    KWQ_BLOCK_EXCEPTIONS;

    NSView *docView;
    NSView *view = getView();    
     
    docView = getDocumentView();
    if (docView)
        view = docView;
    
    NSPoint np = [view convertPoint: NSMakePoint (x, y) toView: nil];
    vx = (int)np.x;
    vy = (int)np.y;
    
    return;

    KWQ_UNBLOCK_EXCEPTIONS;
    
    vx = 0;
    vy = 0;
}

void QScrollView::viewportToContents(int vx, int vy, int& x, int& y)
{
    KWQ_BLOCK_EXCEPTIONS;

    NSView *docView;
    NSView *view = getView();    

    docView = getDocumentView();
    if (docView)
        view = docView;
        
    NSPoint np = [view convertPoint: NSMakePoint (vx, vy) fromView: nil];
    x = (int)np.x;
    y = (int)np.y;

    return;

    KWQ_UNBLOCK_EXCEPTIONS;

    x = 0;
    y = 0;
}

void QScrollView::setStaticBackground(bool b)
{
#if 0
    NSScrollView *view = (NSScrollView *)getView();
    KWQ_BLOCK_EXCEPTIONS;
    if ([view _KWQ_isScrollView])
        [[view contentView] setCopiesOnScroll: !b];
    KWQ_UNBLOCK_EXCEPTIONS;
#endif
}

void QScrollView::resizeEvent(QResizeEvent *)
{
}

void QScrollView::setContentsPosRecursive(int x, int y)
{
#if 0
    KWQ_BLOCK_EXCEPTIONS;
    [getDocumentView() _KWQ_scrollPointRecursive:NSMakePoint(x, y)];
    KWQ_UNBLOCK_EXCEPTIONS;
#endif
}

void QScrollView::ensureVisible(int x, int y)
{
	// Troll tech docs 
	setContentsPos(x-25, y-25);
}

void QScrollView::ensureVisible(int x, int y, int xmargin, int ymargin)
{
    // Note that the definition of ensureVisible in trolltech documentation says:
    // "Scrolls the content so that the point (x, y) is visible with at least the 
    // xmargin and ymargin margins (if possible, otherwise centered).", which is
    // not what we're doing here.
    KWQ_BLOCK_EXCEPTIONS;
    [getDocumentView() scrollRectToVisible:NSMakeRect(x, y, xmargin, ymargin)];
    KWQ_UNBLOCK_EXCEPTIONS;
}

void QScrollView::ensureRectVisibleCentered(const QRect &rect, bool forceCentering)
{
    KWQ_BLOCK_EXCEPTIONS;
    [getDocumentView() _KWQ_scrollRectToVisible:NSMakeRect(rect.x(), rect.y(), rect.width(), rect.height()) forceCentering:forceCentering];
    KWQ_UNBLOCK_EXCEPTIONS;
}

NSView *QScrollView::getDocumentView() const
{
    id view = getView();

    KWQ_BLOCK_EXCEPTIONS;
    if ([view respondsToSelector:@selector(documentView)]) 
	return [view documentView];
    KWQ_UNBLOCK_EXCEPTIONS;
    
    return nil;
}

bool QScrollView::isQScrollView() const
{
    return true;
}
