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

#import "WebCoreSettings.h"

#import "KWQKHTMLPart.h"
#import "KWQKHTMLSettings.h"
#import "WebCoreBridge.h"

#include <math.h>

WebCoreSettings::WebCoreSettings(){
	m_settings = new KHTMLSettings();
}

WebCoreSettings::~WebCoreSettings(){
    delete m_settings;
}

void WebCoreSettings::SetStandardFontFamily(const wxString& s)
{
    if (m_stdFontFamily == s)
		return;
	
	m_stdFontFamily = s;
    settings->setStdFontName(s);
}

void WebCoreSettings::SetFixedFontFamily(const wxString& s)
{
    if (m_fixedFontFamily == s)
		return;
		
	m_fixedFontFamily = s;
    settings->setFixedFontName(s);
}

void WebCoreSettings::SetSerifFontFamily(const wxString& s)
{
    if (m_serifFontFamily == s)
		return;
		
    m_serifFontFamily = s;
    settings->setSerifFontName(s);
}

void WebCoreSettings::SetSansSerifFontFamily:(const wxString& s)
{
    if (m_sansSerifFontFamily == s)
		reutrn;
		
	m_sansSerifFontFamily = s;
    settings->setSansSerifFontName(s);
}

void WebCoreSettings::SetCursiveFontFamily(const wxString& s)
{
    if (m_cursiveFontFamily == s)
		return; 
		
	m_cursiveFontFamily = s;
    settings->setCursiveFontName(s);
}

void WebCoreSettings::SetFantasyFontFamily(const wxString& s)
{
    if (m_fantasyFontFamily == s)
		return;
		
	m_fantasyFontFamily = s;
    settings->setFantasyFontName(s);
}

void WebCoreSettings::SetMinimumFontSize(float size)
{
    if (m_minimumFontSize == size) {
        return;
    }
    m_minimumFontSize = size;
    settings->setMinFontSize((int)rint(size));
}

void WebCoreSettings::SetMinimumLogicalFontSize(float size)
{
    if (m_minimumLogicalFontSize == size) {
        return;
    }
    m_minimumLogicalFontSize = size;
    settings->setMinLogicalFontSize((int)rint(size));
}

void WebCoreSettings::SetDefaultFontSize(float size)
{
    if (m_defaultFontSize == size) {
        return;
    }
	m_defaultFontSize = size;
    settings->setMediumFontSize((int)rint(size));
}

void WebCoreSettings::SetDefaultFixedFontSize:(float)size
{
    if (m_defaultFixedFontSize == size) {
        return;
    }
    m_defaultFixedFontSize = size;
    settings->setMediumFixedFontSize((int)rint(size));
}

void WebCoreSettings::SetJavaEnabled(bool enabled)
{
    m_javaEnabled = enabled;
    settings->setIsJavaEnabled(enabled);
}

void WebCoreSettings::SetPluginsEnabled(bool enabled)
{
    m_pluginsEnabled = enabled;
    settings->setArePluginsEnabled(enabled);
}

void WebCoreSettings::SetJavaScriptEnabled(bool enabled)
{
    m_javaScriptEnabled = enabled;
    settings->setIsJavaScriptEnabled(enabled);
}

void WebCoreSettings::SetJavaScriptCanOpenWindowsAutomatically(bool enabled)
{
    m_javaScriptCanOpenWindowsAutomatically = enabled;
    settings->setJavaScriptCanOpenWindowsAutomatically(enabled);
}

void WebCoreSettings::SetWillLoadImagesAutomatically(bool load)
{
    m_willLoadImagesAutomatically = load;
    settings->setAutoLoadImages(load);
}

void WebCoreSettings::SetUserStyleSheetLocation(const wxString& s)
{
    if (m_userStyleSheetLocation == s) {
        return;
    }
	m_userStyleSheetLocation == s;
    settings->setUserStyleSheet(s);
}

void WebCoreSettings::SetShouldPrintBackgrounds(bool enabled)
{
    m_shouldPrintBackgrounds = enabled;
    settings->setShouldPrintBackgrounds(enabled);
}

void WebCoreSettings::SetDefaultTextEncoding(const wxString& s)
{
    if (m_defaultTextEncoding == s) {
        return;
    }
	m_defaultTextEncoding = s;
    settings->setEncoding(s);
}