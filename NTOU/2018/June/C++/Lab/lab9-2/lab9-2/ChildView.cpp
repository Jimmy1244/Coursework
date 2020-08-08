// ChildView.cpp : implementation of the CChildView class
//

#include "stdafx.h"
#include "Mandelbrot03.h"
#include "ChildView.h"
#include "MainFrm.h"
#include "ZoomWnd.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CChildView

CChildView::CChildView()
    : m_windowDimension(500),
      m_maxIterations(256),
      m_mandelbrot(-0.5, 0.0, 2.25, 500),
      m_pBmpMandel(0),
      m_animateInterval(500),
      m_currentIteration(0),
      m_timerPaused(false),
      m_range(2.25),
      m_centerX(-0.5),
      m_centerY(0.0)
{
    memset(m_mandel, 0, m_windowDimension*m_windowDimension*sizeof(sBGR));
    int i, j;
    m_data = new int*[m_windowDimension];
    for (i=0; i<m_windowDimension; i++)
    {
        m_data[i] = new int[m_windowDimension];
        for (j=0; j<m_windowDimension; j++)
            m_data[i][j] = 0;
    }
    m_colors = new sBGR[m_maxIterations];
}

CChildView::~CChildView()
{
    delete m_pBmpMandel;
    delete[] m_colors;
    int i;
    if (m_data)
    {
        for (i=0; i<m_windowDimension; i++)
            delete[] m_data[i];
        delete[] m_data;
    }
    delete m_zoomUpWnd;
}

BEGIN_MESSAGE_MAP(CChildView,CWnd )
	//{{AFX_MSG_MAP(CChildView)
	ON_WM_PAINT()
	ON_WM_CREATE()
	ON_WM_LBUTTONDOWN()
	ON_WM_TIMER()
	ON_WM_DESTROY()
	ON_UPDATE_COMMAND_UI(IDM_PAUSEANIMATION, OnUpdatePauseAnimation)
	ON_COMMAND(IDM_PAUSEANIMATION, OnPauseAnimation)
	ON_WM_RBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDBLCLK()
    ON_NOTIFY_EX_RANGE(TTN_NEEDTEXTW, 0, 0xFFFF, OnToolTipNotify) // Unicode
    ON_NOTIFY_EX_RANGE(TTN_NEEDTEXTA, 0, 0xFFFF, OnToolTipNotify) // ASCII
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CChildView message handlers

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(NULL, IDC_ARROW), HBRUSH(COLOR_WINDOW+1), NULL);

	return TRUE;
}

void CChildView::newBitmap()
{
    int width=m_windowDimension;
    int height=m_windowDimension;

	pBGR mandelLine = (pBGR) m_mandel;
	int stepX, stepY;
	for (stepY=0; stepY<height; stepY++) 
    {
		for (stepX=0; stepX<width; stepX++) 
		{
            ASSERT((m_data[stepX][stepY] <= 255) &&
                   (m_data[stepX][stepY] >= 0)); 
            mandelLine[stepX] = m_colors[255-m_data[stepX][stepY]];
        }
		mandelLine += width;
	}

	BITMAPINFO bi;
	bi.bmiHeader.biSize = sizeof(bi.bmiHeader);
	bi.bmiHeader.biWidth = width;
	bi.bmiHeader.biHeight = height;
	bi.bmiHeader.biPlanes = 1;
	bi.bmiHeader.biBitCount = 32;
	bi.bmiHeader.biCompression = BI_RGB;
	bi.bmiHeader.biSizeImage = 4 * width * height;
	bi.bmiHeader.biClrUsed = 0;
	bi.bmiHeader.biClrImportant = 0;

    CClientDC dc(this);

    HBITMAP hBmpMandel = CreateCompatibleBitmap(dc.GetSafeHdc(), width, height);
    SetDIBits(dc.GetSafeHdc(), hBmpMandel, 0, height, m_mandel, &bi, DIB_RGB_COLORS);

    delete m_pBmpMandel;
    m_pBmpMandel = new CBitmap;
    m_pBmpMandel->Attach(hBmpMandel);
}


void CChildView::OnPaint() 
{
	CPaintDC dc(this); // device context for painting

    newBitmap();
    CDC dcMem;
    dcMem.CreateCompatibleDC(&dc);
    CBitmap *pOldBmp = (CBitmap *)dcMem.SelectObject(m_pBmpMandel);
    dc.BitBlt(0, 0, m_windowDimension, m_windowDimension,
              &dcMem, 0, 0, SRCCOPY);
    dcMem.SelectObject(pOldBmp);

	// Do not call CWnd::OnPaint() for painting messages
}

int CChildView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CWnd ::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
//    CWaitCursor wait;
    ++m_currentIteration;
    m_mandelbrot.generateData(m_data, 1);

    generateRandomColors();

	if (SetTimer(1000, m_animateInterval, 0))
        m_timerID = 1000;

    LPCTSTR strMyClass = AfxRegisterWndClass(
      CS_VREDRAW | CS_HREDRAW,
      ::LoadCursor(NULL, IDC_ARROW),
      (HBRUSH) ::GetStockObject(WHITE_BRUSH),
      ::LoadIcon(NULL, MAKEINTRESOURCE(IDI_ZOOM)));

    m_zoomUpWnd = new CZoomWnd(300, m_colors);

    m_zoomUpWnd->CreateEx(0, strMyClass, "Zoom Up Window for Mandelbrot", 
        WS_OVERLAPPED, 0, 0, 305, 305, 0, 0);

    m_zoomUpWnd->SetIcon( ::LoadIcon(NULL, MAKEINTRESOURCE(IDI_ZOOM)), true );

    m_zoomUpWnd->ShowWindow(SW_SHOW);

    EnableToolTips(TRUE);
//    m_zoomUpWnd->setMandel(-1.5,1.1,1.1,25);
	return 0;
}

void CChildView::generateRandomColors()
{
    int color1, color2, color3, i, mag[256], min;
    COLORREF colors[256];
    *(int *)&m_colors[255] = 0x00ffffff;
	for (i=0; i<255; i++)
    {
        color1=rand()%210;
        color1 -= color1 %10;
        color2=rand()%210;
        color2 -= color2 %10;
        color3=rand()%210;
        color3 -= color3 %10;
        colors[i] = RGB(color1+55, 
                        color2+55, 
                        color3+55);
        mag[i] = (color1+55)*(color1+55)+
                 (color2+55)*(color2+55)+
                 (color3+55)*(color3+55);
    }
    for (i=0; i<255; i++)
    {
        min = selection(&mag[i], 255-i);
        swap(i, min+i, mag, colors);
    }

    for (i=0; i<255; i++)
    {
        m_colors[i].b = GetBValue(colors[i]);
        m_colors[i].g = GetGValue(colors[i]);
        m_colors[i].r = GetRValue(colors[i]);
        m_colors[i].pad = 0;
    }
}

int CChildView::selection(int mag[], int nMag)
{
    int i, min=0;
    for (i=1; i<nMag; i++)
        if (mag[i]<mag[min]) min = i;
    return min;
}

void CChildView::swap(int i, int j, int mag[], COLORREF colors[])
{
    COLORREF tmpC;
    int tmpM;
    tmpC = colors[i];
    tmpM = mag[i];
    colors[i] = colors[j];
    mag[i] = mag[j];
    colors[j] = tmpC;
    mag[j] = tmpM;
}

void CChildView::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
    if (nIDEvent == m_timerID)
    {
        if (!m_timerPaused)
            if (m_currentIteration < m_maxIterations)
            {
                int nChanges = m_mandelbrot.updateData(m_data, m_currentIteration);
                m_currentIteration++;
                CString str;
                str.Format("Iteration: %d %d points diverge", m_currentIteration, nChanges);
                ((CMainFrame *)AfxGetMainWnd())->SetMessageText(str);
                Invalidate(FALSE);
            }
    }
	
	CWnd ::OnTimer(nIDEvent);
}

void CChildView::OnDestroy() 
{
    m_zoomUpWnd->DestroyWindow();
	CWnd::OnDestroy();
	
    if (m_timerID)
        KillTimer(m_timerID);
}

void CChildView::OnUpdatePauseAnimation(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
    pCmdUI->SetCheck(m_timerPaused);	
}

void CChildView::OnPauseAnimation() 
{
    m_timerPaused = !m_timerPaused;	
}

void CChildView::OnRButtonDown(UINT nFlags, CPoint point) 
{
    generateRandomColors();
    newBitmap();
    Invalidate(FALSE);
    m_zoomUpWnd->setColorTable(m_colors);
	
	CWnd ::OnRButtonDown(nFlags, point);
}

void CChildView::OnLButtonDown(UINT nFlags, CPoint point) 
{
    m_zoomRect.left = point.x;
    m_zoomRect.top = point.y;
    m_zoomRect.right = point.x+1;
    m_zoomRect.bottom = point.y+1;

    CClientDC dc(this);
    CBrush *pOldBr = (CBrush *) dc.SelectStockObject(NULL_BRUSH);
//    CPen pen(PS_DASH, 1, RGB(0, 0, 0));
//    CPen *pOldPen = (CPen *) dc.SelectObject(&pen);
    int oldROP2 = dc.SetROP2(R2_NOT);
    dc.Rectangle(m_zoomRect);
    dc.SetROP2(oldROP2);
//    dc.SelectObject(pOldPen);
    dc.SelectObject(pOldBr);

	CWnd ::OnLButtonDown(nFlags, point);
}

void CChildView::OnLButtonUp(UINT nFlags, CPoint point) 
{
    if ((point.x > m_zoomRect.left) && (point.y > m_zoomRect.top))
    {
        CRect oldRect(m_zoomRect);
        m_zoomRect.right = point.x;
        m_zoomRect.bottom = point.y;
        if (m_zoomRect.Width() > m_zoomRect.Height())
            m_zoomRect.right = m_zoomRect.left + m_zoomRect.Height();
        else
            m_zoomRect.bottom = m_zoomRect.top + m_zoomRect.Width();
        if (m_zoomRect.Width() > 300)
        {
            m_zoomRect.right = m_zoomRect.left + 300;
            m_zoomRect.bottom = m_zoomRect.top + 300;
        }

        CClientDC dc(this);
        CBrush *pOldBr = (CBrush *) dc.SelectStockObject(NULL_BRUSH);
//        CPen pen(PS_SOLID, 1, RGB(0, 0, 0));
//        CPen *pOldPen = (CPen *) dc.SelectObject(&pen);
        int oldROP2 = dc.SetROP2(R2_NOT);
        dc.Rectangle(oldRect);
//        dc.Rectangle(m_zoomRect);
        dc.SetROP2(oldROP2);
//        dc.SelectObject(pOldPen);
        dc.SelectObject(pOldBr);
        
        double step = m_range / (m_windowDimension-1);
//        TRACE("%d %d %d %d\n", m_zoomRect.left, m_zoomRect.top, m_zoomRect.right, m_zoomRect.bottom);
        m_zoomUpWnd->setMandel(m_centerX-m_range/2.0+m_zoomRect.left*step,
                               m_centerY+m_range/2.0-m_zoomRect.top*step,
                               m_zoomRect.Width()*step,
                               m_currentIteration);
        m_zoomRect = CRect(0,0,0,0);
    }
	
	CWnd ::OnLButtonUp(nFlags, point);
}

void CChildView::OnMouseMove(UINT nFlags, CPoint point) 
{
    if (m_zoomRect != CRect(0,0,0,0))
    {
        if ((point.x > m_zoomRect.left) && (point.y > m_zoomRect.top))
        {
            CRect oldRect(m_zoomRect);
            m_zoomRect.right = point.x;
            m_zoomRect.bottom = point.y;
            if (m_zoomRect.Width() > m_zoomRect.Height())
                m_zoomRect.right = m_zoomRect.left + m_zoomRect.Height();
            else
                m_zoomRect.bottom = m_zoomRect.top + m_zoomRect.Width();
            if (m_zoomRect.Width() > 300)
            {
                m_zoomRect.right = m_zoomRect.left + 300;
                m_zoomRect.bottom = m_zoomRect.top + 300;
            }
            CClientDC dc(this);
            CBrush *pOldBr = (CBrush *) dc.SelectStockObject(NULL_BRUSH);
//            CPen pen(PS_DASH, 1, RGB(0, 0, 0));
//            CPen *pOldPen = (CPen *) dc.SelectObject(&pen);
            int oldROP2 = dc.SetROP2(R2_NOT);
            dc.Rectangle(oldRect);
            dc.Rectangle(m_zoomRect);
            dc.SetROP2(oldROP2);
//            dc.SelectObject(pOldPen);
            dc.SelectObject(pOldBr);
        }
    }
	CWnd ::OnMouseMove(nFlags, point);
}

void CChildView::OnLButtonDblClk(UINT nFlags, CPoint point) 
{
    PostMessage(WM_COMMAND, IDM_PAUSEANIMATION);	
	CWnd ::OnLButtonDblClk(nFlags, point);
}


BOOL CChildView::PreTranslateMessage(MSG* pMsg)
{
    // TODO: 在此加入特定的程式碼和 (或) 呼叫基底類別

    return CWnd::PreTranslateMessage(pMsg);
}


INT_PTR CChildView::OnToolHitTest(CPoint point, TOOLINFO* pTI) const
{
    pTI->hwnd = this->m_hWnd;
//    TRACE("hwnd=%p uID=%x cbSize=%d\n", pTI->hwnd, pTI->uId, pTI->cbSize);
    pTI->lpszText = LPSTR_TEXTCALLBACK;
    pTI->rect.left = point.x-20;
    pTI->rect.right = point.x+20;
    pTI->rect.top = point.y-20;
    pTI->rect.bottom = point.y+20;
    pTI->uId = 2;
    return pTI->uId+rand()%2;
//    return CWnd::OnToolHitTest(point, pTI);
}

BOOL CChildView::OnToolTipNotify(UINT id, NMHDR *pNMHDR, LRESULT *pResult)
{
   // need to handle both ANSI and UNICODE versions of the message
   TOOLTIPTEXTA* pTTTA = (TOOLTIPTEXTA*)pNMHDR;
   TOOLTIPTEXTW* pTTTW = (TOOLTIPTEXTW*)pNMHDR;
   CString strTipText;
   UINT nID = (UINT) pNMHDR->idFrom;
   strTipText.Format("滑鼠左鍵可框選放大區域!");
//   ((CMainFrame *)AfxGetMainWnd())->SetMessageText(strTipText);

   if (pNMHDR->code == TTN_NEEDTEXTA)
      lstrcpyn(pTTTA->szText, strTipText, sizeof(pTTTA->szText));
   else
      ::MultiByteToWideChar( CP_ACP , 0, strTipText, -1, pTTTW->szText, sizeof(pTTTW->szText)/(sizeof pTTTW->szText[0]) );
   *pResult = 0;

   return TRUE;    // message was handled
}

