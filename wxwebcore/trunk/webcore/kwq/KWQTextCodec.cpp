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

#include <wx/strconv.h>
#include <wx/intl.h>

#include <map>
#include <string>

#include <unicode/ucnv.h>
#include <unicode/ustring.h>

#include "KWQTextCodec.h"

// ---------------------------------------------------------------------------
// UTF-16 <-> UTF-32 conversion for ICU
// ---------------------------------------------------------------------------

// FIXME: this will eventually be needed by QString code as well, move it to
//        some header

template <typename T> struct CharBuffer
{
    CharBuffer() : data(NULL), size(0) {}
    CharBuffer(const T *d, size_t s) : data(d), size(s) {}
    CharBuffer(const CharBuffer& buf) : data(buf.data), size(buf.size)
    {
        const_cast<CharBuffer*>(&buf)->data = NULL;
        const_cast<CharBuffer*>(&buf)->size = 0;
    }

    ~CharBuffer() { if (data) delete[] data; }

    const T *data;
    size_t   size;
};

CharBuffer<UChar> UTF32_to_UTF16(const UChar32 *str, size_t size)
{
    UErrorCode err;

    int32_t buflen;
    // get needed buffer size:
    u_strFromUTF32(NULL, 0, &buflen, str, size, &err);
    if ( !U_SUCCESS(err) )
        return CharBuffer<UChar>();

    UChar *buf = new UChar[buflen+1];
    u_strFromUTF32(buf, buflen+1, NULL, str, size, &err);
    if ( !U_SUCCESS(err) )
        return CharBuffer<UChar>();

    return CharBuffer<UChar>(buf, buflen);
}

CharBuffer<UChar32> UTF16_to_UTF32(const UChar *str, size_t size)
{
    UErrorCode err;

    int32_t buflen;
    // get needed buffer size:
    u_strToUTF32(NULL, 0, &buflen, str, size, &err);
    if ( !U_SUCCESS(err) )
        return CharBuffer<UChar32>();

    UChar32 *buf = new UChar32[buflen+1];
    u_strToUTF32(buf, buflen+1, NULL, str, size, &err);
    if ( !U_SUCCESS(err) )
        return CharBuffer<UChar32>();

    return CharBuffer<UChar32>(buf, buflen);
}

// ---------------------------------------------------------------------------
// QTextConverter - real implementation
// ---------------------------------------------------------------------------

class QTextConverter
{
public:
    ~QTextConverter();

    static QTextConverter *make(const char *charset);

    QCString fromUnicode(const QString& str);
    QString toUnicode(const char *str, int len, bool flush);

private:
    QTextConverter(UConverter *c) : m_conv(c) {}

    UConverter *m_conv;
};

QTextConverter *QTextConverter::make(const char *charset)
{
    UConverter *c = ucnv_open(charset, NULL);
    if ( c )
        return new QTextConverter(c);
    else
        return NULL;
}

QTextConverter::~QTextConverter()
{
    if ( m_conv )
        ucnv_close(m_conv);
}

QCString QTextConverter::fromUnicode(const QString& str)
{
    QCString output;

    const size_t BUFLEN = 1024;
    char buf[BUFLEN];
    char *target;

    CharBuffer<UChar> input(
        UTF32_to_UTF16((const UniChar*)str.unicode(), str.length()));

    if ( !input.data )
        return QCString();

    const UChar *source = input.data;
    const UChar *sourceLimit = source + input.size;

    while ( source != sourceLimit )
    {
        UErrorCode err;
        target = buf;
        ucnv_fromUnicode(m_conv,
                         &target,
                         buf + BUFLEN,
                         &source,
                         sourceLimit,
                         NULL,
                         true /*flush*/,
                         &err);

        if ( U_FAILURE(err) && err != U_BUFFER_OVERFLOW_ERROR )
        {
            // error converting, return what we got so far (FIXME?)
            ucnv_resetFromUnicode(m_conv);
            return output;
        }

        output += QCString(buf, target - buf);
    }

    return output;
}

QString QTextConverter::toUnicode(const char *str, int len, bool flush)
{
    QString output;

    const size_t BUFLEN = 1024;
    UChar buf[BUFLEN];
    UChar *target;

    const char *source = str;
    const char *sourceLimit = source + len;

    while ( source != sourceLimit )
    {
        UErrorCode err;
        target = buf;
        ucnv_toUnicode(m_conv,
                       &target,
                       buf + BUFLEN,
                       &source,
                       sourceLimit,
                       NULL,
                       flush,
                       &err);

        if ( U_FAILURE(err) && err != U_BUFFER_OVERFLOW_ERROR )
        {
            // error converting, return what we got so far (FIXME?)
            ucnv_resetToUnicode(m_conv);
            return output;
        }

        CharBuffer<UniChar> chunk(UTF16_to_UTF32(buf, target - buf));
        output += QString((const QChar*)chunk.data, chunk.size);
    }

    return output;
}

// ---------------------------------------------------------------------------
// QTextCodec
// ---------------------------------------------------------------------------

namespace
{

struct CodecsCache
{
    typedef std::map<std::string, QTextCodec*> CodecsMap;
    CodecsMap codecs;

    ~CodecsCache()
    {
        for ( CodecsMap::iterator i = codecs.begin(); i != codecs.end(); ++i )
        {
            delete i->second;
        }
        codecs.clear();
    }
};

CodecsCache gs_codecsCache;

} // anon namespace

QTextCodec::QTextCodec(QTextConverter *conv, const char *charset)
    : m_name(charset), m_conv(conv)
{
    CFStringEncoding enc =
        KWQCFStringEncodingFromIANACharsetName(charset, &m_flags);

    // From ICU documentation:
    //
    // For example, in SJIS, the backslash character in the ASCII portion is
    // also used to represent the yen currency sign. When mapping from Unicode
    // character 0x005C, it's unclear whether to map the character back to yen
    // or backslash in SJIS. This function will take the input buffer and
    // replace all the yen sign characters with backslash. This is necessary
    // when the user tries to open a file with the input buffer on Windows.
    // This function will test the converter to see whether such mapping is
    // required. You can sometimes avoid using this function by using the
    // correct version of Shift-JIS.
    if ( enc == kCFStringEncodingShiftJIS_X0213_00 ||
         enc == kCFStringEncodingEUC_JP )
    {
        m_backslashAsCurrencySymbol = 0x00A5; // yen sign
    }
    else
    {
        m_backslashAsCurrencySymbol = '\\';
    }
}

QTextCodec::~QTextCodec()
{
    delete m_conv;
}

/*static*/
QTextCodec *QTextCodec::codecForName(const char *charset)
{
    std::string key(charset);

    if ( gs_codecsCache.codecs.find(key) != gs_codecsCache.codecs.end() )
    {
        return gs_codecsCache.codecs[key];
    }
    else
    {
        QTextConverter *conv = QTextConverter::make(charset);
        if ( !conv )
        {
            gs_codecsCache.codecs[key] = NULL;
            return NULL;
        }

        QTextCodec *c = new QTextCodec(conv, charset);
        gs_codecsCache.codecs[key] = c;
        return c;
    }
}

/*static*/
QTextCodec *QTextCodec::codecForNameEightBitOnly(const char *charset)
{
    // FIXME: Apple's version returns UTF-8 codec for "Unicode" encodings,
    //        which are all possible variables of UCS-2/UTF-16.
    //        We don't understand what is it supposed to do, so we happily
    //        ignore it... for now.
    //
    //        If it's needed, use UTF-8 iff kCFStringEncodingUnicode ==
    //        KWQCFStringEncodingFromIANACharsetName(charset)
    return codecForName(charset);
}

/*static*/
QTextCodec *QTextCodec::codecForLocale()
{
    return codecForName(wxLocale::GetSystemEncodingName().ToAscii());
}

QTextDecoder *QTextCodec::makeDecoder() const
{
    QTextConverter *conv = QTextConverter::make(m_name);
    if ( conv )
        return new QTextDecoder(conv);
    else
        return NULL;
}

QCString QTextCodec::fromUnicode(const QString& str) const
{
    QChar backslash = backslashAsCurrencySymbol();
    if ( backslash != '\\' )
    {
        QString str2(str);
        str2.replace(QChar('\\'), backslash);
        return m_conv->fromUnicode(str2);
    }
    else
    {
        return m_conv->fromUnicode(str);
    }
}

QString QTextCodec::toUnicode(const char *str, int len) const
{
    return m_conv->toUnicode(str, len, true /*flush state*/);
}

// ---------------------------------------------------------------------------
// QTextDecoder
// ---------------------------------------------------------------------------

QTextDecoder::~QTextDecoder()
{
    delete m_conv;
}

QString QTextDecoder::toUnicode(const char *text, int len, bool flush)
{
    return m_conv->toUnicode(text, len, flush);
}
