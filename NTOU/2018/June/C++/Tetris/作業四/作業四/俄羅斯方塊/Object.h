#pragma once

#include "point.h"
class Rect;

class Object{
public:
	Object();
	Object(int color, const Point position, const Point data[4]); // 建構元
	~Object();
	bool move(const Point &offset, const Rect &boundary); // 移動 offset 位移
	int hit(const Rect &rect) const; // 檢查物件是否在矩形區域 rect 中
	void draw(int color) const; // 繪製 (true), 清除 (false)
	void jump(const Rect &rect);
	void rotate(const Rect &boundary);
	void rotateCounter(const Rect &boundary);
	bool getAndDelay(Rect &boundary, Object &next);
	void setPixelTable(Rect &boundary);
	bool getStart(Rect& boundary);
private:
	int m_color;
	Point m_pos;
	Point m_data[4];
};