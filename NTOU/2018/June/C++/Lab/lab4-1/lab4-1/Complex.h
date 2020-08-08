#pragma once
class Complex
{
public:
	Complex(void);
	~Complex(void);
private:
	double m_real;
	double m_imaginary;
public:
	void setValue(double real, double imaginary);
	void multiply(Complex y);
	void add(Complex y);
	bool equal(Complex y, double precision);
	float magnitude(void);
	void print(void);
};

