#pragma once

#include "point.h"
class Rect;
#include "utilwin32.h"
#include "conio.h"

class Object{
public:
	Object();
	Object(const char face, const Point position, const Point data[4]); // �غc��
	~Object();
	bool move(const Point &offset, const Rect &boundary); // ���� offset �첾
	int hit(const Rect &rect) const; // �ˬd����O�_�b�x�ΰϰ� rect ��
	void draw(const char face) const; // ø�s (true), �M�� (false)
	void jump(const Rect &rect);
private:
	char m_face;
	Point m_pos;
	Point m_data[4];
};