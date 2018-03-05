// NN_Analysis.h : main header file for the NN_ANALYSIS application
//

#if !defined(AFX_NN_ANALYSIS_H__D73A12A4_27E4_4E0F_A563_66305AD1AF28__INCLUDED_)
#define AFX_NN_ANALYSIS_H__D73A12A4_27E4_4E0F_A563_66305AD1AF28__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CNN_AnalysisApp:
// See NN_Analysis.cpp for the implementation of this class
//

//##ModelId=3A0D7BAF01F5
class CNN_AnalysisApp : public CWinApp
{
public:
	//##ModelId=3A0D7BAF0209
	CNN_AnalysisApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNN_AnalysisApp)
	public:
	//##ModelId=3A0D7BAF020A
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CNN_AnalysisApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NN_ANALYSIS_H__D73A12A4_27E4_4E0F_A563_66305AD1AF28__INCLUDED_)
