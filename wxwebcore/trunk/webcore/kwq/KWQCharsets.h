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

#ifndef KWQCHARSETS_H_
#define KWQCHARSETS_H_

enum KWQEncodingFlags {
    NoEncodingFlags = 0,
    VisualOrdering = 1,
    BigEndian = 2,
    LittleEndian = 4,
    IsJapanese = 8
};

// subset of CFStringEncoding for our internal use:
enum CFStringEncoding
{
    kCFStringEncodingASCII,
    kCFStringEncodingBig5_DOSVariant,
    kCFStringEncodingBig5_HKSCS_1999,
    kCFStringEncodingDOSArabic,
    kCFStringEncodingDOSBalticRim,
    kCFStringEncodingDOSChineseTrad,
    kCFStringEncodingDOSGreek,
    kCFStringEncodingDOSGreek2,
    kCFStringEncodingDOSIcelandic,
    kCFStringEncodingDOSJapanese,
    kCFStringEncodingDOSLatin1,
    kCFStringEncodingDOSLatin2,
    kCFStringEncodingDOSLatinUS,
    kCFStringEncodingDOSRussian,
    kCFStringEncodingDOSThai,
    kCFStringEncodingDOSTurkish,
    kCFStringEncodingEBCDIC_CP037,
    kCFStringEncodingEUC_CN_DOSVariant,
    kCFStringEncodingEUC_JP,
    kCFStringEncodingEUC_KR_DOSVariant,
    kCFStringEncodingEUC_TW,
    kCFStringEncodingGB_18030_2000,
    kCFStringEncodingHZ_GB_2312,
    kCFStringEncodingInvalidId,
    kCFStringEncodingISO_2022_CN,
    kCFStringEncodingISO_2022_CN_EXT,
    kCFStringEncodingISO_2022_JP,
    kCFStringEncodingISO_2022_JP_1,
    kCFStringEncodingISO_2022_JP_2,
    kCFStringEncodingISO_2022_JP_3,
    kCFStringEncodingISO_2022_KR,
    kCFStringEncodingISOLatin1,
    kCFStringEncodingISOLatin10,
    kCFStringEncodingISOLatin2,
    kCFStringEncodingISOLatin3,
    kCFStringEncodingISOLatin4,
    kCFStringEncodingISOLatin5,
    kCFStringEncodingISOLatin6,
    kCFStringEncodingISOLatin7,
    kCFStringEncodingISOLatin8,
    kCFStringEncodingISOLatin9,
    kCFStringEncodingISOLatinArabic,
    kCFStringEncodingISOLatinCyrillic,
    kCFStringEncodingISOLatinGreek,
    kCFStringEncodingISOLatinHebrew,
    kCFStringEncodingISOLatinThai,
    kCFStringEncodingJIS_C6226_78,
    kCFStringEncodingJIS_X0201_76,
    kCFStringEncodingJIS_X0208_83,
    kCFStringEncodingJIS_X0208_90,
    kCFStringEncodingJIS_X0212_90,
    kCFStringEncodingKOI8_R,
    kCFStringEncodingKOI8_U,
    kCFStringEncodingMacArabic,
    kCFStringEncodingMacCentralEurRoman,
    kCFStringEncodingMacChineseSimp,
    kCFStringEncodingMacChineseTrad,
    kCFStringEncodingMacCroatian,
    kCFStringEncodingMacCyrillic,
    kCFStringEncodingMacDevanagari,
    kCFStringEncodingMacDingbats,
    kCFStringEncodingMacFarsi,
    kCFStringEncodingMacGreek,
    kCFStringEncodingMacGujarati,
    kCFStringEncodingMacGurmukhi,
    kCFStringEncodingMacHebrew,
    kCFStringEncodingMacIcelandic,
    kCFStringEncodingMacJapanese,
    kCFStringEncodingMacKorean,
    kCFStringEncodingMacRoman,
    kCFStringEncodingMacRomanian,
    kCFStringEncodingMacRomanLatin1,
    kCFStringEncodingMacSymbol,
    kCFStringEncodingMacThai,
    kCFStringEncodingMacTibetan,
    kCFStringEncodingMacTurkish,
    kCFStringEncodingMacVT100,
    kCFStringEncodingNextStepLatin,
    kCFStringEncodingShiftJIS_DOSVariant,
    kCFStringEncodingShiftJIS_X0213_00,
    kCFStringEncodingUnicode,
    kCFStringEncodingUTF8,
    kCFStringEncodingWindowsArabic,
    kCFStringEncodingWindowsBalticRim,
    kCFStringEncodingWindowsCyrillic,
    kCFStringEncodingWindowsGreek,
    kCFStringEncodingWindowsHebrew,
    kCFStringEncodingWindowsKoreanJohab,
    kCFStringEncodingWindowsLatin1,
    kCFStringEncodingWindowsLatin2,
    kCFStringEncodingWindowsLatin5,
    kCFStringEncodingWindowsVietnamese
};

CFStringEncoding
KWQCFStringEncodingFromIANACharsetName(const char *,
                                       KWQEncodingFlags *flags = 0);

#endif /* KWQCHARSETS_H_ */
