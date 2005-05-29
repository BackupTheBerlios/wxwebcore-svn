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

#include <unicode/utf.h>
#include <unicode/uchar.h>

typedef UChar32 UniChar;

    typedef enum
    {
        DirectionL   = U_LEFT_TO_RIGHT,
        DirectionR   = U_RIGHT_TO_LEFT,
        DirectionEN  = U_EUROPEAN_NUMBER,
        DirectionES  = U_EUROPEAN_NUMBER_SEPARATOR,
        DirectionET  = U_EUROPEAN_NUMBER_TERMINATOR,
        DirectionAN  = U_ARABIC_NUMBER,
        DirectionCS  = U_COMMON_NUMBER_SEPARATOR,
        DirectionB   = U_BLOCK_SEPARATOR,
        DirectionS   = U_SEGMENT_SEPARATOR,
        DirectionWS  = U_WHITE_SPACE_NEUTRAL,
        DirectionON  = U_OTHER_NEUTRAL,
        DirectionLRE = U_LEFT_TO_RIGHT_EMBEDDING,
        DirectionLRO = U_LEFT_TO_RIGHT_OVERRIDE,
        DirectionAL  = U_RIGHT_TO_LEFT_ARABIC,
        DirectionRLE = U_RIGHT_TO_LEFT_EMBEDDING,
        DirectionRLO = U_RIGHT_TO_LEFT_OVERRIDE,
        DirectionPDF = U_POP_DIRECTIONAL_FORMAT,
        DirectionNSM = U_DIR_NON_SPACING_MARK,
        DirectionBN  = U_BOUNDARY_NEUTRAL
    } WebCoreUnicodeDirection;


    int WebCoreUnicodeDigitValueFunction(UChar32 c);
    WebCoreUnicodeDirection WebCoreUnicodeDirectionFunction(UChar32 c);
    bool WebCoreUnicodeMirroredFunction(UChar32 c);
    UChar32 WebCoreUnicodeMirroredCharFunction(UChar32 c);
    UChar32 WebCoreUnicodeLowerFunction(UChar32 c);
    UChar32 WebCoreUnicodeUpperFunction(UChar32 c);
