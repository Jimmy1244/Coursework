#pragma once

#include<iostream>

#include "utilwin32.h"

//class Rect;

class Point{
public:
	Point();
	Point(const int x, const int y);
	~Point();
	Point operator+(const Point &rhs)const;
	int hit(const int left, const int top, const int right, const int bottom)const;// �P�_�I�O�_�b�ǤJ���x�ΰ϶���
	void draw(const char face)const;
	void changeDIR(bool dir);
private:
	int m_x, m_y;
};