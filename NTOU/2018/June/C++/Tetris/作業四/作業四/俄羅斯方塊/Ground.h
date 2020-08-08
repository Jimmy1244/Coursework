#pragma once

#include "point.h"
#include<vector>

using namespace std;

class Ground
{
public:
	Ground(const int &left, const int &top, const int &right, const int &bottom);
	~Ground(void);
	void gotoNextLine(const int lower);
	int countScore();
	bool isFullLine(const int line);
	void getPoint(int x, int y);
	void draw(const int lower);
private:
	int m_left, m_top, m_right, m_bottom;
	int m_pointNum;
	vector<Point> m_points;
	vector<vector<Point*> >m_lines;//最下面一層為m_line[bottom - top + 1]
	vector<Point*>m_surface;
};