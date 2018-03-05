// NN_AnalysisDlg.cpp : implementation file
//

#include "stdafx.h"
#include "NN_Analysis.h"
#include "NN_AnalysisDlg.h"
#include "OScopeThread.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

//##ModelId=3A0D7BB8016B
class CAboutDlg : public CDialog
{
public:
	//##ModelId=3A0D7BB8017F
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	//##ModelId=3A0D7BB80189
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//##ModelId=3A0D7BB8017F
CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

//##ModelId=3A0D7BB80189
void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNN_AnalysisDlg dialog

//##ModelId=3A0D7BAE0303
CNN_AnalysisDlg::CNN_AnalysisDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CNN_AnalysisDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CNN_AnalysisDlg)
	m_PatternFile = _T("iris.dat");
	m_NetworkFile = _T("iris.net");
	m_LearningRate = _T("0.45");
	m_MomentumTerm = _T("0.9");
	m_HiddenNodes1 = 5;
	m_InputNodes = 4;
	m_OutputNodes = 3;
	m_LayersNumber = 3;
	m_Tolerance = _T("0.5");
	m_DisplayInterval = 1;
	m_HiddenNodes2 = 0;
	m_HiddenNodes3 = 0;
	m_HiddenNodes4 = 0;
	m_HiddenNodes5 = 0;
	m_HiddenNodes6 = 0;
	m_Beta = _T("1.0");
	m_PatternNum = 150;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_OScopeCtrl = new (COScopeCtrl);//m_OScopeCtrl;
}

//##ModelId=3A0D7BAF00F0
void CNN_AnalysisDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CNN_AnalysisDlg)
	DDX_Text(pDX, IDC_EDIT_PATTERN_FILE, m_PatternFile);
	DDX_Text(pDX, IDC_EDIT_NETWORK_FILE, m_NetworkFile);
	DDX_Text(pDX, IDC_EDIT_LEARNING_RATE, m_LearningRate);
	DDX_Text(pDX, IDC_EDIT_MOMENTUM_TERM, m_MomentumTerm);
	DDX_Text(pDX, IDC_EDIT_HIDDEN_NODE1, m_HiddenNodes1);
	DDX_Text(pDX, IDC_EDIT_INPUT_NODE, m_InputNodes);
	DDX_Text(pDX, IDC_EDIT_OUTPUT_NODE, m_OutputNodes);
	DDX_Text(pDX, IDC_EDIT_NUM_LAYERS, m_LayersNumber);
	DDV_MinMaxInt(pDX, m_LayersNumber, 3, 8);
	DDX_Text(pDX, IDC_EDIT_TOLERANCE, m_Tolerance);
	DDX_Text(pDX, IDC_EDIT_DISPLAY_INTERVAL, m_DisplayInterval);
	DDX_Text(pDX, IDC_EDIT_HIDDEN_NODE2, m_HiddenNodes2);
	DDX_Text(pDX, IDC_EDIT_HIDDEN_NODE3, m_HiddenNodes3);
	DDX_Text(pDX, IDC_EDIT_HIDDEN_NODE4, m_HiddenNodes4);
	DDX_Text(pDX, IDC_EDIT_HIDDEN_NODE5, m_HiddenNodes5);
	DDX_Text(pDX, IDC_EDIT_HIDDEN_NODE6, m_HiddenNodes6);
	DDX_Text(pDX, IDC_EDIT_BETA, m_Beta);
	DDX_Text(pDX, IDC_EDIT_PATTERN_NUM, m_PatternNum);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CNN_AnalysisDlg, CDialog)
	//{{AFX_MSG_MAP(CNN_AnalysisDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_TRAINING, OnButtonTraining)
	ON_BN_CLICKED(IDC_CHECK_PAUSE, OnCheckPause)
	ON_EN_UPDATE(IDC_EDIT_NUM_LAYERS, OnUpdateEditNumLayers)
	ON_BN_CLICKED(IDC_BUTTON_STOP, OnButtonStop)
	ON_BN_CLICKED(IDC_BUTTON_RUN, OnButtonRun)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNN_AnalysisDlg message handlers

//##ModelId=3A0D7BAF0122
BOOL CNN_AnalysisDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	// Static Control에 대한 사이즈 
	CRect rect;
	GetDlgItem(IDC_STATIC_OSCILLOSCOPE)->GetWindowRect(rect) ;
	ScreenToClient(rect) ;

	// create the control
	m_OScopeCtrl->Create(WS_VISIBLE | WS_CHILD, rect, this) ;

	// customize the control
	m_OScopeCtrl->SetRange(0.0, 1.0, 2) ;
	m_OScopeCtrl->SetYUnits("Squre Error Sum") ;
	m_OScopeCtrl->SetXUnits("Iteration") ;
	m_OScopeCtrl->SetBackgroundColor(RGB(0, 0, 0)) ;
	m_OScopeCtrl->SetGridColor(RGB(0, 125, 200)) ;
	m_OScopeCtrl->SetPlotColor(RGB(255, 255, 255)) ;
	
	// Edit박스에 대한 FALSE
	if(m_LayersNumber == 3)
	{
		GetDlgItem(IDC_EDIT_HIDDEN_NODE2)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT_HIDDEN_NODE3)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT_HIDDEN_NODE4)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT_HIDDEN_NODE5)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT_HIDDEN_NODE6)->EnableWindow(FALSE);
	}
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

//##ModelId=3A0D7BAF012D
void CNN_AnalysisDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

//##ModelId=3A0D7BAF014A
void CNN_AnalysisDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
//##ModelId=3A0D7BAF0172
HCURSOR CNN_AnalysisDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

//##ModelId=3A0D7BAF017C
void CNN_AnalysisDlg::OnButtonTraining() 
{
	// Button이 눌렸을때 Thread를 생성시킨다.
	m_pOScopeThread	= (COScopeThread*)AfxBeginThread(RUNTIME_CLASS(COScopeThread),
		THREAD_PRIORITY_LOWEST, 0, CREATE_SUSPENDED);
	m_pOScopeThread->SetOwner(this); // Dlg에 대한 포인터를 넘긴다.
	m_pOScopeThread->ResumeThread(); // Thread를 시작 시킨다.
	// Thread를 동작하는 동안 다른 Thread를 동작 시키지 못하게 한다.
	GetDlgItem(IDC_BUTTON_TRAINING)->EnableWindow(FALSE); 
}

//##ModelId=3A0D7BAF0190
void CNN_AnalysisDlg::OnCheckPause() 
{
	// 체크 버튼에 대한 멈춤/재개를 결정한다.
	CButton* pCheck = (CButton*)GetDlgItem(IDC_CHECK_PAUSE);
	BOOL bSuspend = pCheck->GetCheck();

	if(bSuspend)
		m_pOScopeThread->SuspendThread();
	else
		m_pOScopeThread->ResumeThread();
}

//##ModelId=3A0D7BAF019A
void CNN_AnalysisDlg::OnOK() 
{
	CDialog::OnOK();
}

//##ModelId=3A0D7BAF01AF
void CNN_AnalysisDlg::OnUpdateEditNumLayers() 
{
	// Edit 데이터 변경에 따른 Enable설정.
	UpdateData(TRUE);

	if(m_LayersNumber == 3)
	{
		GetDlgItem(IDC_EDIT_HIDDEN_NODE2)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT_HIDDEN_NODE3)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT_HIDDEN_NODE4)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT_HIDDEN_NODE5)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT_HIDDEN_NODE6)->EnableWindow(FALSE);
	}
	if(m_LayersNumber == 4)
	{
		GetDlgItem(IDC_EDIT_HIDDEN_NODE2)->EnableWindow(TRUE);
		GetDlgItem(IDC_EDIT_HIDDEN_NODE3)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT_HIDDEN_NODE4)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT_HIDDEN_NODE5)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT_HIDDEN_NODE6)->EnableWindow(FALSE);
	}
	else if(m_LayersNumber == 5)
	{
		GetDlgItem(IDC_EDIT_HIDDEN_NODE2)->EnableWindow(TRUE);
		GetDlgItem(IDC_EDIT_HIDDEN_NODE3)->EnableWindow(TRUE);
		GetDlgItem(IDC_EDIT_HIDDEN_NODE4)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT_HIDDEN_NODE5)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT_HIDDEN_NODE6)->EnableWindow(FALSE);
	}
	else if(m_LayersNumber == 6)
	{
		GetDlgItem(IDC_EDIT_HIDDEN_NODE2)->EnableWindow(TRUE);
		GetDlgItem(IDC_EDIT_HIDDEN_NODE3)->EnableWindow(TRUE);
		GetDlgItem(IDC_EDIT_HIDDEN_NODE4)->EnableWindow(TRUE);
		GetDlgItem(IDC_EDIT_HIDDEN_NODE5)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT_HIDDEN_NODE6)->EnableWindow(FALSE);
	}
	else if(m_LayersNumber == 7)
	{
		GetDlgItem(IDC_EDIT_HIDDEN_NODE2)->EnableWindow(TRUE);
		GetDlgItem(IDC_EDIT_HIDDEN_NODE3)->EnableWindow(TRUE);
		GetDlgItem(IDC_EDIT_HIDDEN_NODE4)->EnableWindow(TRUE);
		GetDlgItem(IDC_EDIT_HIDDEN_NODE5)->EnableWindow(TRUE);
		GetDlgItem(IDC_EDIT_HIDDEN_NODE6)->EnableWindow(FALSE);
	}
	else if(m_LayersNumber == 8)
	{
		GetDlgItem(IDC_EDIT_HIDDEN_NODE2)->EnableWindow(TRUE);
		GetDlgItem(IDC_EDIT_HIDDEN_NODE3)->EnableWindow(TRUE);
		GetDlgItem(IDC_EDIT_HIDDEN_NODE4)->EnableWindow(TRUE);
		GetDlgItem(IDC_EDIT_HIDDEN_NODE5)->EnableWindow(TRUE);
		GetDlgItem(IDC_EDIT_HIDDEN_NODE6)->EnableWindow(TRUE);
	}

	UpdateData(FALSE);
}


//##ModelId=3A0D7BAF01B9
void CNN_AnalysisDlg::OnButtonStop() 
{
	// Stop에 대한 Thread 중지...
	m_pOScopeThread->SuspendThread();
	GetDlgItem(IDC_BUTTON_TRAINING)->EnableWindow(TRUE);
}

//##ModelId=3A0D7BAF01C4
void CNN_AnalysisDlg::OnButtonRun() 
{
	ShellExecute(this->m_hWnd, NULL, "NN_Test.Exe", NULL,"",SW_SHOW);
	
}
