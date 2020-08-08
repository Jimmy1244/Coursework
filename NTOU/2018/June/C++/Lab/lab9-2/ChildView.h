// ChildView.h : interface of the CChildView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CHILDVIEW_H__58A748C4_986F_46C5_A166_D2E0BF3DAEE7__INCLUDED_)
#define AFX_CHILDVIEW_H__58A748C4_986F_46C5_A166_D2E0BF3DAEE7__INCLUDED_

#include "Mandelbrot.h"	// Added by ClassView

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CChildView window

#include "BGR.h"

class CZoomWnd;

class CChildView : public CWnd
{
// Construction
public:
	CChildView();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CChildView)
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CChildView();

	// Generated message map functions
protected:
	//{{AFX_MSG(CChildView)
	afx_msg void OnPaint();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnDestroy();
	afx_msg void OnUpdatePauseAnimation(CCmdUI* pCmdUI);
	afx_msg void OnPauseAnimation();
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
    afx_msg BOOL OnToolTipNotify(UINT id, NMHDR *pNMHDR, LRESULT *pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	const double m_centerY;
	const double m_centerX;
	const double m_range;
	CRect m_zoomRect;
	CZoomWnd *m_zoomUpWnd;
	bool m_timerPaused;
	int m_animateInterval;
	unsigned int m_timerID;
	void newBitmap();
	int selection(int mag[], int nMag);
	void swap(int i, int j, int mag[], COLORREF colors[]);
	void generateRandomColors();

    sBGR m_mandel[500][500];
    int **m_data;
	CBitmap *m_pBmpMandel;
	sBGR *m_colors;

    Mandelbrot m_mandelbrot;
    int m_currentIteration;
	const int m_maxIterations;
	const int m_windowDimension;
public:
    virtual BOOL PreTranslateMessage(MSG* pMsg);
    virtual INT_PTR OnToolHitTest(CPoint point, TOOLINFO* pTI) const;
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHILDVIEW_H__58A748C4_986F_46C5_A166_D2E0BF3DAEE7__INCLUDED_)
