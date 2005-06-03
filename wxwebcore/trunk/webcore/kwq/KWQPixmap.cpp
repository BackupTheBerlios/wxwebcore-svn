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
#import "loader.h"

#import "KWQPixmap.h"

QPixmap *KWQLoadPixmap(const char *name)
{
	// wxImage supports more formats than wxBitmap, so create
	// then convert.
	wxImage newImage = wxImage(wxString(name, wxConvFile));
	
    QPixmap *p = new QPixmap(wxBitmap(newImage));
    return p;
}

bool canRenderImageType(const QString &type)
{
	return true;
}

QPixmap::QPixmap()
{
    m_bitmap = wxBitmap();
    MIMEType = wxEmptyString;
    needCopyOnWrite = false;
}

QPixmap::QPixmap(const wxBitmap& bitmap)
{
    m_bitmap = bitmap;
    MIMEType = wxEmptyString;
    needCopyOnWrite = false;
}

QPixmap::QPixmap(QString MIME)
{
    m_bitmap = wxBitmap();
    MIMEType = MIME;
    needCopyOnWrite = false;
}

QPixmap::QPixmap(const QSize &sz)
{
    m_bitmap = wxBitmap(sz.width(), sz.height());
    MIMEType = wxEmptyString;
    needCopyOnWrite = false;
}

QPixmap::QPixmap(const QByteArray &bytes)
{
	//TODO: wxBitmap/Image need to have dimensions passed in...
    //m_bitmap = wxBitmap();
	MIMEType = wxEmptyString;
    needCopyOnWrite = false;
}

QPixmap::QPixmap(const QByteArray &bytes, const wxString& MIME)
{
    MIMEType = wxString(MIME);
	//TODO: wxBitmap/Image need to have dimensions passed in...
    //m_bitmap = wxBitmap();
    needCopyOnWrite = false;
}

QPixmap::QPixmap(int w, int h)
{
    m_bitmap = wxBitmap(w, h);
    MIMEType = wxEmptyString;
    needCopyOnWrite = false;
}

QPixmap::QPixmap(const QPixmap &copyFrom) : QPaintDevice(copyFrom)
{
    imageRenderer = copyFrom.imageRenderer;
    needCopyOnWrite = false;
    MIMEType = copyFrom.MIMEType;
}

QPixmap::~QPixmap()
{
    if (imageRenderer){
		imageRenderer = NULL;
	}
}

QPixmap::operator wxBitmap() const
{
	if (m_bitmap.Ok()) 
		return m_bitmap;
	
	return wxBitmap();
}

void QPixmap::resetAnimation()
{
}

bool QPixmap::shouldUseThreadedDecoding()
{
    return false;
}

bool QPixmap::receivedData(const QByteArray &bytes, bool isComplete, khtml::CachedImageCallback *decoderCallback)
{
	return false;
}

bool QPixmap::mask() const
{
    return false;
}

bool QPixmap::isNull() const
{
    return m_bitmap.Ok();
}

QSize QPixmap::size() const
{
	if (m_bitmap.Ok())
		return QSize(m_bitmap.GetWidth(), m_bitmap.GetHeight());

	return QSize(0, 0);
}

QRect QPixmap::rect() const
{
    if (m_bitmap.Ok()) 
	    return QRect(0, 0, m_bitmap.GetWidth(), m_bitmap.GetHeight());
	
	return QRect(0, 0, 0, 0);
}

int QPixmap::width() const
{
    if (m_bitmap.Ok()) {
        return m_bitmap.GetWidth();
    }
    return 0;
}

int QPixmap::height() const
{
    if (m_bitmap.Ok()) {
        return m_bitmap.GetHeight();
    }
    return 0;
}

void QPixmap::resize(const QSize &sz)
{
    resize(sz.width(), sz.height());
}

void QPixmap::resize(int w, int h)
{
    if (m_bitmap.Ok()){
		// TODO: consider making QPixmap a wxImage depending on which would 
		// overall be more efficient
		wxImage resizer = m_bitmap.ConvertToImage();
		m_bitmap = wxBitmap(resizer.Scale(w, h));
	}	
}

QPixmap QPixmap::xForm(const QWMatrix &xmatrix) const
{
    // This function is only called when an image needs to be scaled.  
    // We can depend on render_image.cpp to call resize AFTER
    // creating a copy of the image to be scaled. So, this
    // implementation simply returns a copy of the image. Note,
    // this assumption depends on the implementation of
    // RenderImage::printObject.   
    return *this;
}

QPixmap &QPixmap::operator=(const QPixmap &assignFrom)
{
    MIMEType = assignFrom.MIMEType;
    assignFrom.needCopyOnWrite = true;
    needCopyOnWrite = true;
	m_bitmap = assignFrom.m_bitmap;
    return *this;
}

void QPixmap::increaseUseCount() const
{
}

void QPixmap::decreaseUseCount() const
{
}

void QPixmap::stopAnimations()
{
}

void QPixmap::flushRasterCache()
{
}
