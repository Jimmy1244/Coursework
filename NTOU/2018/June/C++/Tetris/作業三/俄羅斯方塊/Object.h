#pragma once

#include "point.h"
class Rect;
#include "utilwin32.h"
#include "conio.h"

class Object{
public:
	Object();
	Object(const char face, const Point position, const Point data[4]); // 建構元
	~Object();
	bool move(const Point &offset, const Rect &boundary); // 移動 offset 位移
	int hit(const Rect &rect) const; // 檢查物件是否在矩形區域 rect 中
	void draw(const char face) const; // 繪製 (true), 清除 (false)
	void jump(const Rect &rect);
private:
	char m_face;
	Point m_pos;
	Point m_data[4];
};