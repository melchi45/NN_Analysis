#if !defined(AFX_OSCOPETHREAD_H__72C492FE_9A5B_413F_A6F3_C4236EA6612C__INCLUDED_)
#define AFX_OSCOPETHREAD_H__72C492FE_9A5B_413F_A6F3_C4236EA6612C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// OScopeThread.h : header file
//
#include "NN_AnalysisDlg.h"


/////////////////////////////////////////////////////////////////////////////
// COScopeThread thread

//##ModelId=3A0D7BAC0218
class COScopeThread : public CWinThread
{
	DECLARE_DYNCREATE(COScopeThread)
protected:
	//##ModelId=3A0D7BAC022C
	COScopeThread();           // protected constructor used by dynamic creation
	//##ModelId=3A0D7BAC0273
	CNN_AnalysisDlg* m_pDlg;
// Attributes
public:
	// Dialog에 대한 변수.
	//##ModelId=3A0D7BAC0291
	CString	m_PatternFile;
	//##ModelId=3A0D7BAC02A5
	CString	m_NetworkFile;
	//##ModelId=3A0D7BAC02B9
	CString	m_LearningRate;
	//##ModelId=3A0D7BAC02CD
	CString	m_MomentumTerm;
	//##ModelId=3A0D7BAC02EB
	CString m_Beta;

	//##ModelId=3A0D7BAC02F5
	int		m_HiddenNodes1;
	//##ModelId=3A0D7BAC0309
	int		m_HiddenNodes2;
	//##ModelId=3A0D7BAC031D
	int		m_HiddenNodes3;
	//##ModelId=3A0D7BAC033B
	int		m_HiddenNodes4;
	//##ModelId=3A0D7BAC034F
	int		m_HiddenNodes5;
	//##ModelId=3A0D7BAC0363
	int		m_HiddenNodes6;

	//##ModelId=3A0D7BAC0377
	int		m_InputNodes;
	//##ModelId=3A0D7BAC038B
	int		m_OutputNodes;
	//##ModelId=3A0D7BAC039F
	int		m_LayersNumber;
	//##ModelId=3A0D7BAC03B3
	CString	m_Tolerance;
	//##ModelId=3A0D7BAC03C7
	int		m_DisplayInterval;
	//##ModelId=3A0D7BAC03DB
	int		m_PatternNum;
	
	//##ModelId=3A0D7BAD0007
	float f_LearningRate;
	//##ModelId=3A0D7BAD001B
	float f_MomentumTerm;
	//##ModelId=3A0D7BAD0025
	float f_Tolerance;
	//##ModelId=3A0D7BAD0039
	float f_Beta;
// Operations
public:
	//##ModelId=3A0D7BAD004D
	int Run(); // Thread의 구동.
	//##ModelId=3A0D7BAD0057
	void SetOwner(CNN_AnalysisDlg* pDlg); // Dialog에 대한 포인터 저장.

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COScopeThread)
	public:
	//##ModelId=3A0D7BAD0062
	virtual BOOL InitInstance();
	//##ModelId=3A0D7BAD0075
	virtual int ExitInstance();
	//}}AFX_VIRTUAL

// Implementation
protected:
	//##ModelId=3A0D7BAD0089
	virtual ~COScopeThread();

	// Generated message map functions
	//{{AFX_MSG(COScopeThread)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OSCOPETHREAD_H__72C492FE_9A5B_413F_A6F3_C4236EA6612C__INCLUDED_)
