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

// NOTE: This class is an internal class (not an interface) and thus
// it is subject to change. This should not be considered the final
// API.

#include <wx/defs.h>

#ifndef ROUND_TO_INT
#define ROUND_TO_INT(x) (unsigned int)((x)+.5)
#endif

struct WebCoreTextStyle
{
    wxColour *textColor;
    wxColour *backgroundColor;
    int letterSpacing;
    int wordSpacing;
    int padding;
    wxString **families;
    unsigned smallCaps : 1;
    unsigned rtl : 1;
    unsigned visuallyOrdered : 1;
    unsigned applyRunRounding : 1;
    unsigned applyWordRounding : 1;
    unsigned attemptFontSubstitution : 1;
};

struct WebCoreTextRun
{
    const UniChar *characters;
    unsigned int length;
    int from;
    int to;
};

struct WebCoreTextGeometry
{
    wxPoint point;
    float selectionY;
    float selectionHeight;
    bool useFontMetricsForSelectionYAndHeight : 1;
};

#ifdef __cplusplus
extern "C" {
#endif

typedef struct WebCoreTextRun WebCoreTextRun;
typedef struct WebCoreTextStyle WebCoreTextStyle;
typedef struct WebCoreTextGeometry WebCoreTextGeometry;

extern void WebCoreInitializeTextRun(WebCoreTextRun *run, const UniChar *characters, unsigned int length, int from, int to);
extern void WebCoreInitializeEmptyTextStyle(WebCoreTextStyle *style);
extern void WebCoreInitializeEmptyTextGeometry(WebCoreTextGeometry *geometry);

#ifdef __cplusplus
}
#endif

class WebCoreTextRenderer: wxObject {
public:

	WebCoreTextRenderer(); 
	~WebCoreTextRenderer();
	
	int getAscent();
	int getDescent();
	int getLineSpacing();
	float getXHeight();

// horizontal metrics
	float floatWidthForRun(const WebCoreTextRun *run, const WebCoreTextStyle *style, float *buffer);

// drawing
	void drawRun(const WebCoreTextRun *run, const WebCoreTextStyle *style, const WebCoreTextGeometry *geometry);
	void drawHighlightForRun(const WebCoreTextRun *run, const WebCoreTextStyle *style, const WebCoreTextGeometry *geometry);
	void drawLineForCharacters(wxPoint point, float yOffset, int width, wxColour *color, float thickness);
	void drawLineForMisspelling(wxPoint point, (int)width);
	int getMisspellingLineThickness();

// selection point check
	int pointToOffset(const WebCoreTextRun *run, const WebCoreTextStyle *style, int x, bool reversed, bool includePartialGlyphs);
}
