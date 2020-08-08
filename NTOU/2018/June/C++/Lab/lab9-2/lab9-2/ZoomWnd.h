#if !defined(AFX_ZOOMWND_H__577A6E58_70A6_4EB5_B12F_BF13A46FAE50__INCLUDED_)
#define AFX_ZOOMWND_H__577A6E58_70A6_4EB5_B12F_BF13A46FAE50__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ZoomWnd.h : header file
//
#include "BGR.h"

/////////////////////////////////////////////////////////////////////////////
// CZoomWnd window

class CZoomWnd : public CWnd
{
// Construction
public:
    CZoomWnd(int size, sBGR colors[]);

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CZoomWnd)
	//}}AFX_VIRTUAL

// Implementation
public:
	void setMandel(double left, double top, double width, int maxIterations);
	void setColorTable(sBGR colors[]);
	virtual ~CZoomWnd();

	// Generated message map functions
protected:
	//{{AFX_MSG(CZoomWnd)
	afx_msg void OnPaint();
	afx_msg void OnClose();
	afx_msg void OnDestroy();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

    sBGR m_mandel[300][300];
    int **m_data;
	CBitmap *m_pBmpMandel;
	sBGR m_colors[256];

	const int m_windowDimension;
private:
	void newBitmap();
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ZOOMWND_H__577A6E58_70A6_4EB5_B12F_BF13A46FAE50__INCLUDED_)
