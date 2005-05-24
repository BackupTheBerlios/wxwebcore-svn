/*
 * Copyright (c) 2005 Vaclav Slavik
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

#include "KWQStringList.h"

#include <wx/tokenzr.h>

QStringList QStringList::split(const QString& separator, const QString& s,
                               bool allowEmptyEntries)
{
    // KHTML only uses this form with single tokenizer character, so we
    // can safely make our life easier like this
    if ( separator.length() == 1 )
    {
        return split(separator[0], s, allowEmptyEntries);
    }
    else
    {
        wxFAIL_MSG( _T("tokenizing by string separator not implemented") );
        return QStringList();
    }
}

QStringList QStringList::split(const QChar& separator, const QString& s,
                               bool allowEmptyEntries)
{
    // again, KHTML doesn't use non-ASCII separators and while they're
    // supported in Unicode build of wxWidgets, they'd cause problems in
    // ANSI build
    wxASSERT_MSG( separator.unicode() <= 0x7F,
                  _T("only ASCII separators implemented") );
    wxString sep = wxString::FromAscii((char)separator);

    wxCOMPILE_TIME_ASSERT( sizeof(UniChar) == sizeof(wchar_t),
                           UniCharHasDifferentSizeThanWchar_t );

    // conversion to UTF-8 is done in ANSI build only -- given the above,
    // tokens will be valid UTF-8 substrings that we can convert back to
    // Unicode QString
    wxString input((const wchar_t*)s.unicode(), wxConvUTF8, s.length());

    wxStringTokenizer tkn(input, sep,
                          allowEmptyEntries ?
                          wxTOKEN_RET_EMPTY_ALL : wxTOKEN_STRTOK);

    QStringList result;
    while ( tkn.HasMoreTokens() )
    {
        wxString t = tkn.GetNextToken();
#if wxUSE_UNICODE
        result.append(QString((const QChar*)t.c_str(), t.length()));
#else
        result.append(QString::fromUtf8(t.c_str(), t.length()));
#endif
    }

    return result;
}

QString QStringList::join(const QString &separator) const
{
    QString result;
    
    for (ConstIterator i = begin(), j = ++begin(); i != end(); ++i, ++j) {
        result += *i;
	if (j != end()) {
	    result += separator;
	}
    }

    return result;
}

QString QStringList::pop_front()
{
    QString front = first();
    remove(begin());
    return front;
}
