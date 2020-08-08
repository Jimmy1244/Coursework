#pragma once

class Point;
#include "Object.h"

class Rect{
public:
	Rect(const int left, const int top, const int right, const int bottom); //�غc��
	~Rect();
	int hit(const Point &pt) const; //�P�_�O�_�]�t�ǤJ���I
	int hit(const Object &obj) const; //�P�_�O�_�]�t�ǤJ����Ӫ���
	void drawBoundary() const; //ø�s�x�Ϊ����
	void setPixelTable(int x, int y, int set);
	void drawPixelTable();
	bool isFullLine(int line);
	int countScore();
	void editIntroduce(int x, int y, char * str);
	void Teris();
	friend bool Object::getAndDelay(Rect& boundary, Object &next);
	friend bool Object::getStart(Rect& boundary);
	friend void Point::draw(int color)const;
private:
	int m_left, m_top, m_right, m_bottom;
	int **m_pixelTable;
	int m_speed;
	int m_previewFlag;
	bool m_start;
	bool m_gameOver;
	static const int pixelSize = 32;
};