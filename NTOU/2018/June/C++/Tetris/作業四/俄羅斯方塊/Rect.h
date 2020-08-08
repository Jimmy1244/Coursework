#pragma once

class Point;
#include "Object.h"

class Rect{
public:
	Rect(const int left, const int top, const int right, const int bottom); //建構元
	~Rect();
	int hit(const Point &pt) const; //判斷是否包含傳入的點
	int hit(const Object &obj) const; //判斷是否包含傳入的整個物件
	void drawBoundary() const; //繪製矩形的邊界
	void setPixelTable(const int x, const int y, const int set);
	void drawPixelTable()const;
	bool isFullLine(const int line)const;
	int countScore();
	void editIntroduce(const int x, const int y, char * str);
	void Teris();
	friend bool Object::getAndDelay(Rect& boundary, Object &next);
	friend bool Object::getStart(Rect& boundary)const;
	friend void Point::draw(const int color)const;
private:
	int m_left, m_top, m_right, m_bottom;
	int **m_pixelTable;
	int m_speed;
	int m_previewFlag;
	bool m_start;
	bool m_gameOver;
	static const int pixelSize = 24;
};