#include "stdafx.h" 
#include "Complex.h"
#include <iostream>
#include<cassert>
#include<cmath>

using namespace std;

Complex::Complex(void)
	:m_real(0), m_imaginary(0.)
{
}


Complex::~Complex(void)
{
}


void Complex::setValue(double real, double imaginary)
{
	m_real = real;
	m_imaginary = imaginary;
}


void Complex::add(Complex y)
{
	m_real += y.m_real;
	m_imaginary += y.m_imaginary;
}


void Complex::subtract(Complex y)
{
	m_real -= y.m_real;
	m_imaginary -= y.m_imaginary;
}

void Complex::mutiply(Complex y)
{
	double temp = m_real;
	m_real = y.m_real * m_real - (m_imaginary * y.m_imaginary);
	m_imaginary = y.m_real * m_imaginary + temp * y.m_imaginary;
}


bool Complex::divide(Complex y)
{
	if(y.m_real || y.m_real){
		Complex z;
		z.m_real = y.m_real;
		z.m_imaginary = -y.m_imaginary;
		y.mutiply(z);
		mutiply(z);
		m_real /= y.m_real;
		m_imaginary /= y.m_real;
		return true;
	}
	return false;
}


bool Complex::equal(Complex y, double precision)
{
	if(m_real < y.m_real + precision && m_real > y.m_real - precision  && m_imaginary < y.m_imaginary + precision && m_imaginary > y.m_imaginary - precision)
		return true;
	return false;
}

bool Complex::diverge(){
	if(abs(m_real) >= 2 || abs(m_imaginary) >= 2)
		return true;
	return false;
}


void Complex::print()
{
	cout << '(' <<m_real << " + " << m_imaginary << " i)\n";
}

void Complex::uniTest(void)
{
	Complex x1, x2, x3;
    x1.setValue(7, 3);
    x2.setValue(1, 1);
    x3.setValue(5, -2); // (7+3i)/(1+i) = (5-2i)
    assert(x1.divide(x2));
    assert(x1.equal(x3, 1e-10)); // C/C++ 常數 1e-10 代表 1x10-10
	//x2.print();
	//x3.print();
    x2.setValue(0, 0);
    assert(!x1.divide(x2));
	//x2.print();
}

double Complex::magnitude(void)
{
	return sqrt((m_real * m_real + m_imaginary * m_imaginary));
}