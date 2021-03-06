/*
 * Copyright (c) 2005 Kevin Ollivier
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 *
 */

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

#import "KWQDateTime.h"

static wxDateTime::Month intToMonth(int monthNum){
	switch (monthNum){
		case 1:
			return wxDateTime::Jan;
		case 2:
			return wxDateTime::Feb;
		case 3:
			return wxDateTime::Mar;
		case 4:
			return wxDateTime::Apr;
		case 5:
			return wxDateTime::May;
		case 6:
			return wxDateTime::Jun;
		case 7:
			return wxDateTime::Jul;
		case 8:
			return wxDateTime::Aug;
		case 9:
			return wxDateTime::Sep;
		case 10:
			return wxDateTime::Oct;
		case 11:
			return wxDateTime::Nov;
		case 12:
			return wxDateTime::Dec;
		default:
			return wxDateTime::Inv_Month;
	};

}

QTime::QTime(int hours, int minutes)
{
	timeInSeconds = wxDateTime();
    timeInSeconds.Set(1, wxDateTime::Jan, 2001, hours, minutes, 0, 0);
}

int QTime::msec() const
{
	return timeInSeconds.GetMillisecond();
}

int QTime::elapsed() const
{
	wxDateTime current = wxDateTime::Now();
	current.Subtract(timeInSeconds);
	// value is milliseconds!
	return (current.GetTicks() * 1000);
}

int QTime::restart()
{
	int timeElapsed = elapsed();
	timeInSeconds = wxDateTime::Now();
    return (int)(timeElapsed * 1000);
}

QDate::QDate(int y, int m, int d)
    : year(y), month(m), day(d)
{
}

QDateTime::QDateTime(const QDate &d, const QTime &t)
{
	
    dateInSeconds = wxDateTime();
	dateInSeconds.SetYear(d.year);
	dateInSeconds.SetMonth(intToMonth(d.month));
	dateInSeconds.SetDay(d.day);
	dateInSeconds.SetHour(t.timeInSeconds.GetHour());
	dateInSeconds.SetMinute(t.timeInSeconds.GetMinute());
	dateInSeconds.SetSecond(t.timeInSeconds.GetSecond());
}

int QDateTime::secsTo(const QDateTime &b) const
{
    return (int)(b.dateInSeconds.GetTicks() - dateInSeconds.GetTicks());
}

bool KWQUIEventTime::uiEventPending() const
{
    return false;
/*
    unsigned int mask = NSAnyEventMask & 
      ~(NSFlagsChangedMask | NSAppKitDefinedMask | NSSystemDefinedMask | NSApplicationDefinedMask | NSPeriodicMask | NSCursorUpdateMask);
    return [[NSApplication sharedApplication] nextEventMatchingMask:mask untilDate:nil
                                              inMode:NSEventTrackingRunLoopMode dequeue:NO] != nil;
*/
}

#ifdef _KWQ_IOSTREAM_

std::ostream &operator<<(std::ostream &o, const QDate &date)
{
    return o <<
        "QDate: [yy/mm/dd: " <<
        date.year <<
        '/' <<
        date.month <<
        '/' <<
        date.day <<
        ']';
}

std::ostream &operator<<(std::ostream &o, const QTime &time)
{
    return o <<
        "QTime: [hh:mm:ss:ms = " <<
        (int)time.timeInSeconds.GetHour() <<
        ':' <<
        (int)time.timeInSeconds.GetMinute() <<
        ':' <<
        (int)time.timeInSeconds.GetSecond() <<
        ':' <<
        time.timeInSeconds.GetMillisecond() <<
        ']';
}

std::ostream &operator<<(std::ostream &o, const QDateTime &dateTime)
{
    return o <<
        "QDateTime: [yy/mm/dd hh:mm:ss:ms = " <<
        (int)dateTime.dateInSeconds.GetYear() <<
        '/' <<
        (int)dateTime.dateInSeconds.GetMonth() <<
        '/' <<
        (int)dateTime.dateInSeconds.GetDay() <<
        ' ' << 
        (int)dateTime.dateInSeconds.GetHour() <<
        ':' <<
        (int)dateTime.dateInSeconds.GetMinute() <<
        ':' <<
        (int)dateTime.dateInSeconds.GetSecond() <<
        ':' <<
        ((int)dateTime.dateInSeconds.GetMillisecond() <<
        ']';
}

#endif // _KWQ_IOSTREAM_
