// Mandelbrot.cpp: implementation of the Mandelbrot class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Mandelbrot02.h"
#include "Mandelbrot.h"
#include "Complex.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Mandelbrot::Mandelbrot(double center_X, double center_Y, double ranges)
{
	TRACE("Mandelbrot::Mandelbrot() is called\n");
	centerX = center_X;
	centerY = center_Y;
	range = ranges;
	TRACE("%lf %lf %lf", centerX, centerY, range);
}

void Mandelbrot::generateData(int ** &data, 
                              int windowSize, 
                              int maxIterations)
{
	int i, j;
	if(data != 0){
		for(i =0; i < windowSize; i++)
			delete[] data[i];
		delete[] data;
	}
	Complex c;
	double step = range / (windowSize-1);
	data = new int*[windowSize];
	for(i = 0; i < windowSize; i++){
		data[i] = new int[windowSize];
		for(j = 0; j < windowSize; j++){
			c.setValue(centerX-range/2.0+i*step, centerY+range/2.0-j*step);
			int k;
			Complex z;
			for(k = 0; k < maxIterations; k++){
				z.mutiply(z);
				z.add(c);
				if(z.diverge()){
					break;
				}
			}
			data[i][j] = k;
		}
	}
}

void Mandelbrot::deleteData(int **&data, int windowSize)
{
	int i, j;
	for(i =0; i < windowSize; i++)
		delete[] data[i];
	delete[] data;
}
