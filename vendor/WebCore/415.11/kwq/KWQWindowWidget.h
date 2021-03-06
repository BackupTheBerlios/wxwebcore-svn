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

#ifndef KWQKWINDOW_WIDGET_H
#define KWQKWINDOW_WIDGET_H

#include "KWQWidget.h"

#ifdef __OBJC__
@class WebCoreBridge;
#else
class WebCoreBridge;
#endif

class KWQWindowWidgetPrivate;

class KWQWindowWidget : public QWidget
{
 public:
    virtual ~KWQWindowWidget();

    KWQWindowWidget(WebCoreBridge *bridge);

    virtual QSize sizeHint() const;
    virtual QRect frameGeometry() const;
    virtual void setFrameGeometry(const QRect &);

    virtual QWidget *topLevelWidget() const;
    virtual QPoint mapFromGlobal(const QPoint &) const;
    virtual QPoint viewportToGlobal(const QPoint &) const;

 private:
    KWQWindowWidgetPrivate *d;
};

#endif /* KWQKWINDOW_WIDGET_H */
