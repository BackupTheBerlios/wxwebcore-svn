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

#import "KWQRegion.h"

QRegion::QRegion(const QRect &rect)
{
	m_region = new wxRegion(rect);
}

QRegion::QRegion(int x, int y, int w, int h, RegionType t)
{
	m_regionType = t;
	m_region = new wxRegion(x, y, w, h);
}

QRegion::QRegion(const QPointArray &arr)
{
	m_regionType = Rectangle; //I assume...
    int len = (int)arr.size()-1;
	wxPoint points[len];
    for (uint i = 0; i < arr.size(); ++i) {
        points[i] = wxPoint(arr[i].x(), arr[i].y());
    }
	
	//TODO: wx docs say this constructor only works with MSW and QTK
	//double-check and see if we can impl on Mac if so.
	m_region = new wxRegion((size_t)arr.size(), (wxPoint *)&points);
}

QRegion::~QRegion()
{
    if (m_region)
		delete m_region;
}

QRegion::QRegion(const QRegion &other)
{
	m_region = other.m_region;
}

QRegion &QRegion::operator=(const QRegion &other)
{
    if (m_region == other.m_region) {
        return *this;
    }
    if (m_region)
		delete m_region;
	
    m_region = other.m_region;
    return *this;
}

bool QRegion::contains(const QPoint &point) const
{
    return m_region->Contains(point.x(), point.y());
}

void QRegion::translate(int deltaX, int deltaY)
{
    //TODO: Is this the same thing as translate?
	m_region->Offset(deltaX, deltaY);
}

QRect QRegion::boundingRect() const
{
    return m_region ? QRect(m_region->GetBox()) : QRect();
}
