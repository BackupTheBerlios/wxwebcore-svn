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

#import "KWQTimer.h"

#import "KWQAssertions.h"

class wxSingleShotTimer: public wxEvtHandler {
	public:
		wxSingleShotTimer(int msec, QObject *receiver, const char *member);
		void fire(wxTimerEvent &event);
	private:
		wxTimer *m_timer;
		KWQSlot *m_callbackSlot;
};

QTimer::QTimer()
    : m_timer(nil), m_monitorFunction(0), m_timeoutSignal(this, SIGNAL(timeout()))
{
	m_timer = new wxTimer();
}

bool QTimer::isActive() const
{
    return m_timer->IsRunning();
}

void QTimer::start(int msec, bool singleShot)
{
    stop();
	m_timer->Start(msec, singleShot);
	
	if (m_monitorFunction) {
        m_monitorFunction(m_monitorFunctionContext);
    }
}

void QTimer::stop()
{
    if (m_timer == nil) {
        return;
    }
    m_timer->Stop();
	
	if (m_monitorFunction) {
        m_monitorFunction(m_monitorFunctionContext);
    }

}

void QTimer::setMonitor(void (*monitorFunction)(void *context), void *context)
{
    ASSERT(!m_monitorFunction);
    m_monitorFunction = monitorFunction;
    m_monitorFunctionContext = context;
}

void QTimer::singleShot(int msec, QObject *receiver, const char *member)
{
	wxSingleShotTimer *timer = new wxSingleShotTimer(msec, receiver, member);
}

wxSingleShotTimer::wxSingleShotTimer(int msec, QObject *receiver, const char *member){
	wxEvtHandler::wxEvtHandler();
	wxTimer *m_timer = new wxTimer();
    m_timer->SetOwner(this);
	m_callbackSlot = new KWQSlot(receiver, member);
	m_timer->Connect(wxEVT_TIMER, wxTimerEventHandler(wxSingleShotTimer::fire));
	m_timer->Start(msec, true);
}

void wxSingleShotTimer::fire(wxTimerEvent &event)
{	
    m_callbackSlot->call();
	
	if (m_callbackSlot != NULL)
		delete m_callbackSlot;
		
	if (m_timer != NULL)
		delete m_timer;
	
	delete this;
}
