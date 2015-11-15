
// GrafikaGodHelpUsAll.h : main header file for the GrafikaGodHelpUsAll application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CGrafikaGodHelpUsAllApp:
// See GrafikaGodHelpUsAll.cpp for the implementation of this class
//

class CGrafikaGodHelpUsAllApp : public CWinApp
{
public:
	CGrafikaGodHelpUsAllApp();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	void DrawInstrumenTable(CDC* pDC, CRect rect, COLORREF color);
	void DrawRectangle(CDC* pDC, CRect rect, COLORREF color);

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CGrafikaGodHelpUsAllApp theApp;
