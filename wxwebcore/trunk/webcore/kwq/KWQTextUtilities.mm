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

#import "KWQTextUtilities.h"

#import "KWQString.h"
#import <unicode/ubrk.h>
#import <unicode/ustring.h>
#import <unicode/utypes.h>

// This code was swiped from the CarbonCore UnicodeUtilities.  One change from that is to use the empty
// string instead of the "old locale model" as the ultimate fallback.  This change is per the UnicodeUtilities
// engineer.
// NOTE: this abviously could be fairly expensive to do.  If it turns out to be a bottleneck, it might
// help to instead put a call in the iteratory initializer to set the current text break locale.  Unfortunately,
// we can not cache it across calls to our API since the result can change without our knowing (AFAIK
// there are no notifiers for AppleTextBreakLocale and/or AppleLanguages changes).
static char * currentTextBreakLocaleID(void)
{
#define localeStringLength 32
    static char     localeStringBuffer[localeStringLength];
    char *          localeString = &localeStringBuffer[0];
    
	//TODO: Implement this using wx!
	
    // empty string means "root locale", which what we use if we can't use a pref
    *localeString = 0;
	
    return localeString;
}

void KWQFindWordBoundary(const QChar *chars, int len, int position, int *start, int *end)
{
    int  startPos = 0;
    int  endPos = 0;

    UErrorCode status = U_ZERO_ERROR;
    UBreakIterator *boundary = ubrk_open(UBRK_WORD, currentTextBreakLocaleID(), const_cast<UChar *>(reinterpret_cast<const UChar *>(chars)), len, &status);
    if ( boundary && U_SUCCESS(status) ) {
        startPos = ubrk_preceding(boundary, position);
        if (startPos == UBRK_DONE) {
            startPos = 0;
        } 
        endPos = ubrk_following(boundary, startPos);
        if (endPos == UBRK_DONE)
            endPos = len;

        ubrk_close(boundary);
    }
    
    *start = startPos;
    *end = endPos;
}

int KWQFindNextWordFromIndex(const QChar *chars, int len, int position, bool forward)
{   
    int pos = 0;
    
    UErrorCode status = U_ZERO_ERROR;
    UBreakIterator *boundary = ubrk_open(UBRK_WORD, currentTextBreakLocaleID(), const_cast<UChar *>(reinterpret_cast<const UChar *>(chars)), len, &status);
    if ( boundary && U_SUCCESS(status) ) {
        if (forward) {
            pos = ubrk_following(boundary, position);
            if (pos == UBRK_DONE)
                pos = len;
        } else {
            pos = ubrk_preceding(boundary, position);
            if (pos == UBRK_DONE)
                pos = 0;
        }
        ubrk_close(boundary);
	}
	
	return pos;
}

void KWQFindSentenceBoundary(const QChar *chars, int len, int position, int *start, int *end)
{
    int  startPos = 0;
    int  endPos = 0;

    UErrorCode status = U_ZERO_ERROR;
    UBreakIterator *boundary = ubrk_open(UBRK_SENTENCE, currentTextBreakLocaleID(), const_cast<UChar *>(reinterpret_cast<const UChar *>(chars)), len, &status);
    if ( boundary && U_SUCCESS(status) ) {
        startPos = ubrk_preceding(boundary, position);
        if (startPos == UBRK_DONE) {
            startPos = 0;
        } 
        endPos = ubrk_following(boundary, startPos);
        if (endPos == UBRK_DONE)
            endPos = len;

        ubrk_close(boundary);
    }
    
    *start = startPos;
    *end = endPos;
}

int KWQFindNextSentenceFromIndex(const QChar *chars, int len, int position, bool forward)
{
    int pos = 0;
    
    UErrorCode status = U_ZERO_ERROR;
    UBreakIterator *boundary = ubrk_open(UBRK_SENTENCE, currentTextBreakLocaleID(), const_cast<UChar *>(reinterpret_cast<const UChar *>(chars)), len, &status);
    if ( boundary && U_SUCCESS(status) ) {
        if (forward) {
            pos = ubrk_following(boundary, position);
            if (pos == UBRK_DONE)
                pos = len;
        } else {
            pos = ubrk_preceding(boundary, position);
            if (pos == UBRK_DONE)
                pos = 0;
        }
        ubrk_close(boundary);
    }
        
    return pos;
}
