#include "Ground.h"
#include "Object.h"


Ground::Ground(const int &left, const int &top, const int &right, const int &bottom)
	:m_left(left), m_top(top), m_right(right), m_bottom(bottom)
{
	m_surface.resize(right - left + 1);
	m_lines.resize(bottom - top + 1, vector<Point*>(right - left + 1));
}


Ground::~Ground(void)
{
}

void Ground::gotoNextLine(const int lower){
	int i;
	for(i = lower; i > m_top; i--){
		m_lines[i] = m_lines[i - 1];
	}
}

int Ground::countScore(){
	int i;
	int count = 0;
	for(i = m_bottom; i > m_top; i--){
		if(isFullLine(i)){
			gotoNextLine(i);
			count++;
		}
	}
	return count;//Åýrect¨Ó¥[score
}

bool Ground::isFullLine(const int line){
	int i;
	for(i = 0; i < m_right - m_left + 1; i++){
		if(m_lines[line][i] == 0)
			return false;
	}
	return true;
}

void Ground::getPoint(const int x, const int y){
	
}