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
#include <wx/url.h>

// KO: these are interfaces. see ObjC @protocol reference or WebCoreBridge.h for more info on why
// I did things this way

class WebCoreResourceLoader: public wxObject {

public:

	WebCoreResourceLoader();
	~WebCoreResourceLoader();
	virtual void receivedResponse(void* response); //just for now, so things compile
	virtual void redirectedToURL(wxURL* url);

	virtual void addData(void* data);

// Either finishWithData:, reportError, or cancel must be called before the
// loader is released, but never more than one.
	virtual void finishWithData(void* data);
	virtual void reportError();
	virtual void cancel();
}

class WebCoreResourceHandle: public wxObject {

public:

	WebCoreResourceHandle();
	~WebCoreResourceHandle();
	
	// yup, this was the only function this class had...
	virtual void cancel();
}
