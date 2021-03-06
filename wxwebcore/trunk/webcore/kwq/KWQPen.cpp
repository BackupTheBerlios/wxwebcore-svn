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

#import "KWQPen.h"

QPen::QPen(const QColor &color, uint width, PenStyle style) : penStyle(style), penWidth(width), penColor(color)
{
}

const QColor &QPen::color() const
{
    return penColor;
}

uint QPen::width() const
{
    return penWidth;
}

QPen::PenStyle QPen::style() const
{
    return penStyle;
}

void QPen::setColor(const QColor &color)
{
    penColor = color;
}

void QPen::setWidth(uint width)
{
    penWidth = width;
}

void QPen::setStyle(PenStyle style)
{
    penStyle = style;
}

bool QPen::operator==(const QPen &compareTo) const
{
    return (penWidth == compareTo.penWidth) &&
        (penStyle == compareTo.penStyle) &&
        (penColor == compareTo.penColor);
}

bool QPen::operator!=(const QPen &compareTo) const
{
    return !(*this == compareTo);
}

QPen::operator wxPen() const
{
	int style;
	PenStyle thisStyle;
	switch (thisStyle){
		case SolidLine:
			style = wxSOLID;
			break;
		case DotLine:
			style = wxDOT;
			break;
		case DashLine:
			style = wxLONG_DASH;
			break;
		case NoPen:
		default:
			style = wxTRANSPARENT;
	};

	return wxPen(color(), width(), style);

}


