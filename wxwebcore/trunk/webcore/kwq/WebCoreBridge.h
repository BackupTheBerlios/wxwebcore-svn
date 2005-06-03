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

#include <wx/defs.h>
#include <wx/url.h>
#include <wx/datetime.h>
#include <wx/font.h>
#include <wx/dynarray.h>

#import "npruntime.h"

// FIXME: it'd be nice if we don't have to ifdef this...
#if __APPLE__
#include <JavaVM/jni.h>
#else
#include <jni.h>
#endif

#import "WebCoreKeyboardAccess.h"

class KWQKHTMLPart;
class KHTMLView;
class RenderArena;

namespace khtml {
    class RenderPart;
    class RenderObject;
}

typedef khtml::RenderPart KHTMLRenderPart;

class wxDOMCSSStyleDeclaration;
class wxDOMDocument;
class wxDOMDocumentFragment;
class wxDOMElement;
class wxDOMHTMLElement;
class wxDOMNode;
class wxDOMRange;
class WebCoreSettings;
class WebScriptObject;
class FontData;
class FormData;

// just a placeholder name for now, until we determine the best match for NSArray
class wxArray; 

//just for the moment so we can compile files including this header
//we may need/want to implement wx versions of these
class NSDictionary;
class NSAttributedString; //basically a string which stores formatting info
class NSRange;
class NSNotification;
class NSURLResponse;
typedef unsigned int NSDraggingOperation;
// possible values are here: 
// http://developer.apple.com/documentation/Cocoa/Reference/ApplicationKit/ObjC_classic/TypesAndConstants/AppKitTypes.html#//apple_ref/doc/uid/20000019-BAJJFEEE

typedef enum _NSSelectionAffinity {
   NSSelectionAffinityUpstream = 0,
   NSSelectionAffinityDownstream = 1
} NSSelectionAffinity;

typedef enum _NSCellState {
   NSMixedState = -1,
   NSOffState = 0,
   NSOnState = 1
} NSCellStateValue;

//end NS defines

extern wxString *WebCoreElementDOMNodeKey;
extern wxString *WebCoreElementFrameKey;
extern wxString *WebCoreElementImageAltStringKey;
extern wxString *WebCoreElementImageKey;
extern wxString *WebCoreElementImageRectKey;
extern wxString *WebCoreElementImageURLKey;
extern wxString *WebCoreElementIsSelectedKey;
extern wxString *WebCoreElementLinkURLKey;
extern wxString *WebCoreElementLinkTargetFrameKey;
extern wxString *WebCoreElementLinkLabelKey;
extern wxString *WebCoreElementLinkTitleKey;
extern wxString *WebCoreElementTitleKey;

extern wxString *WebCorePageCacheStateKey;

typedef enum {
    WebCoreDeviceScreen,
    WebCoreDevicePrinter
} WebCoreDeviceType;

typedef enum {
    WebSelectionStateNone,
    WebSelectionStateCaret,
    WebSelectionStateRange,
} WebSelectionState;

typedef enum {
    WebSelectByMoving,
    WebSelectByExtending
} WebSelectionAlteration;

typedef enum {
    WebSelectForward,
    WebSelectBackward,
    WebSelectRight,
    WebSelectLeft
} WebSelectionDirection;

typedef enum {
    WebSelectByCharacter,
    WebSelectByWord,
    WebSelectByLine,
    WebSelectByParagraph,
    WebSelectToLineBoundary,
    WebSelectToParagraphBoundary,
    WebSelectToDocumentBoundary
} WebSelectionGranularity;

typedef enum {
    WebScrollUp,
    WebScrollDown,
    WebScrollLeft,
    WebScrollRight
} WebScrollDirection;

typedef enum {
    WebScrollLine,
    WebScrollPage,
    WebScrollDocument,
    WebScrollWheel
} WebScrollGranularity;

typedef enum {
    WebUndoActionUnspecified,
    WebUndoActionSetColor,
    WebUndoActionSetBackgroundColor,
    WebUndoActionTurnOffKerning,
    WebUndoActionTightenKerning,
    WebUndoActionLoosenKerning,
    WebUndoActionUseStandardKerning,
    WebUndoActionTurnOffLigatures,
    WebUndoActionUseStandardLigatures,
    WebUndoActionUseAllLigatures,
    WebUndoActionRaiseBaseline,
    WebUndoActionLowerBaseline,
    WebUndoActionSetTraditionalCharacterShape,
    WebUndoActionSetFont,
    WebUndoActionChangeAttributes,
    WebUndoActionAlignLeft,
    WebUndoActionAlignRight,
    WebUndoActionCenter,
    WebUndoActionJustify,
    WebUndoActionSetWritingDirection,
    WebUndoActionSubscript,
    WebUndoActionSuperscript,
    WebUndoActionUnderline,
    WebUndoActionOutline,
    WebUndoActionUnscript,
    WebUndoActionDrag,
    WebUndoActionCut,
    WebUndoActionPaste,
    WebUndoActionPasteFont,
    WebUndoActionPasteRuler,
    WebUndoActionTyping,
} WebUndoAction;

// WebCoreBridge objects are used by WebCore to abstract away operations that need
// to be implemented by library clients, for example WebKit. The objects are also
// used in the opposite direction, for simple access to WebCore functions without dealing
// directly with the KHTML C++ classes.

// A WebCoreBridge creates and holds a reference to a KHTMLPart.

// The WebCoreBridge interface contains methods for use by the non-WebCore side of the bridge.

// KO: what this means for us is that this is the part that's implemented in WebCoreBridge.mm
// and it is basically a Cocoa and now wx wrapper around KHTMLPart.

class WebCoreBridge : wxObject
{
public:
	WebCoreBridge();
	~WebCoreBridge();
	
	static WebCoreBridge* bridgeForDOMDocument(DOMDocument* document);
	void initializeSettings(WebCoreSettings* settings);
	void setRenderPart(KHTMLRenderPart* renderPart);
	KHTMLRenderPart* getRenderPart() const {return _renderPart; }
	void setName(const wxString& name);
	wxString& getName() const;
	
	KWQKHTMLPart* getPart();
	void setParent(WebCoreBridge *parent);
	
	void provisionalLoadStarted();
	void openURL(const wxString& URL, bool reload, const wxString& contentType, const wxString& refresh, const wxDateTime& lastModified, NSDictionary* pageCache);
	void setEncoding(const wxFontEncoding& encoding, bool userChosen);
	void addData(void* data);
	void closeURL();
	
	void didNotOpenURL(const wxString& URL, NSDictionary* pageCache);
	bool canLoadURL(const wxString& URL, const wxString& referrer, bool hideReferrer);
	
	void saveDocumentState();
	void restoreDocumentState();
	
	bool canCachePage();
	bool saveDocumentToPageCache();
	
	void end();
	void stop();
	
	wxString& GetURL() const;
	wxString& GetBaseURL() const;
	
	void installInFrame(wxWindow* window);
	void removeFromFrame();
	
	void scrollToAnchor(const wxString& anchor);
	void scrollToAnchorWithURL(const wxString& URL);
	
	bool scrollOverflowInDirection(WebScrollDirection direction, WebScrollGranularity granularity);
	bool scrollOverflowWithScrollWheelEvent(wxEvent* event);
	
	void createKHTMLViewWithWindow(wxWindow* window, int marginWidth, int marginHeight);
	bool isFrameSet();
	
	void reapplyStylesForDeviceType(WebCoreDeviceType deviceType);
	void forceLayoutAdjustingViewSize(bool adjustSizeFlag);
	void forceLayoutWithMinimumPageWidth(float minPageWidth, float maxPageWidth, bool adjustSizeFlag);
	void sendResizeEvent();
	void sendScrollEvent();
	bool needsLayout();
	void setNeedsLayout();
	
	void drawRect(const wxRect& rect);
	void adjustPageHeightNew(float newBottom, float oldTop, float oldBottom, float bottomLimit);
	wxArray& computePageRectsWithPrintWidthScaleFactor(float printWidthScaleFactor, float printHeight);
	
	void setActivationEventNumber(int num);
	
	// event handlers
	void mouseDown(wxMouseEvent* event);
	void mouseUp(wxMouseEvent* event);
	void mouseMoved(wxMouseEvent* event);
	void mouseDragged(wxMouseEvent* event);
	
	bool sendContextMenuEvent(wxEvent* event); // return YES if event is eaten by WebCore
	
	wxWindow* nextKeyView();
	wxWindow* previousKeyView();
	
	wxWindow* nextKeyViewInsideWebFrameViews();
	wxWindow* previousKeyViewInsideWebFrameViews();
	
	// these two are tricky, they are looking for protocols rather than implementations...
	void* copyDOMTree(void* copier);
	void* copyRenderTree(void* copier);
	
	wxString& renderTreeAsExternalRepresentation() const;
	
	NSDictionary* elementAtPoint(const wxPoint& point);
	wxString& URLWithAttributeString(const wxString& string) const;
	
	DOMElement* elementWithName(const wxString& name, DOMElement* form);
	DOMElement* elementForView(wxWindow* view);
	
	bool elementDoesAutoComplete(DOMElement* element);
	bool elementIsPassword(DOMElement* element);
	
	DOMElement* formForElement(DOMElement* element);
	DOMElement* currentForm();
	wxArray& controlsInForm(DOMElement* form) const;
	wxString& searchForLabels(const wxArrayString& labels, DOMElement* beforeElement) const;
	wxString& matchLabels(const wxArrayString& labels, DOMElement* againstElement) const;
	
	bool searchFor(const wxString& string, bool direction, bool caseSensitive, bool wrap);
	void jumpToSelection();
	
	wxString& advanceToNextMisspelling() const;
	wxString& advanceToNextMisspellingStartingJustBeforeSelection() const;
	void unmarkAllMisspellings();
	
	void setTextSizeMultiplier(float multiplier);
	
	wxString& GetTextEncoding() const;
	
	wxString& stringByEvaluatingJavaScriptFromString(const wxString& string) const;
	wxString& stringByEvaluatingJavaScriptFromString(const wxString& string, bool forceUserGesture);
	
	DOMDocument* GetDOMDocument();
	DOMHTMLElement* GetFrameElement();
	
	bool isSelectionEditable();
	WebSelectionState GetSelectionState();
	
	NSAttributedString* selectedAttributedString();
	wxString& selectedString() const;
	
	void setSelectionFromNone();
	void setDisplaysWithFocusAttributes(bool flag);
	
	void setWindowHasFocus(bool flag);
	
	wxString& stringForRange(DOMRange* range) const;
	
	wxString& markupStringFromNode(DOMNode* node, wxArray* nodes);
	wxString& markupStringFromRange(DOMRange* range, wxArray* nodes);
	
	void selectAll();
	void deselectAll();
	void deselectText();
	
	wxRect& selectionRect() const;
	wxRect& visibleSelectionRect() const;
	
	void centerSelectionInVisibleArea();
	
	wxImage* selectionImage();
	wxRect& caretRectAtNode(DOMNode* node, int offset, NSSelectionAffinity affinity) const;
	wxRect& firstRectForDOMRange(DOMRange* range) const;
	
	void setSelectedDOMRange(DOMRange* range, NSSelectionAffinity selectionAffinity, bool closeTyping);
	DOMRange* selectedDOMRange();
	NSSelectionAffinity selectionAffinity();
	
	// Emacs-style-editing "mark"
	void setMarkDOMRange(DOMRange* range);
	DOMRange* markDOMRange();
	
	// international text input "marked text"
	void setMarkedTextDOMRange(DOMRange* range, const wxArray& attributes, const wxArray& ranges);
	DOMRange* markedTextDOMRange();
	void replaceMarkedTextWithText(const wxString& text);
	
	NSAttributedString* attributedStringFrom(DOMNode* startNode, int startOffset, DOMNode* endNode, int endOffset);
	
	wxFont& fontForSelection(bool hasMultipleFonts) const;
	NSDictionary* fontAttributesForSelectionStart();
	NSWritingDirection baseWritingDirectionForSelectionStart();
	
	// do we use 
	wxString& stringWithData(void* data, const wxFontEncoding& textEncoding) const;
	wxString& stringWithData(void* data, const wxString& textEncodingName) const;
	
	bool interceptKeyEvent(wxKeyEvent* event, wxWindow* view);
	
	void setShouldCreateRenderers(bool f);
	bool shouldCreateRenderers();
	
	int numPendingOrLoadingRequests();
	bool doneProcessingData();
	
	void setDrawsBackground(bool drawsBackground);
	
	wxColour& bodyBackgroundColor() const;
	wxColour& selectionColor() const;
	
	void adjustViewSize();
	
	void* accessibilityTree();
	
	void undoEditing(void* arg);
	void redoEditing(void* arg);
	
	DOMRange* rangeByExpandingSelectionWithGranularity(WebSelectionGranularity granularity);
	DOMRange* rangeOfCharactersAroundCaret();
	DOMRange* rangeByAlteringCurrentSelection(WebSelectionAlteration alteration, WebSelectionDirection direction, WebSelectionGranularity granularity);
	void alterCurrentSelection(WebSelectionAlteration alteration, WebSelectionDirection direction, WebSelectionGranularity granularity);
	DOMRange* rangeByAlteringCurrentSelection(WebSelectionAlteration alteration, float verticalDistance);
	WebSelectionGranularity selectionGranularity();
	
	DOMRange* smartDeleteRangeForProposedRange(DOMRange* proposedCharRange);
	void smartInsertForString(const wxString& pasteString, DOMRange* charRangeToReplace, wxString* beforeString, wxString* afterString); 
	bool canDeleteRange(DOMRange* range);
	void selectNSRange(const NSRange& range);
	NSRange selectedNSSRange() const;
	NSRange markedTextNSRange() const;
	DOMRange* convertToObjCDOMRange(NSRange range);
	
	DOMDocumentFragment* documentFragmentWithMarkupString(const wxString& markupString, const wxString& baseURLString);
	DOMDocumentFragment* documentFragmentWithText(const wxString& text);
	
	void replaceSelectionWithFragment(DOMDocumentFragment* fragment, bool selectReplacement, bool smartReplace, bool matchStyle);
	void replaceSelectionWithNode(DOMNode* node, bool selectReplacement, bool smartReplace);
	void replaceSelectionWithMarkupString(const wxString& markupString, const wxString& baseURLString, bool selectReplacement, bool smartReplace);
	void replaceSelectionWithText(const wxString& text, bool selectReplacement, bool smartReplace);
	
	void insertLineBreak();
	void insertParagraphSeparator();
	void insertParagraphSeparatorInQuotedContext();
	void insertText(const wxString& text, bool selectInsertedText);
	
	void setSelectionToDragCaret();
	void moveSelectionToDragCaret(DOMDocumentFragment* selectionFragment, bool smartMove);
	void moveDragCaretToPoint(const wxPoint& point);
	void removeDragCaret();
	DOMRange* dragCaretDOMRange();
	DOMRange* editableDOMRangeForPoint(const wxPoint& point);
	
	void deleteSelectionWithSmartDelete(bool smartDelete);
	void deleteKeyPressedWithSmartDelete(bool smartDelete);
	void forwardDeleteKeyPressedWithSmartDelete(bool smartDelete);
	
	DOMCSSStyleDeclaration* typingStyle();
	void setTypingStyle(DOMCSSStyleDeclaration* style, WebUndoAction undoAction);
	void applyStyle(DOMCSSStyleDeclaration* style, WebUndoAction undoAction);
	void applyParagraphStyle(DOMCSSStyleDeclaration* style, WebUndoAction undoAction);
	bool selectionStartHasStyle(DOMCSSStyleDeclaration* style);
	NSCellStateValue selectionHasStyle(DOMCSSStyleDeclaration* style);
	void applyEditingStyleToBodyElement();
	void removeEditingStyleFromBodyElement();
	void applyEditingStyleToElement(DOMElement* element);
	void removeEditingStyleFromElement(DOMElement* element);
	
	void ensureSelectionVisible();
	
	// these are part of the ObjC JS bindings
	WebScriptObject* windowScriptObject();
	NPObject* windowScriptNPObject();
	
	bool eventMayStartDrag(wxEvent* event);
	
	// the three functions below take an object that conforms to the "NSDraggingInfo"
	// interface. 
	NSDragOperation dragOperationForDraggingInfo(void* info);
	void dragExitedWithDraggingInfo(void* info);
	bool concludeDragForDraggingInfo(void* info);
	
	void dragSourceMovedTo(const wxPoint& windowLoc);
	void dragSourceEndedAt(const wxPoint& windowLoc, NSDragOperation operation);
	
	bool mayDHTMLCut();
	bool mayDHTMLCopy();
	bool mayDHTMLPaste();
	bool tryDHTMLCut();
	bool tryDHTMLCopy();
	bool tryDHTMLPaste();
	
	void clear();
	
private:
    KWQKHTMLPart *_part;
    KHTMLRenderPart *_renderPart;
    RenderArena *_renderPartArena;
    bool _shouldCreateRenderers;

// The WebCoreBridge protocol contains methods for use by the WebCore side of the bridge.

// In NSArray objects for post data, NSData objects represent literal data, and wxString objects represent encoded files.
// The encoding is the standard form encoding for uploading files.

// KO: A protocol in ObjC is closest to an base class/interface in C++/Java. It specifies a series of methods that any class 
// derived from it *must* implement. So our wxWebCoreCtrl, or whatever, will derive from this.
// However, that's up to us. I don't think anything in WebCore uses this. Safari does, but so long as we keep our 
// WebCoreBridge above in sync, we can decide how to wrap it into wx ourselves.

// KO: This is actually a complete TLW interface, as it manipulates status bar, toolbars, etc.
// I think we can actually change this as we need to, I don't see anywhere within WebCore that this interface is implemented

public:
	virtual wxList& childFrames(); // WebCoreBridge objects
	virtual WebCoreBridge* mainFrame();
	virtual WebCoreBridge* findFrameNamed(const wxString& name);
	/* Creates a name for an frame unnamed in the HTML.  It should produce repeatable results for loads of the same frameset. */
	virtual wxString& generateFrameName();
	virtual void frameDetached();
	virtual wxWindow* documentView();

	virtual void loadURL(const wxString& URL, const wxString& referrer, bool reload, bool userGesture, const wxString& target, wxEvent* triggerEvent, wxDOMElement* form, QMap<QString, QString>* formValues);
	virtual void postWithURL(const wxString& URL, const wxString& referrer, const wxString& target, FormData* data, const wxString& contentType, wxEvent* triggerEvent, wxDOMElement* form, QMap<QString, QString>* formValues);

	virtual WebCoreBridge* createWindowWithURL(const wxString& URL, const wxString& name);
	virtual void showWindow();

	virtual wxString& userAgentForURL(const wxString& URL) const;

	virtual void setTitle(const wxString& title);
	virtual void setStatusText(const wxString& status);

	virtual void setIconURL(const wxString& URL);
	virtual void setIconURL(const wxString& URL, const wxString& withType);

	virtual WebCoreBridge* createChildFrameNamed(const wxString& frameName, const wxString& withURL);
    virtual wxString& referrer() const;
	virtual void setReferrer(const wxString& referrer);
    virtual void renderPart(KHTMLRenderPart *renderPart);
    virtual void allowsScrolling(bool allowsScrolling, int marginWidth, int marginHeight);

	virtual bool areToolbarsVisible();
	virtual void setToolbarsVisible(bool visible);
	virtual bool isStatusBarVisible();
	virtual void setStatusBarVisible(bool visible);
	virtual bool areScrollbarsVisible();
	virtual void setScrollbarsVisible(bool visible);
	
	virtual wxFrame* window();
	virtual void setWindowFrame(const wxRect& frame);
	virtual wxRect& windowFrame() const;
	virtual void setWindowContentRect(const wxRect& frame);
	virtual wxRect& windowContentRect() const;

	virtual void setWindowIsResizable(bool resizable);
	virtual bool windowIsResizable();

	virtual void closeWindowSoon();

	virtual void runJavaScriptAlertPanelWithMessage(const wxString& message);
	virtual bool runJavaScriptConfirmPanelWithMessage(const wxString& message);
	virtual bool runJavaScriptTextInputPanelWithPrompt(const wxString& prompt, const wxString& defaultText, wxString* result);
	virtual void addMessageToConsole(NSDictionary* message);

//heck, we're probably not going to use some of this anyways, so I'll be lazy. :-)
#if 0
- (id <WebCoreResourceHandle>)startLoadingResource:(id <WebCoreResourceLoader>)loader withURL:(NSURL *)URL customHeaders:(NSDictionary *)customHeaders;
- (id <WebCoreResourceHandle>)startLoadingResource:(id <WebCoreResourceLoader>)loader withURL:(NSURL *)URL customHeaders:(NSDictionary *)customHeaders postData:(NSArray *)data;

- (void)objectLoadedFromCacheWithURL:(NSURL *)URL response:(NSURLResponse *)response data:(NSData *)data;

- (NSData *)syncLoadResourceWithURL:(NSURL *)URL customHeaders:(NSDictionary *)requestHeaders postData:(NSArray *)postData finalURL:(NSURL **)finalNSURL responseHeaders:(NSDictionary **)responseHeaderDict statusCode:(int *)statusCode;


#endif

	bool isReloading();
	time_t expiresTimeForResponse(NSURLResponse *response);

	void reportClientRedirectToURL(const wxString& URL, int seconds, const wxDateTime& fireDate, bool lockHistory, bool isJavaScriptFormAction);
	void reportClientRedirectCancelled(bool cancelWithLoadInProgress);

	void focusWindow;
	void unfocusWindow;

	wxWindow* nextKeyViewOutsideWebFrameViews();
	wxWindow* nextValidKeyViewOutsideWebFrameViews();
	wxWindow* previousKeyViewOutsideWebFrameViews();

	bool defersLoading();
	void setDefersLoading(bool loading);

// TODO: Need to decide what to do for these NSArrays...
#if 0
- (void)saveDocumentState:(NSArray *)documentState;
- (NSArray *)documentState;
#endif

	void setNeedsReapplyStyles();

	void tokenizerProcessedData();

// OK to be an wxString rather than an NSURL.
// This URL is only used for coloring visited links.
	wxString& requestedURLString() const;
	wxString& incomingReferrer() const;

#if 0
- (NSView *)viewForPluginWithURL:(NSURL *)URL
                  attributeNames:(NSArray *)attributeNames
                 attributeValues:(NSArray *)attributeValues
                        MIMEType:(wxString *)MIMEType;
- (NSView *)viewForJavaAppletWithFrame:(NSRect)frame
                        attributeNames:(NSArray *)attributeNames
                       attributeValues:(NSArray *)attributeValues
                               baseURL:(NSURL *)baseURL;
#endif

	bool saveDocumentToPageCache(void* documentInfo);

	int getObjectCacheSize();

	bool frameRequiredForMIMEType(const wxString& MIMEType, const wxString& URL);

	void loadEmptyDocumentSynchronously();

	wxString& MIMETypeForPath(const wxString& path) const;

	void allowDHTMLDrag(bool* flagDHTML, bool* UADrag);
	bool startDraggingImage(wxImage *dragImage, const wxPoint& dragLoc, NSDragOperation operation, const wxEvent& event, bool sourceIsDHTML, bool dhtmlWroteData);
	void handleAutoscrollForMouseDragged(const wxEvent& event);
	bool mayStartDragAtEventLocation(const wxPoint& location);

	bool selectWordBeforeMenuEvent();

	int historyLength();
	void goBackOrForward(int distance);
	bool canGoBackOrForward(int distance);

	void controlTextDidBeginEditing(NSNotification *obj);
	void controlTextDidEndEditing(NSNotification *obj);
	void controlTextDidChange(NSNotification *obj);

#if 0
- (BOOL)control:(NSControl *)control textShouldBeginEditing:(NSText *)fieldEditor;
- (BOOL)control:(NSControl *)control textShouldEndEditing:(NSText *)fieldEditor;
- (BOOL)control:(NSControl *)control didFailToFormatString:(wxString *)string errorDescription:(wxString *)error;
- (void)control:(NSControl *)control didFailToValidatePartialString:(wxString *)string errorDescription:(wxString *)error;
- (BOOL)control:(NSControl *)control isValidObject:(id)obj;
- (BOOL)control:(NSControl *)control textView:(NSTextView *)textView doCommandBySelector:(SEL)commandSelector;
- (BOOL)control:(NSControl *)control textView:(NSTextView *)textView shouldHandleEvent:(NSEvent *)event;

- (NSView <WebCoreFileButton> *)fileButtonWithDelegate:(id <WebCoreFileButtonDelegate>)delegate;

- (void)setHasBorder:(BOOL)hasBorder;

- (WebCoreKeyboardUIMode)keyboardUIMode;

- (void)didSetName:(wxString *)name;

- (NSFileWrapper *)fileWrapperForURL:(NSURL *)URL;

- (void)print;

- (jobject)getAppletInView:(NSView *)view;

// Deprecated, use getAppletInView: instead.
- (jobject)pollForAppletInView:(NSView *)view;

- (NSUndoManager *)undoManager;
- (wxString *)nameForUndoAction:(WebUndoAction)undoAction;
- (void)issueCutCommand;
- (void)issueCopyCommand;
- (void)issuePasteCommand;
- (void)issuePasteAndMatchStyleCommand;
- (void)respondToChangedSelection;
- (void)respondToChangedContents;
- (void)setIsSelected:(BOOL)isSelected forView:(NSView *)view;
- (BOOL)isEditable;
- (BOOL)shouldBeginEditing:(DOMRange *)range;
- (BOOL)shouldEndEditing:(DOMRange *)range;
- (BOOL)canPaste;

- (wxString *)overrideMediaType;

- (void)windowObjectCleared;

- (int)spellCheckerDocumentTag;
- (BOOL)isContinuousSpellCheckingEnabled;

- (void)didFirstLayout;

- (void)dashboardRegionsChanged:(NSMutableDictionary *)regions;

- (BOOL)isCharacterSmartReplaceExempt:(unichar)c isPreviousCharacter:(BOOL)isPreviousCharacter;
#endif
};


// This interface definition allows those who hold a WebCoreBridge * to call all the methods
// in the WebCoreBridge protocol without requiring the base implementation to supply the methods.
// This idiom is appropriate because WebCoreBridge is an abstract class.

#if 0
@interface WebCoreBridge (SubclassResponsibility) <WebCoreBridge>
@end

@protocol WebCoreDOMTreeCopier <NSObject>
- (NSObject *)nodeWithName:(wxString *)name value:(wxString *)value source:(wxString *)source children:(NSArray *)children;
@end

@protocol WebCoreRenderTreeCopier <NSObject>
- (NSObject *)nodeWithName:(wxString *)name position:(NSPoint)p rect:(NSRect)rect view:(NSView *)view children:(NSArray *)children;
@end

@protocol WebCoreFileButton <NSObject>
- (void)setFilename:(wxString *)filename;
- (void)performClick;
- (wxString *)filename;
- (float)baseline;
- (void)setVisualFrame:(NSRect)rect;
- (NSRect)visualFrame;
- (NSSize)bestVisualFrameSizeForCharacterCount:(int)count;
@end

@protocol WebCoreFileButtonDelegate <NSObject>
- (void)filenameChanged:(wxString *)filename;
- (void)focusChanged:(BOOL)nowHasFocus;
- (void)clicked;
@end
#endif