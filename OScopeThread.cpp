// OScopeThread.cpp : implementation file
//

#include "stdafx.h"
#include "NN_Analysis.h"
#include "OScopeThread.h"
#include "OScopeCtrl.h"

#include "EpochBP.h"
#include "GenBP.h"
//#include "GenSteepness.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define MAX_PATTERNS	300
/////////////////////////////////////////////////////////////////////////////
// COScopeThread

IMPLEMENT_DYNCREATE(COScopeThread, CWinThread)

//##ModelId=3A0D7BAC022C
COScopeThread::COScopeThread()
{
}

//##ModelId=3A0D7BAD0089
COScopeThread::~COScopeThread()
{
}

//##ModelId=3A0D7BAD0062
BOOL COScopeThread::InitInstance()
{
	// TODO:  perform and per-thread initialization here
	return TRUE;
}

//##ModelId=3A0D7BAD0075
int COScopeThread::ExitInstance()
{
	// TODO:  perform any per-thread cleanup here
	return CWinThread::ExitInstance();
}

BEGIN_MESSAGE_MAP(COScopeThread, CWinThread)
	//{{AFX_MSG_MAP(COScopeThread)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COScopeThread message handlers

//##ModelId=3A0D7BAD0057
void COScopeThread::SetOwner(CNN_AnalysisDlg* pDlg)
{
	m_pDlg = pDlg;
}

//##ModelId=3A0D7BAD004D
int COScopeThread::Run()
{
	// Training데이터 Raed와 
	// Training 알고리즘의 적용.

	CString strTemp;
	// Dialog의 오실로스코프 포인터를 가져온다.
	COScopeCtrl* pOScope = (COScopeCtrl*)m_pDlg->m_OScopeCtrl;
	//.GetDlgItem(IDC_STATIC_OSCILLOSCOPE);
	
	// 패턴에 Buffer 
	Pattern *data[MAX_PATTERNS];
	
	int pattern_count = 0;
	int *node_cnt;
	
	// Dialog의 ID데이터 가져오기
	m_pDlg->GetDlgItemText(IDC_EDIT_PATTERN_FILE, m_PatternFile);
	m_pDlg->GetDlgItemText(IDC_EDIT_NETWORK_FILE, m_NetworkFile);
	m_pDlg->GetDlgItemText(IDC_EDIT_LEARNING_RATE, m_LearningRate);
	m_pDlg->GetDlgItemText(IDC_EDIT_MOMENTUM_TERM, m_MomentumTerm);
	m_pDlg->GetDlgItemText(IDC_EDIT_TOLERANCE, m_Tolerance);
	m_pDlg->GetDlgItemText(IDC_EDIT_BETA, m_Beta);

	f_LearningRate = atof(m_LearningRate);
	f_MomentumTerm = atof(m_MomentumTerm);
	f_Tolerance = atof(m_Tolerance);
	f_Beta = atof(m_Beta);
	
	m_LayersNumber = m_pDlg->GetDlgItemInt(IDC_EDIT_NUM_LAYERS);
	m_InputNodes = m_pDlg->GetDlgItemInt(IDC_EDIT_INPUT_NODE);
	m_OutputNodes = m_pDlg->GetDlgItemInt(IDC_EDIT_OUTPUT_NODE);
	
	m_HiddenNodes1 = m_pDlg->GetDlgItemInt(IDC_EDIT_HIDDEN_NODE1);
	m_HiddenNodes2 = m_pDlg->GetDlgItemInt(IDC_EDIT_HIDDEN_NODE2);
	m_HiddenNodes3 = m_pDlg->GetDlgItemInt(IDC_EDIT_HIDDEN_NODE3);
	m_HiddenNodes4 = m_pDlg->GetDlgItemInt(IDC_EDIT_HIDDEN_NODE4);
	m_HiddenNodes5 = m_pDlg->GetDlgItemInt(IDC_EDIT_HIDDEN_NODE5);
	m_HiddenNodes6 = m_pDlg->GetDlgItemInt(IDC_EDIT_HIDDEN_NODE6);

	m_PatternNum = m_pDlg->GetDlgItemInt(IDC_EDIT_PATTERN_NUM);
		
	m_DisplayInterval = m_pDlg->GetDlgItemInt(IDC_EDIT_DISPLAY_INTERVAL);
	
	// 노드에 대한 데이터로 저장
	node_cnt = new int[m_LayersNumber];
	
	node_cnt[0] = m_InputNodes; // Input Node
	
	if(m_LayersNumber == 3)
	{
		node_cnt[1] = m_HiddenNodes1;
	}
	else if(m_LayersNumber == 4)
	{
		node_cnt[1] = m_HiddenNodes1;
		node_cnt[2] = m_HiddenNodes2;
	}
	else if(m_LayersNumber == 5)
	{
		node_cnt[1] = m_HiddenNodes1;
		node_cnt[2] = m_HiddenNodes2;
		node_cnt[3] = m_HiddenNodes3;
	}
	else if(m_LayersNumber == 6)
	{
		node_cnt[1] = m_HiddenNodes1;
		node_cnt[2] = m_HiddenNodes2;
		node_cnt[3] = m_HiddenNodes3;
		node_cnt[4] = m_HiddenNodes4;
	}
	else if(m_LayersNumber == 7)
	{
		node_cnt[1] = m_HiddenNodes1;
		node_cnt[2] = m_HiddenNodes2;
		node_cnt[3] = m_HiddenNodes3;
		node_cnt[4] = m_HiddenNodes4;
		node_cnt[5] = m_HiddenNodes5;
	}
	else if(m_LayersNumber == 8)
	{
		node_cnt[1] = m_HiddenNodes1;
		node_cnt[2] = m_HiddenNodes2;
		node_cnt[3] = m_HiddenNodes3;
		node_cnt[4] = m_HiddenNodes4;
		node_cnt[5] = m_HiddenNodes5;
		node_cnt[6] = m_HiddenNodes6;
	}
	
	node_cnt[m_LayersNumber-1] = m_OutputNodes; // Output Node
	
		
	std::ifstream infile((LPTSTR)(LPCTSTR)m_PatternFile);
	
	while( !infile.eof() && !infile.fail())
	{
		data[pattern_count] = new Pattern(m_InputNodes, m_OutputNodes, infile);
		pattern_count++;
	}
	
	infile.close();
	// BackPropagation Network 구성
	Generic_BackProp<Input_Node, BP_Hidden_Node, BP_Output_Node, Epoch_BP_Link>
		BPnet(f_LearningRate, f_MomentumTerm, m_LayersNumber, node_cnt);

	// BackPropagation Network 구성
//	Generic_Steepness<Input_Node, Steepness_Hidden_Node, Steepness_Output_Node, Steepness_Link>
//		BPnet(f_LearningRate, f_MomentumTerm, f_Beta, m_LayersNumber, node_cnt);
	
	long iteration =0;
	int good = 0;
	double total_error;
	
	int best = 0;
	std::ofstream ofile("test.out");
	
	BPnet.Print(ofile);
	ofile.close();
	
	// Learn 및 Run
	while( good < pattern_count)
	{
		good = 0;
		total_error = 0.0;
		BPnet.Epoch(pattern_count);
		for(int i = 0; i <pattern_count; i++)
		{
			BPnet.Set_Value(data[i]);
			BPnet.Run();
			
			BPnet.Set_Error(data[i]);
			
			BPnet.Learn();
			int good_outputs = 0;
			
			for(int j =0; j < m_OutputNodes; j++)
			{
				// Squre Error Sum
				if(fabs(BPnet.Get_Value(j) - data[i]->Out(j)) < f_Tolerance)
						good_outputs++;
				total_error += fabs(BPnet.Get_Error(j));
//				total_error += sqrt( pow(BPnet.Get_Value(j) - data[i]->Out(j), 2) / pattern_count);
			}
			
			if(good_outputs == m_OutputNodes)
				good++;
		}

		total_error = total_error / pattern_count;

		strTemp.Format("%.7f", total_error);
		m_pDlg->SetDlgItemText(IDC_EDIT_ERROR, strTemp);
		
		if(best < good)
		{
			best = good;
			
			std::ofstream outfile((LPTSTR)(LPCTSTR)m_NetworkFile);
			
			BPnet.Save(outfile);
			outfile.close();
		}
		
		if(iteration % m_DisplayInterval == 0) 
		{
			// Display Interval에 따른 출력 별화 그래프 Update
			pOScope->AppendPoint(total_error);
		}
		strTemp.Format("%d", iteration);
		m_pDlg->SetDlgItemText(IDC_EDIT_ITERATION, strTemp);
		iteration++;
	}
	
	// Learining이 끝났을때 파일로 네트워크 저장
	std::ofstream outfile((LPTSTR)(LPCTSTR)m_NetworkFile);
	BPnet.Save(outfile);
	outfile.close(); 
	// Thread 종료
	AfxEndThread(0); 
	// Learning의 Enable
	m_pDlg->GetDlgItem(IDC_BUTTON_TRAINING)->EnableWindow(TRUE);
	 
	return CWinThread::Run();
}
