#include "point.h"
#include "graphics.h"
#include "Rect.h"

Point::Point(){
}

Point::Point(const int x, const int y)
	:m_x(x), m_y(y)
{
}

Point::~Point(){
}

int Point::hit(const int left, const int top, const int right, const int bottom, int **ground)const{
	if(m_x < left || m_x > right - 1 || m_y >= bottom || m_y < top || ground[m_y - top][m_x - left])//right-1因為每一格圖片是由左往右畫，m_y >= bottom都不可以，碰到底部是bottom - 1
		return -1;
	else if(m_y == bottom - 1 || ground[m_y - top + 1][m_x - left])//加一往下看一格
		return 2;
	return 0;
}

Point Point::operator+(const Point &rhs)const{
	Point res(m_x+rhs.m_x, m_y+rhs.m_y);
	return res;
}

void Point::draw(const int color)const{
	if(color){
		setfillstyle(SOLID_FILL, color);
		//bar(m_x * pixelSize, m_y * pixelSize + 1, (m_x * pixelSize) + pixelSize, (m_y * pixelSize) - pixelSize);
		bar(m_x * Rect::pixelSize, m_y * Rect::pixelSize, (m_x * Rect::pixelSize) + Rect::pixelSize - 1, (m_y * Rect::pixelSize) + Rect::pixelSize - 1);
		setcolor(WHITE);
		//rectangle(m_x * pixelSize, m_y * pixelSize - 1, (m_x * pixelSize) + pixelSize, (m_y * pixelSize) - pixelSize + 1);
		rectangle(m_x * Rect::pixelSize, m_y * Rect::pixelSize, (m_x * Rect::pixelSize) + Rect::pixelSize - 1, (m_y * Rect::pixelSize) + Rect::pixelSize - 1);
	}
	else{
		setfillstyle(SOLID_FILL, 0);
		//bar(m_x * pixelSize - 1, m_y * pixelSize + 1, (m_x * pixelSize) + pixelSize + 1, (m_y * pixelSize) - pixelSize - 1);
		bar(m_x * Rect::pixelSize, m_y * Rect::pixelSize, (m_x * Rect::pixelSize) + Rect::pixelSize, (m_y * Rect::pixelSize) + Rect::pixelSize);
	}
}

void Point::changeDIR(bool dir){
	if(dir == 0)
		m_x = -m_x;
	else
		m_y = -m_y;
}

void Point::rotate(){
	int tmp = m_x;
	m_x = -m_y;
	m_y = tmp + 1;
}

void Point::rotateCounter(){
	int tmp = m_x;
	m_x = m_y - 1;
	m_y = -tmp;
}

void Point::setPixelTable(Rect &boundary, int color)const{
	boundary.setPixelTable(m_x, m_y, color);
}