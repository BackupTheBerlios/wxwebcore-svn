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

#import "KWQFont.h"

QFont::QFont()
    : _isPrinterFont(false)
    , m_font()
{
}

QFont::~QFont()
{
}

QFont::QFont(const QFont &other)
    : _isPrinterFont(other._isPrinterFont)
    , m_font(other)
{
}

QFont &QFont::operator=(const QFont &other)
{
    _isPrinterFont = other._isPrinterFont;
    m_font = other;
    return *this;
}

QString QFont::family() const
{
    return QString(m_font.GetFaceName());
}

void QFont::setFamily(const QString &qfamilyName)
{
	// NOTE: QFont's family is more like wx's face name than
	// a special font family. Qt may have those too, but if so,
	// they are determined by heuristics, and we don't have to 
	// worry about that for now anyways.
	
    m_font.SetFaceName(qfamilyName);
}

void QFont::setFirstFamily(const KWQFontFamily& family) 
{
    _family = family;
}

void QFont::setPixelSize(float s)
{
    m_font.SetPointSize((int)s);
}

void QFont::setWeight(int weight)
{
    if (weight == Bold) {
        m_font.SetWeight(wxFONTWEIGHT_BOLD);
    } else if (weight == Normal) {
        m_font.SetWeight(wxFONTWEIGHT_NORMAL);
    }
}

void QFont::setPrinterFont(bool isPrinterFont)
{
    _isPrinterFont = isPrinterFont;
}

int QFont::weight() const
{
    return bold() ? Bold : Normal;
}

void QFont::setItalic(bool flag)
{
    if (flag) {
        m_font.SetStyle(wxFONTSTYLE_ITALIC);
    } else {
        m_font.SetStyle(wxFONTSTYLE_NORMAL);
    }
}

bool QFont::italic() const
{
    return (m_font.GetStyle() == wxFONTSTYLE_ITALIC);
}

bool QFont::bold() const
{
    return (m_font.GetWeight() == wxFONTWEIGHT_BOLD);
}

bool QFont::isFixedPitch() const
{
    return m_font.IsFixedWidth();
}


bool QFont::operator==(const QFont &compareFont) const
{
    return m_font == compareFont
        && _isPrinterFont == compareFont._isPrinterFont;
}

QFont::operator wxFont() const
{
    return m_font;
}
