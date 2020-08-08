#pragma once

#include "point.h"
class Object;
//#include "Object.h"

class Rect{
public:
	Rect(const int left, const int top, const int right, const int bottom); //建構元
	int hit(const Point &pt) const; //判斷是否包含傳入的點
	int hit(const Object &obj) const; //判斷是否包含傳入的整個物件
	void draw() const; //繪製矩形的邊界
private:
	int m_left, m_top, m_right, m_bottom;
};