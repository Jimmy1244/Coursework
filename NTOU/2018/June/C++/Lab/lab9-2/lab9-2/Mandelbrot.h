// Mandelbrot.h: interface for the Mandelbrot class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MANDELBROT_H__B5AEAA3B_9D8D_484D_AB31_932C210B233F__INCLUDED_)
#define AFX_MANDELBROT_H__B5AEAA3B_9D8D_484D_AB31_932C210B233F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Complex.h"

class Mandelbrot  
{
public:
	int updateData(int ** const &data, int currentIteration);
	void generateData(int ** const &data, int numIterations);
	Mandelbrot(double centerX, double centerY, double range, int windowSize);
	virtual ~Mandelbrot();

private:
	Complex **m_z;
	const double m_range;
    const double m_centerY;
    const double m_centerX;
    const int m_windowSize;
};

#endif // !defined(AFX_MANDELBROT_H__B5AEAA3B_9D8D_484D_AB31_932C210B233F__INCLUDED_)
