#pragma once

class Rect;

class Point{
public:
	Point();
	Point(const int x, const int y);
	~Point();
	Point operator+(const Point &rhs)const;
	int hit(const int left, const int top, const int right, const int bottom, int **ground)const;// �P�_�I�O�_�b�ǤJ���x�ΰ϶���
	void draw(const int color)const;
	void changeDIR(bool dir);
	void rotate();
	void rotateCounter();
	void setPixelTable(Rect &boundary, int color)const;
private:
	int m_x, m_y;
};