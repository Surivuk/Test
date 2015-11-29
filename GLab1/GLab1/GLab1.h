
// GLab1.h : main header file for the GLab1 application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CGLab1App:
// See GLab1.cpp for the implementation of this class
//

class CGLab1App : public CWinApp
{
public:
	CGLab1App();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CGLab1App theApp;
