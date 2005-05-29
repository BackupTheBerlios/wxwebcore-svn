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

#import "KWQPushButton.h"

enum {
    topMargin,
    bottomMargin,
    leftMargin,
    rightMargin,
    baselineFudgeFactor
};

QPushButton::QPushButton(QWidget *parent)
{
    m_button = new wxButton(parent->getView(), -1);
}

QPushButton::QPushButton(const QString &text, QWidget *parent)
{
    m_button = new wxButton(parent->getView(), -1);
    setText(text);
}

QSize QPushButton::sizeHint() const 
{
	QSize size(-1, -1);
    if (m_button)
		size = m_button->GetBestSize();
    return size;
}

QRect QPushButton::frameGeometry() const
{

	// TODO: We'll have to figure out if we need special calcs like this ourselves
	// or if we can just go with the regular wx class methods. I think we'll have to
	// see the render to find out...
    QRect r = QWidget::frameGeometry();
    return QRect(r.x() + dimensions()[leftMargin], r.y() + dimensions()[topMargin],
        r.width() - (dimensions()[leftMargin] + dimensions()[rightMargin]),
        r.height() - (dimensions()[topMargin] + dimensions()[bottomMargin]));
}

void QPushButton::setFrameGeometry(const QRect &r)
{
    QWidget::setFrameGeometry(QRect(r.x() - dimensions()[leftMargin], r.y() - dimensions()[topMargin],
        r.width() + dimensions()[leftMargin] + dimensions()[rightMargin],
        r.height() + dimensions()[topMargin] + dimensions()[bottomMargin]));
}

int QPushButton::baselinePosition(int height) const
{
    // Button text is centered vertically, with a fudge factor to account for the shadow.

    return (int)ceil(-dimensions()[topMargin]
        + ((height + dimensions()[topMargin] + dimensions()[bottomMargin])) / 2.0
        - dimensions()[baselineFudgeFactor]);
}

const int *QPushButton::dimensions() const
{
    // We empirically determined these dimensions.
    // It would be better to get this info from AppKit somehow.
    static const int w[3][5] = {
        { 4, 7, 6, 6, 2 },
        { 4, 6, 5, 5, 2 },
        { 0, 1, 1, 1, 1 }
    };

    return w[0];
}
