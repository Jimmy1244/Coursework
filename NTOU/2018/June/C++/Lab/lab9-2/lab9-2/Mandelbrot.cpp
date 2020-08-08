// Mandelbrot.cpp: implementation of the Mandelbrot class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Mandelbrot03.h"
#include "Mandelbrot.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Mandelbrot::Mandelbrot(double centerX, double centerY, double range,
                       int windowSize):m_range(range), m_centerX(centerX), m_centerY(centerY), m_windowSize(windowSize)
{
	int i;
	m_z = new Complex*[windowSize];
	for(i = 0; i < windowSize; i++){
		m_z[i] = new Complex[windowSize];
	}
}

Mandelbrot::~Mandelbrot()
{
	int i;
	for(i = 0; i < m_windowSize; i++){
		delete[] m_z[i];
	}
	delete[] m_z;
}

void Mandelbrot::generateData(int ** const &data, //一次到numIterations
                              int numIterations)
{
	int i, j;
	Complex c;
	double step = m_range / (m_windowSize-1);
	for(i = 0; i < m_windowSize; i++){
		for(j = 0; j < m_windowSize; j++){
			int k;
			c.setValue(m_centerX-m_range/2.0+i*step, m_centerY+m_range/2.0-j*step);
			data[i][j] = 0;
			for(k = 0; k < numIterations; k++){
				m_z[i][j].mutiply(m_z[i][j]);
				m_z[i][j].add(c);
				if(m_z[i][j].diverge()){
					data[i][j] = k;
					break;
				}
			}
		}
	}
}

int Mandelbrot::updateData(int ** const &data, 
                           int currentIteration)//呼叫一次算一步
{
	int i, j, count = 0;
	Complex c;
	double step = m_range / (m_windowSize-1);
	for(i = 0; i < m_windowSize; i++){
		for(j = 0; j < m_windowSize; j++){
			if(data[i][j] == 0){
				c.setValue(m_centerX-m_range/2.0+i*step, m_centerY+m_range/2.0-j*step);
				m_z[i][j].mutiply(m_z[i][j]);
				m_z[i][j].add(c);
				if(m_z[i][j].diverge()){
					data[i][j] = currentIteration + 1;
					count++;
				}
			}
		}
	}
    return count;
}
