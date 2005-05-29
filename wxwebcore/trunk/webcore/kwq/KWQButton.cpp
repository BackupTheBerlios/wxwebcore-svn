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

#import "KWQButton.h"

#import "KWQAssertions.h"
#import "KWQCheckBox.h"
#import "KWQKHTMLPart.h"
#import "WebCoreBridge.h"

#import "render_form.h"

QButton::QButton()
    : m_clicked(this, SIGNAL(clicked()))
{
	m_button = new wxButton(NULL, -1);
}

QButton::~QButton()
{
    if (m_button)
		m_button->Destroy();
	
}

void QButton::setText(const QString &s)
{
    if (m_button)
		m_button->SetLabel(s));
}

QString QButton::text() const
{
    QString result;
	if (m_button)
		result = QString(m_button->GetLabel());

    return result;
}

void QButton::clicked()
{
    if (m_button) {
        m_clicked.call();
    }

}

void QButton::click(bool sendMouseEvents)
{
	// NOTE: hopefully this is all that is needed...
	if (m_button)
		clicked();
}

void QButton::setFont(const QFont &f)
{
	if (m_button)
		m_button->SetFont(f);
}

QWidget::FocusPolicy QButton::focusPolicy() const
{

    WebCoreBridge *bridge = KWQKHTMLPart::bridgeForWidget(this);
    if (!bridge || !bridge->getPart() || !bridge->getPart()->tabsToAllControls()) {
        return NoFocus;
    }

    return QWidget::focusPolicy();
}

void QButton::setWritingDirection(QPainter::TextDirection direction)
{
	//TODO: How should we handle this? 
}
