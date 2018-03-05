// OScopeCtrl.h : header file
//

#ifndef __OScopeCtrl_H__
#define __OScopeCtrl_H__

/////////////////////////////////////////////////////////////////////////////
// COScopeCtrl window

//##ModelId=3A0D7BAD0206
class COScopeCtrl : public CWnd
{
// Construction
public:
	//##ModelId=3A0D7BAD021B
  COScopeCtrl();

// Attributes
public:
	//##ModelId=3A0D7BAD0224
  double AppendPoint(double dNewPoint);
	//##ModelId=3A0D7BAD022E
  void SetRange(double dLower, double dUpper, int nDecimalPlaces=1);
	//##ModelId=3A0D7BAD0242
  void SetXUnits(CString string);
	//##ModelId=3A0D7BAD024D
  void SetYUnits(CString string);
	//##ModelId=3A0D7BAD0257
  void SetGridColor(COLORREF color);
	//##ModelId=3A0D7BAD026A
  void SetPlotColor(COLORREF color);
	//##ModelId=3A0D7BAD0274
  void SetBackgroundColor(COLORREF color);
	//##ModelId=3A0D7BAD027F
  void InvalidateCtrl();
	//##ModelId=3A0D7BAD0288
  void DrawPoint();
	//##ModelId=3A0D7BAD0292
  void Reset();

  // Operations
public:

// Overrides
  // ClassWizard generated virtual function overrides
  //{{AFX_VIRTUAL(COScopeCtrl)
  public:
	//##ModelId=3A0D7BAD029C
  virtual BOOL Create(DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID=NULL);
  //}}AFX_VIRTUAL

// Implementation
public:
	//##ModelId=3A0D7BAD02CE
  int m_nShiftPixels;          // amount to shift with each new point 
	//##ModelId=3A0D7BAD02E2
  int m_nYDecimals;

	//##ModelId=3A0D7BAD02EC
  CString m_strXUnitsString;
	//##ModelId=3A0D7BAD030A
  CString m_strYUnitsString;

	//##ModelId=3A0D7BAD031E
  COLORREF m_crBackColor;        // background color
	//##ModelId=3A0D7BAD0328
  COLORREF m_crGridColor;        // grid color
	//##ModelId=3A0D7BAD033C
  COLORREF m_crPlotColor;        // data color  
  
	//##ModelId=3A0D7BAD0350
  double m_dCurrentPosition;   // current position
	//##ModelId=3A0D7BAD0364
  double m_dPreviousPosition;  // previous position

	//##ModelId=3A0D7BAD0378
  virtual ~COScopeCtrl();

  // Generated message map functions
protected:
  //{{AFX_MSG(COScopeCtrl)
	//##ModelId=3A0D7BAD0382
  afx_msg void OnPaint();
	//##ModelId=3A0D7BAD03A0
  afx_msg void OnSize(UINT nType, int cx, int cy); 
  //}}AFX_MSG
  DECLARE_MESSAGE_MAP()

	//##ModelId=3A0D7BAD03B5
  int m_nHalfShiftPixels;
	//##ModelId=3A0D7BAD03C8
  int m_nPlotShiftPixels;
	//##ModelId=3A0D7BAD03DC
  int m_nClientHeight;
	//##ModelId=3A0D7BAE0012
  int m_nClientWidth;
	//##ModelId=3A0D7BAE0027
  int m_nPlotHeight;
	//##ModelId=3A0D7BAE003B
  int m_nPlotWidth;

	//##ModelId=3A0D7BAE004F
  double m_dLowerLimit;        // lower bounds
	//##ModelId=3A0D7BAE006D
  double m_dUpperLimit;        // upper bounds
	//##ModelId=3A0D7BAE0081
  double m_dRange;
	//##ModelId=3A0D7BAE0095
  double m_dVerticalFactor;
  
	//##ModelId=3A0D7BAE00A9
  CRect  m_rectClient;
	//##ModelId=3A0D7BAE00BD
  CRect  m_rectPlot;
	//##ModelId=3A0D7BAE00E6
  CPen   m_penPlot;
	//##ModelId=3A0D7BAE0104
  CBrush m_brushBack;

	//##ModelId=3A0D7BAE012C
  CDC     m_dcGrid;
	//##ModelId=3A0D7BAE014A
  CDC     m_dcPlot;
	//##ModelId=3A0D7BAE017C
  CBitmap *m_pbitmapOldGrid;
	//##ModelId=3A0D7BAE01A4
  CBitmap *m_pbitmapOldPlot;
	//##ModelId=3A0D7BAE01C2
  CBitmap m_bitmapGrid;
	//##ModelId=3A0D7BAE01F4
  CBitmap m_bitmapPlot;

};

/////////////////////////////////////////////////////////////////////////////
#endif
