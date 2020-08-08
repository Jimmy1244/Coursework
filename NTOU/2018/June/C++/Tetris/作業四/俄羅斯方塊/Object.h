#pragma once

#include "point.h"
class Rect;

class Object{
public:
	Object();
	Object(int color, const Point position, const Point data[4]); // �غc��
	~Object();
	bool move(const Point &offset, const Rect &boundary); // ���� offset �첾
	int hit(const Rect &rect) const; // �ˬd����O�_�b�x�ΰϰ� rect ��
	void draw(const int color) const; // ø�s (true), �M�� (false)
	void jump(const Rect &rect);
	void rotate(const Rect &boundary);
	void rotateCounter(const Rect &boundary);
	bool getAndDelay(Rect &boundary, Object &next);
	void setPixelTable(Rect &boundary)const;
	bool getStart(Rect& boundary)const;
private:
	int m_color;
	Point m_pos;
	Point m_data[4];
};