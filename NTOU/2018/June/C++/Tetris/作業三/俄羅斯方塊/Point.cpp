#include "point.h"

Point::Point(){
}

Point::Point(const int x, const int y)
	:m_x(x), m_y(y)
{
}

Point::~Point(){
}

int Point::hit(const int left, const int top, const int right, const int bottom)const{
	if(m_x < left || m_x > right || m_y < top || m_y > bottom)
		return -1;
	else if(m_x == right && m_y == bottom)
		return 3;
	else if(m_x == left && m_y == bottom)
		return 3;
	else if(m_x == left && m_y == top)
		return 3;
	else if(m_x == right && m_y == top)
		return 3;
	else if(m_x == left)
		return 1;
	else if(m_y == top)
		return 2;
	else if(m_x == right)
		return 1;
	else if(m_y == bottom)
		return 2;
	return 0;
}

Point Point::operator+(const Point &rhs)const{
	Point res(m_x+rhs.m_x, m_y+rhs.m_y);
	return res;
}

void Point::draw(const char face)const{
	gotoxy(m_x, m_y);
	std::cout << face;
}

void Point::changeDIR(int dir){
	if(dir == 1)
		m_x = -m_x;
	else if (dir == 2)
		m_y = -m_y;
	else if (dir == 3){
		m_y = -m_y;
		m_x = -m_x;
	}
}