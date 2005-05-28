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

// NOTE: This class is an internal class (not an interface) and thus
// it is subject to change. This should not be considered the final
// API.

#include <wx/defs.h>
#include <wx/bitmap.h>
#include <wx/dc.h>

class WebCoreImageRenderer: wxObject{

public:

	WebCoreImageRenderer();
	~WebCoreImageRenderer();

	bool incrementalLoadWithBytes(const void* bytes, unsigned length, bool isComplete, void* callback);
	wxSize getSize();
	void resize(wxSize &s);
	void drawImageInRect(wxRect &ir, wxRect &fromRect);
	void drawImageInRect(wxRect &ir, wxRect &fromRect, int compsiteOperator, wxDC* context);
	// NOTE: in wx impl, compositeOperator is probably closest to a logical function
	// see here for values Cocoa supports: 
	// http://developer.apple.com/documentation/Cocoa/Reference/ApplicationKit/ObjC_classic/Classes/NSImage.html
	// and here for the ones they expose via JavaScript (the ones we need to worry about!)
	// http://developer.apple.com/documentation/AppleApplications/Reference/SafariJSRef/Classes/Canvas.html#//apple_ref/doc/uid/30001240-54491-BAJEHAHB
	// in any case, whatever the implementation, we'll likely use an enum to determine which to use
	// hence an int param.
	
	void stopAnimation();
	void tileInRect(wxRect &r, wxPoint &p, wxDC *context);
	bool isNull();
	void flushRasterCache();
	wxBitmap* getImage();
	void resetAnimation();
}
