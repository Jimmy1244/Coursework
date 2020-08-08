#pragma once

#include "point.h"
class Object;
//#include "Object.h"

class Rect{
public:
	Rect(const int left, const int top, const int right, const int bottom); //�غc��
	int hit(const Point &pt) const; //�P�_�O�_�]�t�ǤJ���I
	int hit(const Object &obj) const; //�P�_�O�_�]�t�ǤJ����Ӫ���
	void draw() const; //ø�s�x�Ϊ����
private:
	int m_left, m_top, m_right, m_bottom;
};