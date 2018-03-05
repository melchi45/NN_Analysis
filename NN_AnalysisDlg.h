// NN_AnalysisDlg.h : header file
//

#if !defined(AFX_NN_ANALYSISDLG_H__08971632_5082_4605_90ED_9B65D4FC4B48__INCLUDED_)
#define AFX_NN_ANALYSISDLG_H__08971632_5082_4605_90ED_9B65D4FC4B48__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "OScopeCtrl.h"

class COScopeThread;
/////////////////////////////////////////////////////////////////////////////
// CNN_AnalysisDlg dialog

//##ModelId=3A0D7BAE02F8
class CNN_AnalysisDlg : public CDialog
{
// Construction
public:
	//##ModelId=3A0D7BAE0303
	CNN_AnalysisDlg(CWnd* pParent = NULL);	// standard constructor
	//##ModelId=3A0D7BAE032B
	COScopeCtrl* m_OScopeCtrl;
	//##ModelId=3A0D7BAE0349
	COScopeThread* m_pOScopeThread;
// Dialog Data
	//{{AFX_DATA(CNN_AnalysisDlg)
	enum { IDD = IDD_NN_ANALYSIS_DIALOG };
	//##ModelId=3A0D7BAE035C
	CString	m_PatternFile;
	//##ModelId=3A0D7BAE0370
	CString	m_NetworkFile;
	//##ModelId=3A0D7BAE0384
	CString	m_LearningRate;
	//##ModelId=3A0D7BAE03A2
	CString	m_MomentumTerm;
	//##ModelId=3A0D7BAE03B6
	int		m_HiddenNodes1;
	//##ModelId=3A0D7BAE03D4
	int		m_InputNodes;
	//##ModelId=3A0D7BAF0000
	int		m_OutputNodes;
	//##ModelId=3A0D7BAF0014
	int		m_LayersNumber;
	//##ModelId=3A0D7BAF0032
	CString	m_Tolerance;
	//##ModelId=3A0D7BAF0046
	int		m_DisplayInterval;
	//##ModelId=3A0D7BAF005A
	int		m_HiddenNodes2;
	//##ModelId=3A0D7BAF006E
	int		m_HiddenNodes3;
	//##ModelId=3A0D7BAF008C
	int		m_HiddenNodes4;
	//##ModelId=3A0D7BAF00A0
	int		m_HiddenNodes5;
	//##ModelId=3A0D7BAF00B4
	int		m_HiddenNodes6;
	//##ModelId=3A0D7BAF00C8
	CString	m_Beta;
	//##ModelId=3A0D7BAF00DC
	int		m_PatternNum;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNN_AnalysisDlg)
	protected:
	//##ModelId=3A0D7BAF00F0
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//##ModelId=3A0D7BAF0104
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CNN_AnalysisDlg)
	//##ModelId=3A0D7BAF0122
	virtual BOOL OnInitDialog();
	//##ModelId=3A0D7BAF012D
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	//##ModelId=3A0D7BAF014A
	afx_msg void OnPaint();
	//##ModelId=3A0D7BAF0172
	afx_msg HCURSOR OnQueryDragIcon();
	//##ModelId=3A0D7BAF017C
	afx_msg void OnButtonTraining();
	//##ModelId=3A0D7BAF0190
	afx_msg void OnCheckPause();
	//##ModelId=3A0D7BAF019A
	virtual void OnOK();
	//##ModelId=3A0D7BAF01AF
	afx_msg void OnUpdateEditNumLayers();
	//##ModelId=3A0D7BAF01B9
	afx_msg void OnButtonStop();
	//##ModelId=3A0D7BAF01C4
	afx_msg void OnButtonRun();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NN_ANALYSISDLG_H__08971632_5082_4605_90ED_9B65D4FC4B48__INCLUDED_)
