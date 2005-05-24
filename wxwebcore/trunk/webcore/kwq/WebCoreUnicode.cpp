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

#include "WebCoreUnicode.h"
#include <unicode/uchar.h>
#include <wx/debug.h>

int WebCoreUnicodeDigitValueFunction(UChar32 c)
{
    return u_charDigitValue(c);
}

WebCoreUnicodeDirection WebCoreUnicodeDirectionFunction(UChar32 c)
{
    // NB: UCharDirection and WebCoreUnicodeDirection values are identical,
    //     but doing a case is less error-prone
    switch ( u_charDirection(c) )
    {
        case U_LEFT_TO_RIGHT:
            return DirectionL;
        case U_RIGHT_TO_LEFT:
            return DirectionR;
        case U_EUROPEAN_NUMBER:
            return DirectionEN;
        case U_EUROPEAN_NUMBER_SEPARATOR:
            return DirectionES;
        case U_EUROPEAN_NUMBER_TERMINATOR:
            return DirectionET;
        case U_ARABIC_NUMBER:
            return DirectionAN;
        case U_COMMON_NUMBER_SEPARATOR:
            return DirectionCS;
        case U_BLOCK_SEPARATOR:
            return DirectionB;
        case U_SEGMENT_SEPARATOR:
            return DirectionS;
        case U_WHITE_SPACE_NEUTRAL:
            return DirectionWS;
        case U_OTHER_NEUTRAL:
            return DirectionON;
        case U_LEFT_TO_RIGHT_EMBEDDING:
            return DirectionLRE;
        case U_LEFT_TO_RIGHT_OVERRIDE:
            return DirectionLRO;
        case U_RIGHT_TO_LEFT_ARABIC:
            return DirectionAL;
        case U_RIGHT_TO_LEFT_EMBEDDING:
            return DirectionRLE;
        case U_RIGHT_TO_LEFT_OVERRIDE:
            return DirectionRLO;
        case U_POP_DIRECTIONAL_FORMAT:
            return DirectionPDF;
        case U_DIR_NON_SPACING_MARK:
            return DirectionNSM;
        case U_BOUNDARY_NEUTRAL:
            return DirectionBN;
        case U_CHAR_DIRECTION_COUNT:
            wxFAIL_MSG(_T("invalid character direction"));
    };

    return DirectionL /*arbitrary*/;
}

bool WebCoreUnicodeMirroredFunction(UChar32 c)
{
    return u_isMirrored(c);
}

UChar32 WebCoreUnicodeMirroredCharFunction(UChar32 c)
{
    return u_charMirror(c);
}

UChar32 WebCoreUnicodeLowerFunction(UChar32 c)
{
    return u_tolower(c);
}

UChar32 WebCoreUnicodeUpperFunction(UChar32 c)
{
    return u_toupper(c);
}
