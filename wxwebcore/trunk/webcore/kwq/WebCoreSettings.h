

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
 
 #include <wx/defs.h>

class KHTMLSettings;

class WebCoreSettings: wxObject
{
public:

	WebCoreSettings();
	~WebCoreSettings();
	
    wxString GetStandardFontFamily() const { return m_stdFontFamily; }
	void SetStandardFontFamily(const wxString& s);
	
	wxString GetFixedFontFamily() const { return m_fixedFontFamily; }
	void SetFixedFontFamily(const wxString& s);

	wxString GetSerifFontFamily() const { return m_serifFontFamily; }
	void SetSerifFontFamily(const wxString& s);
	
	wxString GetSansSerifFontFamily() const { return m_sansSerifFontFamily; }
	void SetSansSerifFontFamily(const wxString& s);
	
	wxString GetCursiveFontFamily() const { return m_cursiveFontFamily; }
	void SetCursiveFontFamily(const wxString& s);
	
	wxString GetFantasyFontFamily() const { return m_fantasyFontFamily; }
	void SetFantasyFontFamily(const wxString& s);
	
	float GetMinimumFontSize() { return m_minimumFontSize; }
	void SetMinimumFontSize(const float size);
	
	float GetMinimumLogicalFontSize() { return m_minimumLogicalFontSize; }
	void SetMinimumLogicalFontSize(const float size);
	
	float GetDefaultFontSize() { return m_defaultFontSize; }
	void SetDefaultFontSize(const float size);
	
	float GetDefaultFixedFontSize() { return m_defaultFixedFontSize; }
	void SetDefaultFixedFontSize(const float size);
	
	wxString GetUserStyleSheetLocation() const { return m_userStyleSheetLocation; }
	void SetUserStyleSheetLocation(const wxString& location);
	
	wxString GetDefaultTextEncoding() const { return m_defaultTextEncoding; }
	void SetDefaultTextEncoding(const wxString& location);
	
	bool GetJavaEnabled() const { return m_javaEnabled; }
	void SetJavaEnabled(bool enabled);
	
	bool GetPluginsEnabled() const { return m_pluginsEnabled; }
	void SetPluginsEnabled(bool enabled);
	
	bool GetJavaScriptEnabled() const { return m_javaScriptEnabled; }
	void SetJavaScriptEnabled(bool enabled);
	
	bool GetJavaScriptCanOpenWindowsAutomatically() const { return m_javaScriptCanOpenWindowsAutomatically; }
	void SetJavaScriptCanOpenWindowsAutomatically(bool enabled);
	
	bool GetLoadWindowsAutomatically() const { return m_willLoadImagesAutomatically; }
	void SetLoadWindowsAutomatically(bool enabled);
	
	bool GetShouldPrintBackgrounds() const { return m_shouldPrintBackgrounds; }
	void SetShouldPrintBackgrounds(bool enabled);
	
	KHTMLSettings* GetKHTMLSettings() const { return m_settings; }
	
private:
	wxString m_stdFontFamily;
	wxString m_fixedFontFamily;
	wxString m_serifFontFamily;
	wxString m_sansSerifFontFamily;
	wxString m_cursiveFontFamily;
	wxString m_fantasyFontFamily;
	
    float m_minimumFontSize;
    float m_minimumLogicalFontSize;
    float m_defaultFontSize;
    float m_defaultFixedFontSize;
    bool m_javaEnabled;
    bool m_pluginsEnabled;
    bool m_javaScriptEnabled;
    bool m_javaScriptCanOpenWindowsAutomatically;
    bool m_willLoadImagesAutomatically;
    bool m_shouldPrintBackgrounds;

    wxString m_userStyleSheetLocation;
    wxString m_defaultTextEncoding;
    
    KHTMLSettings* m_settings;
}