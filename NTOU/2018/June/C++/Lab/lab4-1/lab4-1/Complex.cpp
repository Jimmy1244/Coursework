#include<iostream>

#include "Complex.h"

Complex::Complex(void)
	: m_real(0)
	, m_imaginary(0)
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


void Complex::multiply(Complex y)
{
	double tmp = m_real;
	m_real = m_real * y.m_real - m_imaginary * y.m_imaginary;
	m_imaginary = tmp * y.m_imaginary + y.m_real * m_imaginary;
}


void Complex::add(Complex y)
{
	m_real += y.m_real;
	m_imaginary += y.m_imaginary;
}


bool Complex::equal(Complex y, double precision)
{
	if(m_real < y.m_real + precision && m_real > y.m_real - precision && m_imaginary < y.m_imaginary + precision && m_imaginary > y.m_imaginary - precision)
			return true;
	return false;
}


float Complex::magnitude(void)
{
	return m_real*m_real + m_imaginary * m_imaginary;
}

void Complex::print(void)
{
	std::cout << '(' << m_real << " + " << m_imaginary << ") i\n";
}
