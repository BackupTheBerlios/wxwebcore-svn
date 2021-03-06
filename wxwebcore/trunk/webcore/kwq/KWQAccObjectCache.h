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

#if 0 // FIXME
#include <CoreFoundation/CoreFoundation.h>
#include <ApplicationServices/ApplicationServicesPriv.h>
#endif

#include "visible_position.h"

#ifdef __OBJC__
@class KWQAccObject;
#else
class KWQAccObject;
#endif

class QString;

namespace khtml {
    class RenderObject;
    class VisiblePosition;
}

typedef unsigned int        KWQAccObjectID;

class KWQAccObjectCache
{
public:
    KWQAccObjectCache();
    ~KWQAccObjectCache();
    
    KWQAccObject* accObject(khtml::RenderObject* renderer);
    void setAccObject(khtml::RenderObject* renderer, KWQAccObject* obj);
    void removeAccObject(khtml::RenderObject* renderer);

    KWQAccObjectID getAccObjectID(KWQAccObject* accObject);
    void removeAccObjectID(KWQAccObject* accObject);
#if 0 // FIXME - should we define OMIT_TIGER_FEATURES instead?
#if OMIT_TIGER_FEATURES
// no parameterized attributes in Panther... they were introduced in Tiger
#else
    AXTextMarkerRef textMarkerForVisiblePosition (const khtml::VisiblePosition &);
    khtml::VisiblePosition visiblePositionForTextMarker (AXTextMarkerRef textMarker);
#endif
#endif

    void detach(khtml::RenderObject* renderer);
    
    void childrenChanged(khtml::RenderObject* renderer);

    void postNotification(khtml::RenderObject* renderer, const QString& msg);
    void postNotificationToTopWebArea(khtml::RenderObject* renderer, const QString& msg);
    void handleFocusedUIElementChanged(void);
    
    static void enableAccessibility() { gAccessibilityEnabled = true; }
    static bool accessibilityEnabled() { return gAccessibilityEnabled; }

private:
    static bool gAccessibilityEnabled;

private:
#if 0 // FIXME
    CFMutableDictionaryRef accCache;
    CFMutableDictionaryRef accCacheByID;
    KWQAccObjectID accObjectIDSource;
#endif
};
