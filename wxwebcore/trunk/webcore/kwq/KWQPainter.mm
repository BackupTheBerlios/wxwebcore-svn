/*
 * Copyright (C) 2003 Apple Computer, Inc.  All rights reserved.
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

#import "KWQPainter.h"

#import "KWQAssertions.h"
#import "KWQFontMetrics.h"
#import "KWQKHTMLPart.h"
#import "KWQPaintDevice.h"
#import "KWQPixmap.h"
#import "KWQPointArray.h"
#import "KWQPrinter.h"
#import "KWQPtrStack.h"
#import "KWQWidget.h"
#import "WebCoreGraphicsBridge.h"
#import "WebCoreImageRenderer.h"
#import "WebCoreImageRendererFactory.h"
#import "WebCoreTextRenderer.h"
#import "WebCoreTextRendererFactory.h"

struct QPState {
    QPState() : paintingDisabled(false) { }
    QFont font;
    QPen pen;
    QBrush brush;
    QRegion clip;
    bool paintingDisabled;
};

struct QPainterPrivate {
    QPainterPrivate() : textRenderer(0), focusRingPath(0), focusRingWidth(0), focusRingOffset(0),
                        hasFocusRingColor(false) { }
    ~QPainterPrivate() { }
    QPState state;
    QPtrStack<QPState> stack;
    QFont textRendererFont;
    int focusRingWidth;
    int focusRingOffset;
    bool hasFocusRingColor;
    QColor focusRingColor;
};

#if 0
static CGColorRef CGColorFromNSColor(NSColor *color)
{
    // this needs to always use device colorspace so it can de-calibrate the color for
    // CGColor to possibly recalibrate it
    NSColor* deviceColor = [color colorUsingColorSpaceName:NSDeviceRGBColorSpace];
    float red = [deviceColor redComponent];
    float green = [deviceColor greenComponent];
    float blue = [deviceColor blueComponent];
    float alpha = [deviceColor alphaComponent];
    const float components[] = { red, green, blue, alpha };
    
    CGColorSpaceRef colorSpace = QPainter::rgbColorSpace();
    CGColorRef cgColor = CGColorCreate(colorSpace, components);
    CGColorSpaceRelease(colorSpace);
    return cgColor;
}
#endif

QPainter::QPainter() : data(new QPainterPrivate), _isForPrinting(false), _usesInactiveTextBackgroundColor(false), _drawsFocusRing(true)
{
	m_dc = wxClientDC();
}

QPainter::QPainter(bool forPrinting) : data(new QPainterPrivate), _isForPrinting(forPrinting), _usesInactiveTextBackgroundColor(false), _drawsFocusRing(true)
{
	// TODO: do we need to use wxPrinterDC if forPrinting is true here?
	m_dc = wxDC();
}

QPainter::~QPainter()
{
    delete data;
}

QPaintDevice *QPainter::device() const
{
    static QPrinter printer;
    static QPaintDevice screen;
    return _isForPrinting ? &printer : &screen;
}

const QFont &QPainter::font() const
{
    return data->state.font;
}

void QPainter::setFont(const QFont &aFont)
{
    data->state.font = aFont;
}

QFontMetrics QPainter::fontMetrics() const
{
    return data->state.font;
}

const QPen &QPainter::pen() const
{
    return data->state.pen;
}

void QPainter::setPen(const QPen &pen)
{
    data->state.pen = pen;
}

void QPainter::setPen(PenStyle style)
{
    data->state.pen.setStyle(style);
    data->state.pen.setColor(Qt::black);
    data->state.pen.setWidth(0);
}

void QPainter::setPen(QRgb rgb)
{
    data->state.pen.setStyle(SolidLine);
    data->state.pen.setColor(rgb);
    data->state.pen.setWidth(0);
}

void QPainter::setBrush(const QBrush &brush)
{
    data->state.brush = brush;
}

void QPainter::setBrush(BrushStyle style)
{
    data->state.brush.setStyle(style);
    data->state.brush.setColor(Qt::black);
}

void QPainter::setBrush(QRgb rgb)
{
    data->state.brush.setStyle(SolidPattern);
    data->state.brush.setColor(rgb);
}

const QBrush &QPainter::brush() const
{
    return data->state.brush;
}

QRect QPainter::xForm(const QRect &aRect) const
{
    // No difference between device and model coords, so the identity transform is ok.
    return aRect;
}

void QPainter::save()
{
    data->stack.push(new QPState(data->state));
}

void QPainter::restore()
{
    if (data->stack.isEmpty()) {
        ERROR("ERROR void QPainter::restore() stack is empty");
	return;
    }
    QPState *ps = data->stack.pop();
    data->state = *ps;
    delete ps;
}

// Draws a filled rectangle with a stroked border.
void QPainter::drawRect(int x, int y, int w, int h)
{
    if (data->state.paintingDisabled)
        return;
        
    if (data->state.brush.style() != NoBrush)
        _fillRect(x, y, w, h, data->state.brush.color());

    if (data->state.pen.style() != NoPen) {
        _setColorFromPen();
        drawLine(x, y, w, h);
    }
}

void QPainter::_setColorFromBrush()
{
    m_dc.SetBackground(data->state.brush.color().getNSColor());
}

void QPainter::_setColorFromPen()
{
    m_dc.SetTextForeground(data->state.pen.color());
}

// This is only used to draw borders.
void QPainter::drawLine(int x1, int y1, int x2, int y2)
{
    if (data->state.paintingDisabled || !m_dc.Ok())
        return;

    PenStyle penStyle = data->state.pen.style();
    if (penStyle == NoPen)
        return;
    
	m_dc.SetPen(data->state.pen);

	m_dc.DrawLine(x1, y1, x2, y2);
}


// This method is only used to draw the little circles used in lists.
void QPainter::drawEllipse(int x, int y, int w, int h)
{
    if (data->state.paintingDisabled || !m_dc.Ok())
        return;

	m_dc.SetPen(data->state.pen);
	
	m_dc.DrawEllipse(x, y, w, h);
}


void QPainter::drawArc (int x, int y, int w, int h, int a, int alen)
{ 
    if (data->state.paintingDisabled || !m_dc.Ok())
        return;
    
    if (data->state.pen.style() != NoPen) {
		// Qt specifies angles in 1/16 degrees, wx uses full degrees
		// not sure if that will be a problem for us or not...
        m_dc.DrawEllipticArc(x, y, w, h, (a/16), (alen/16));
    }
}

void QPainter::drawLineSegments(const QPointArray &points, int index, int nlines)
{	
    if (data->state.paintingDisabled || !m_dc.Ok())
        return;
    
    _drawPoints (points, 0, index, nlines, false);
}

void QPainter::drawPolyline(const QPointArray &points, int index, int npoints)
{
    _drawPoints (points, 0, index, npoints, false);
}

void QPainter::drawPolygon(const QPointArray &points, bool winding, int index, 
    int npoints)
{
    if (data->state.paintingDisabled || !m_dc.Ok())
		return; 
		
	_drawPoints(points, winding, index, npoints, true);
	
}

void QPainter::drawConvexPolygon(const QPointArray &points)
{
    _drawPoints (points, false, 0, -1, true);
}

void QPainter::_drawPoints (const QPointArray &_points, bool winding, int index, int _npoints, bool fill)
{
    if (data->state.paintingDisabled || !m_dc.Ok())
        return;
	
	// NOTE: I'm unclear as to why they do things this way. There's no 
	// npoints param in Qt docs, and it seems if npoints is specified
	// it overrides index, which IS in Qt docs. In any case, I chose to  
	// mirror the implementation as it works for WebCore.
	// This is also done in drawPolygon above.
	  
    int npoints = _npoints != -1 ? _npoints : _points.size()-index;
    wxPoint points[npoints];
    for (int i = 0; i < npoints; i++) {
        points[i] = wxPoint(_points[index+i]);
    }
	
	m_dc.SetPen(data->state.pen);
	m_dc.SetBrush(data->state.brush);
    
    if (!fill) {
        m_dc.SetBrush(wxNullBrush);
    }

	int windingRule = wxODDEVEN_RULE;
	if (winding)
		windingRule = wxWINDING_RULE;
		
	// A note from Apple's impl states that they confirmed that all the above
	// functions close the path, and from Qt's docs, drawConvexPolygon gives 
	//"undefined results" if given points that don't create a convex polygon.
	// So all of these functions draw a polygon...
	
	m_dc.DrawPolygon(npoints, wxPoints, 0, 0, windingRule);
}


void QPainter::drawPixmap(const QPoint &p, const QPixmap &pix)
{        
    drawPixmap(p.x(), p.y(), pix);
}


void QPainter::drawPixmap(const QPoint &p, const QPixmap &pix, const QRect &r)
{
    drawPixmap(p.x(), p.y(), pix, r.x(), r.y(), r.width(), r.height());
}

struct CompositeOperator
{
    const char *name;
    NSCompositingOperation value;
};

#define NUM_COMPOSITE_OPERATORS 14
struct CompositeOperator compositeOperators[NUM_COMPOSITE_OPERATORS] = {
    { "clear", wxCLEAR },
    { "copy", wxCOPY },
    { "source-over", NSCompositeSourceOver },
    { "source-in", NSCompositeSourceIn },
    { "source-out", NSCompositeSourceOut },
    { "source-atop", NSCompositeSourceAtop },
    { "destination-over", NSCompositeDestinationOver },
    { "destination-in", NSCompositeDestinationIn },
    { "destination-out", NSCompositeDestinationOut },
    { "destination-atop", NSCompositeDestinationAtop },
    { "xor", wxXOR },
    { "darker", NSCompositePlusDarker },
    { "highlight", NSCompositeHighlight },
    { "lighter", NSCompositePlusLighter }
};

int QPainter::getCompositeOperation(CGContextRef context)
{
	return 0;
#if 0
    return (int)[[WebCoreImageRendererFactory sharedFactory] CGCompositeOperationInContext:context];
#endif
}

void QPainter::setCompositeOperation (CGContextRef context, QString op)
{
#if 0
    [[WebCoreImageRendererFactory sharedFactory] setCGCompositeOperationFromString:op.getNSString() inContext:context];
#endif
}

void QPainter::setCompositeOperation (CGContextRef context, int op)
{
#if 0
    [[WebCoreImageRendererFactory sharedFactory] setCGCompositeOperation:op inContext:context];
#endif
}

int QPainter::compositeOperatorFromString (QString aString)
{
#if 0
    NSCompositingOperation op = NSCompositeSourceOver;
    
    if (aString.length()) {
        const char *operatorString = aString.ascii();
        int i;
        
        for (i = 0; i < NUM_COMPOSITE_OPERATORS; i++) {
            if (strcasecmp (operatorString, compositeOperators[i].name) == 0) {
                return compositeOperators[i].value;
            }
        }
    }
    return (int)op;
#endif

	return 0;
}

void QPainter::drawPixmap(const QPoint &p, const QPixmap &pix, const QRect &r, const QString &compositeOperator)
{
    drawPixmap(p.x(), p.y(), pix, r.x(), r.y(), r.width(), r.height(), compositeOperatorFromString(compositeOperator));
}

void QPainter::drawPixmap( int x, int y, const QPixmap &pixmap,
                           int sx, int sy, int sw, int sh, int compositeOperator, CGContextRef context)
{
    drawPixmap (x, y, sw, sh, pixmap, sx, sy, sw, sh, compositeOperator, context);
}

void QPainter::drawPixmap( int x, int y, int w, int h, const QPixmap &pixmap,
                           int sx, int sy, int sw, int sh, int compositeOperator, CGContextRef context)
{
    drawFloatPixmap ((float)x, (float)y, (float)w, (float)h, pixmap, (float)sx, (float)sy, (float)sw, (float)sh, compositeOperator, context);
}

void QPainter::drawFloatPixmap( float x, float y, float w, float h, const QPixmap &pixmap,
                           float sx, float sy, float sw, float sh, int compositeOperator, CGContextRef context)
{
    if (data->state.paintingDisabled || !m_dc.Ok())
        return;
	
    if (sw == -1)
        sw = pixmap.width();
    if (sh == -1)
        sh = pixmap.height();

    if (w == -1)
        w = pixmap.width();
    if (h == -1)
        h = pixmap.height();

    wxRect paintInRect = wxRect(x, y, w, h);
	wxRect portionToPaint = wxRect(sx, sy, sw, sh);
	
	// the s* params are the portion of the pixmap that are to be drawn
	// so we need to crop the bitmap first
	wxBitmap bitmap = pixmap;
	wxBitmap paintBitmap = wxBitmap(bitmap.GetSubBitmap(portionToPaint));
	
	m_dc.DrawBitmap(paintBitmap, x, y, true); // FIXME: anyway we can support the w and h params??
}

void QPainter::drawTiledPixmap( int x, int y, int w, int h,
				const QPixmap &pixmap, int sx, int sy, CGContextRef context)
{
    if (data->state.paintingDisabled || !m_dc.Ok())
        return;
    
	wxBitmap bitmap = pixmap;
    int width = bitmap.GetWidth();
    int height = bitmap.GetHeight();
    
	wxBitmap paintBitmap = bitmap;
	if (sx > 0 || sy > 0) {
		// again, we need to deal with sx, sy
		wxRect subRect = wxRect(sx, sy, width-sx, height-sy);
		paintBitmap = bitmap.GetSubBitmap(subRect);
	}
		
    int i, j;
    for (i = x; i < x + w; i += width)
    {
        for (j = y; j < y + h; j+= height)
            dc.DrawBitmap(bitmap, i, j);
    }
}

void QPainter::_updateRenderer()
{
#if 0
    if (data->textRenderer == 0 || data->state.font != data->textRendererFont) {
        data->textRendererFont = data->state.font;
        id <WebCoreTextRenderer> oldRenderer = data->textRenderer;
	KWQ_BLOCK_EXCEPTIONS;
        data->textRenderer = KWQRetain([[WebCoreTextRendererFactory sharedFactory]
            rendererWithFont:data->textRendererFont.getNSFont()
            usingPrinterFont:data->textRendererFont.isPrinterFont()]);
        KWQRelease(oldRenderer);
	KWQ_UNBLOCK_EXCEPTIONS;
    }
#endif
}
    
void QPainter::drawText(int x, int y, int, int, int alignmentFlags, const QString &qstring)
{
    if (data->state.paintingDisabled || !m_dc.Ok())
        return;

    _updateRenderer();

    wxString text = qstring;

	m_dc.SetPen(data->style.pen);
	m_dc.SetFont(data->style.font);
	m_dc.SetBrush(data->style.brush);
	
	// TODO: For both drawText methods, we need to determine a way to handle text "families"
	// i.e. sets of equivalent fonts for when one is not available
	
	
	m_dc.DrawText(qstring, x, y);

#if 0
    WebCoreTextRun run;
    WebCoreInitializeTextRun(&run, str, qstring.length(), 0, qstring.length());
    
    WebCoreTextStyle style;
    WebCoreInitializeEmptyTextStyle(&style);
    style.textColor = data->state.pen.color().getNSColor();
    style.families = families;

	// FIXME: Can wx handle aligned text??
    if (alignmentFlags & Qt::AlignRight)
        x -= ROUND_TO_INT([data->textRenderer floatWidthForRun:&run style:&style widths:0]);

    WebCoreTextGeometry geometry;
    WebCoreInitializeEmptyTextGeometry(&geometry);
    geometry.point = NSMakePoint(x, y);

    [data->textRenderer drawRun:&run style:&style geometry:&geometry];
#endif
}

void QPainter::drawText(int x, int y, const QChar *str, int len, int from, int to, int toAdd, const QColor &backgroundColor, QPainter::TextDirection d, bool visuallyOrdered, int letterSpacing, int wordSpacing, bool smallCaps)
{
    if (data->state.paintingDisabled || len <= 0 || !m_dc.Ok())
        return;

    // Avoid allocations, use stack array to pass font families.  Normally these
    // css fallback lists are small <= 3.
    CREATE_FAMILY_ARRAY(data->state.font, families);

    _updateRenderer();

    if (from < 0)
        from = 0;
    if (to < 0)
        to = len;
		
	m_dc.SetPen(data->style.pen);
	m_dc.SetFont(data->style.font);
	m_dc.SetBrush(data->style.brush);
	
	m_dc.SetBackground(wxBrush(backgroundColor, wxSOLID));
	// TODO: For both drawText methods, we need to determine a way to handle text "families"
	// i.e. sets of equivalent fonts for when one is not available
	wxString cutString = wxString(str);
	
	m_dc.DrawText(cutString.Mid(from, to-from), x, y);

#if 0
    WebCoreTextRun run;
    WebCoreInitializeTextRun(&run, (const UniChar *)str, len, from, to);    
    WebCoreTextStyle style;
    WebCoreInitializeEmptyTextStyle(&style);
    style.textColor = data->state.pen.color().getNSColor();
    style.backgroundColor = backgroundColor.isValid() ? backgroundColor.getNSColor() : nil;
    style.rtl = d == RTL ? true : false;
    style.visuallyOrdered = visuallyOrdered;
    style.letterSpacing = letterSpacing;
    style.wordSpacing = wordSpacing;
    style.smallCaps = smallCaps;
    style.families = families;
    style.padding = toAdd;
    WebCoreTextGeometry geometry;
    WebCoreInitializeEmptyTextGeometry(&geometry);
    geometry.point = NSMakePoint(x, y);
    
    [data->textRenderer drawRun:&run style:&style geometry:&geometry];
#endif
}

void QPainter::drawHighlightForText(int x, int y, int h, 
    const QChar *str, int len, int from, int to, int toAdd, const QColor &backgroundColor, 
    QPainter::TextDirection d, bool visuallyOrdered, int letterSpacing, int wordSpacing, bool smallCaps)
{
    if (data->state.paintingDisabled || len <= 0 || !m_dc.Ok())
        return;

	drawText(x, y, str, len, from, to, toAdd, backgroundColor, d, visuallyOrdered, letterSpacing, wordSpacing, smallCaps);
	return;
	
	// FIXME: I believe this draws the selection color around text, but I don't see why
	// there needs to be a special method for this... 
	
    // Avoid allocations, use stack array to pass font families.  Normally these
    // css fallback lists are small <= 3.
    CREATE_FAMILY_ARRAY(data->state.font, families);

    _updateRenderer();

    if (from < 0)
        from = 0;
    if (to < 0)
        to = len;
        
#if 0		
    WebCoreTextRun run;
    WebCoreInitializeTextRun(&run, (const UniChar *)str, len, from, to);    
    WebCoreTextStyle style;
    WebCoreInitializeEmptyTextStyle(&style);
    style.textColor = data->state.pen.color().getNSColor();
    style.backgroundColor = backgroundColor.isValid() ? backgroundColor.getNSColor() : nil;
    style.rtl = d == RTL ? true : false;
    style.visuallyOrdered = visuallyOrdered;
    style.letterSpacing = letterSpacing;
    style.wordSpacing = wordSpacing;
    style.smallCaps = smallCaps;
    style.families = families;    
    style.padding = toAdd;
    WebCoreTextGeometry geometry;
    WebCoreInitializeEmptyTextGeometry(&geometry);
    geometry.point = NSMakePoint(x, y);
    geometry.selectionY = y;
    geometry.selectionHeight = h;
    geometry.useFontMetricsForSelectionYAndHeight = false;
    [data->textRenderer drawHighlightForRun:&run style:&style geometry:&geometry];
#endif
}

void QPainter::drawLineForText(int x, int y, int yOffset, int width)
{
    if (data->state.paintingDisabled || !m_dc.Ok())
        return;
    _updateRenderer();
	
	m_dc.SetBrush(data->style.brush);
	m_dc.SetPen(data->style.pen);
	// TODO: will SetDeviceOrigin handle yOffset?
	m_dc.DrawLine(x, y, x+width, y);
	
#if 0
    [data->textRenderer
        drawLineForCharacters: NSMakePoint(x, y)
               yOffset:(float)yOffset
                 width: width
                 color:data->state.pen.color().getNSColor()
             thickness:data->state.pen.width()];
#endif
}

void QPainter::drawLineForMisspelling(int x, int y, int width)
{
    if (data->state.paintingDisabled || !m_dc.Ok())
        return;
    _updateRenderer();
	
	m_dc.SetBrush(data->style.brush);
	m_dc.SetPen(wxPen(wxRED, 2, wxSHORT_DASH));
	
	m_dc.DrawLine(x, y, x+width, y);
	
#if 0
    [data->textRenderer drawLineForMisspelling:NSMakePoint(x, y) withWidth:width];
#endif
}

int QPainter::misspellingLineThickness() const
{
	return 1;
#if 0
    return [data->textRenderer misspellingLineThickness];
#endif
}

static int getBlendedColorComponent(int c, int a)
{
    // We use white.
    float alpha = (float)(a) / 255;
    int whiteBlend = 255 - a;
    c -= whiteBlend;
    return (int)(c/alpha);
}

QColor QPainter::selectedTextBackgroundColor() const
{
#if 0
    NSColor *color = _usesInactiveTextBackgroundColor ? [NSColor secondarySelectedControlColor] : [NSColor selectedTextBackgroundColor];
    // this needs to always use device colorspace so it can de-calibrate the color for
    // QColor to possibly recalibrate it
    color = [color colorUsingColorSpaceName:NSDeviceRGBColorSpace];
    
    QColor col = QColor((int)(255 * [color redComponent]), (int)(255 * [color greenComponent]), (int)(255 * [color blueComponent]));
#endif

	// FIXME: Is this the appropriate color for selected text on all platforms?
	
	QColor col = QColor(wxColour(wxSYS_COLOUR_HIGHLIGHTTEXT));
	
    // Attempt to make the selection 60% transparent.  We do this by applying a standard blend and then
    // seeing if the resultant color is still within the 0-255 range.
    int alpha = 153;
    int red = getBlendedColorComponent(col.red(), alpha);
    int green = getBlendedColorComponent(col.green(), alpha);
    int blue = getBlendedColorComponent(col.blue(), alpha);
    if (red >= 0 && red <= 255 && green >= 0 && green <= 255 && blue >= 0 && blue <= 255)
        return QColor(qRgba(red, green, blue, alpha));
    return col;
}

void QPainter::_fillRect(int x, int y, int w, int h, const QColor& col)
{
	m_dc.SetBackground(col);
	m_dc.SetPen(wxNullPen);
	m_dc.DrawRect(x, y, w, h);
}

void QPainter::fillRect(int x, int y, int w, int h, const QBrush &brush)
{
    if (data->state.paintingDisabled)
        return;

    if (brush.style() == SolidPattern)
        _fillRect(x, y, w, h, brush.color());
}

void QPainter::fillRect(const QRect &rect, const QBrush &brush)
{
    fillRect(rect.left(), rect.top(), rect.width(), rect.height(), brush);
}

void QPainter::addClip(const QRect &rect)
{
	m_dc.SetClippingRegion(rect);
}

Qt::RasterOp QPainter::rasterOp() const
{
    return CopyROP;
}

void QPainter::setRasterOp(RasterOp)
{
}

void QPainter::setPaintingDisabled(bool f)
{
    data->state.paintingDisabled = f;
}

bool QPainter::paintingDisabled() const
{
    return data->state.paintingDisabled;
}

void QPainter::beginTransparencyLayer(float opacity)
{
#if 0
    [NSGraphicsContext saveGraphicsState];
    CGContextRef context = (CGContextRef)([[NSGraphicsContext currentContext] graphicsPort]);
    CGContextSetAlpha(context, opacity);
    CGContextBeginTransparencyLayer(context, 0);
#endif
}

void QPainter::endTransparencyLayer()
{
#if 0
    CGContextRef context = (CGContextRef)([[NSGraphicsContext currentContext] graphicsPort]);
    CGContextEndTransparencyLayer(context);
    [NSGraphicsContext restoreGraphicsState];
#endif
}

void QPainter::setShadow(int x, int y, int blur, const QColor& color)
{
#if 0
    //Check for an invalid color, as this means that the color was not set for the shadow
    // and we should therefore just use the default shadow color.
    CGContextRef context = (CGContextRef)([[NSGraphicsContext currentContext] graphicsPort]);
    if (!color.isValid()) {
        CGContextSetShadow(context, CGSizeMake(x,-y), blur); // y is flipped.
    } else {
	CGColorRef cgColor = CGColorFromNSColor(color.getNSColor());
        CGContextSetShadowWithColor(context,
                                    CGSizeMake(x,-y), // y is flipped.
                                    blur, 
                                    cgColor);
        CGColorRelease(cgColor);
    }
#endif
}

void QPainter::clearShadow()
{
#if 0
    CGContextRef context = (CGContextRef)([[NSGraphicsContext currentContext] graphicsPort]);
    CGContextSetShadowWithColor(context, CGSizeZero, 0, NULL);
#endif
}

void QPainter::initFocusRing(int width, int offset)
{
#if 0
    if (!_drawsFocusRing)
        return;

    clearFocusRing();
    data->focusRingWidth = width;
    data->hasFocusRingColor = false;
    data->focusRingOffset = offset;
    data->focusRingPath = KWQRetainNSRelease([[NSBezierPath alloc] init]);
    [data->focusRingPath setWindingRule:NSNonZeroWindingRule];
#endif
}

void QPainter::initFocusRing(int width, int offset, const QColor &color)
{
#if 0
    if (!_drawsFocusRing)
        return;

    initFocusRing(width, offset);
    data->hasFocusRingColor = true;
    data->focusRingColor = color;
#endif
}

void QPainter::addFocusRingRect(int x, int y, int width, int height)
{
#if 0
    if (!_drawsFocusRing)
        return;

    ASSERT(data->focusRingPath);
    NSRect rect = NSMakeRect(x, y, width, height);
    int offset = (data->focusRingWidth-1)/2 + data->focusRingOffset;
    rect = NSInsetRect(rect, -offset, -offset);
    [data->focusRingPath appendBezierPathWithRect:rect];
#endif
}

void QPainter::drawFocusRing()
{
#if 0
    if (!_drawsFocusRing)
        return;
    
    ASSERT(data->focusRingPath);
    if (data->state.paintingDisabled)
        return;

    if ([data->focusRingPath elementCount] == 0) {
        ERROR("Request to draw focus ring with no control points");
        return;
    }
    
    NSRect bounds = [data->focusRingPath bounds];
    if (!NSIsEmptyRect(bounds)) {
        int radius = (data->focusRingWidth-1)/2;
        NSColor *color = data->hasFocusRingColor ? data->focusRingColor.getNSColor() : nil;
        [NSGraphicsContext saveGraphicsState];
        [[WebCoreGraphicsBridge sharedBridge] setFocusRingStyle:NSFocusRingOnly radius:radius color:color];
        [data->focusRingPath fill];
        [NSGraphicsContext restoreGraphicsState];   
    }
#endif
}

void QPainter::clearFocusRing()
{
#if 0
    if (data->focusRingPath) {
        KWQRelease(data->focusRingPath);
        data->focusRingPath = nil;
    }
#endif
}
