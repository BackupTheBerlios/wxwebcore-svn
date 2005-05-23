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

#include <stdarg.h>
#include <wx/log.h>

#ifdef _WIN32
    #define vsnprintf _vsnprintf
#endif

static wxString FormatStr(const char *format, va_list args)
{
    const size_t BUFSIZE = 256;
    char buf[BUFSIZE];
    vsnprintf(buf, BUFSIZE, format, args);
    buf[BUFSIZE-1] = 0; // needed on win32 (!=C99 semantics)
    return wxString::FromAscii(buf);
}

void qDebug(const char *format, ...)
{
    va_list args;
    va_start(args, format);
    wxLogDebug(FormatStr(format, args));
    va_end(args);
}

void qWarning(const char *format, ...)
{
    va_list args;
    va_start(args, format);
    wxLogWarning(FormatStr(format, args));
    va_end(args);
}
