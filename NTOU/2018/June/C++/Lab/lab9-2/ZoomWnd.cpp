// ZoomWnd.cpp : implementation file
//

#include "stdafx.h"
#include "Mandelbrot03.h"
#include "ZoomWnd.h"
#include "Mandelbrot.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CZoomWnd

CZoomWnd::CZoomWnd(int size, sBGR colors[])
    : m_windowDimension(size),
      m_pBmpMandel(0)
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
    for (i=0; i<256; i++)
        m_colors[i] = colors[i];
}

CZoomWnd::~CZoomWnd()
{
    delete m_pBmpMandel;
    int i;
    if (m_data)
    {
        for (i=0; i<m_windowDimension; i++)
            delete[] m_data[i];
        delete[] m_data;
    }
}

BEGIN_MESSAGE_MAP(CZoomWnd, CWnd)
	//{{AFX_MSG_MAP(CZoomWnd)
	ON_WM_PAINT()
	ON_WM_CLOSE()
	ON_WM_DESTROY()
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CZoomWnd message handlers

void CZoomWnd::setColorTable(sBGR colors[])
{
    int i;
    for (i=0; i<256; i++)
        m_colors[i] = colors[i];
    Invalidate(FALSE);
}

void CZoomWnd::OnPaint() 
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

void CZoomWnd::newBitmap()
{
    int width=m_windowDimension;
    int height=m_windowDimension;

	pBGR mandelLine = (pBGR) m_mandel;
	int stepX, stepY;
	for (stepY=height-1; stepY>=0; stepY--) 
    {
		for (stepX=0; stepX<width; stepX++) 
            mandelLine[stepX] = m_colors[255-m_data[stepX][stepY]];
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

void CZoomWnd::setMandel(double left, 
                         double top, 
                         double width, int maxIterations)
{
    Mandelbrot mandel(left+width/2.0, 
                      top-width/2.0,
                      width, 300);
    CWaitCursor wait;
    mandel.generateData(m_data, maxIterations);
    Invalidate(FALSE);
}

void CZoomWnd::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
	return;
	CWnd::OnClose();
}

void CZoomWnd::OnDestroy() 
{
	CWnd::OnDestroy();
}

int CZoomWnd::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	
	return 0;
}
