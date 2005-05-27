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

#import "KWQKCursor.h"

void KCursor::setAutoHideCursor(QWidget *w, bool enable) {}

QCursor KCursor::arrowCursor() { return QCursor(); }
QCursor KCursor::crossCursor() { return QCursor(wxCursor(wxCROSS_CURSOR)); }
QCursor KCursor::handCursor() { return QCursor(); }
QCursor KCursor::sizeAllCursor() { return QCursor(); }
QCursor KCursor::sizeHorCursor() { return QCursor(); }
QCursor KCursor::sizeVerCursor() { return QCursor(); }
QCursor KCursor::sizeBDiagCursor() { return QCursor(); }
QCursor KCursor::sizeFDiagCursor() { return QCursor(); }
QCursor KCursor::ibeamCursor() { return QCursor(); }
QCursor KCursor::waitCursor() { return QCursor(wxCursor(wxHOURGLASS_CURSOR)); }
QCursor KCursor::whatsThisCursor() { return QCursor(); }

QCursor KCursor::eastResizeCursor() { return QCursor(); }
QCursor KCursor::northResizeCursor() { return QCursor(); }
QCursor KCursor::northEastResizeCursor() { return QCursor(); }
QCursor KCursor::northWestResizeCursor() { return QCursor(); }
QCursor KCursor::southResizeCursor() { return QCursor(); }
QCursor KCursor::southEastResizeCursor() { return QCursor(); }
QCursor KCursor::southWestResizeCursor() { return QCursor(); }
QCursor KCursor::westResizeCursor() { return QCursor(); }
