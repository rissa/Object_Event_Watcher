/////////////////////////////////////////////////////////////////////////////
// CPPObjectWatcherApp.h : main header file for the CPPObjectWatcher DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "Resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CCPPObjectWatcherApp
// See CPPObjectWatcherApp.cpp for the implementation of this class
//

class CCPPObjectWatcherApp : public CWinApp
{
public:
	CCPPObjectWatcherApp();

// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

	DECLARE_MESSAGE_MAP()
};
