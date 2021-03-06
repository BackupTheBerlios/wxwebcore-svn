/*
 * Copyright (C) 2005 Apple Computer, Inc.  All rights reserved.
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

#import "WebCoreScrollView.h"

@implementation WebCoreScrollView

#if !BUILDING_ON_PANTHER

- (BOOL)autoforwardsScrollWheelEvents
{
    return YES;
}

#else

- (void)scrollWheel:(NSEvent *)event
{
    NSPoint origin = [[self contentView] bounds].origin;

    // Compute a new origin as if we had scrolled a little bit.
    // If we constrain this and nothing happens, that means we're already scrolled to the limit.
    NSPoint newOrigin = origin;
    if ([event deltaX] > 0) {
        newOrigin.x -= 1;
    } else if ([event deltaX] < 0) {
        newOrigin.x += 1;
    }
    if ([event deltaY] > 0) {
        newOrigin.y -= 1;
    } else if ([event deltaY] < 0) {
        newOrigin.y += 1;
    }

    // If we are already scrolled to the limit, pass on this event, and send it on to the next responder
    if (NSEqualPoints(origin, [[self contentView] constrainScrollPoint:newOrigin])) {
        [[self nextResponder] tryToPerform:@selector(scrollWheel:) with:event];
    } else {
        [super scrollWheel:event];
    }
}

#endif

@end
