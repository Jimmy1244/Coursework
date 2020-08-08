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
	void add(Complex y);
	void subtract(Complex y);
	void mutiply(Complex y);
	bool divide(Complex y);
	bool equal(Complex y, double precision);
	bool diverge();
	void print();
	static void uniTest(void);
	double magnitude(void);
};

