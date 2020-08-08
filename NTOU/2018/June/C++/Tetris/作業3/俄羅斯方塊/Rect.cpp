#include<iostream>

#include "utilwin32.h"
#include "Rect.h"
#include "Object.h"

using namespace std;

Rect::Rect(const int left, const int top, const int right, const int bottom)
	:m_left(left), m_top(top), m_right(right), m_bottom(bottom)
{ // �غc��
}

void Rect::draw()const{
    int i;
    gotoxy(m_left-1, m_top-1);
    cout << '+';
    for (i=0; i<m_right; i++)
        cout << '-';
    cout << '+';

    for (i=0; i<m_bottom; i++)
    {
        gotoxy(m_left-1, m_top+i); cout << '|';
        gotoxy(m_left+m_right, m_top+i); cout << '|';
    }

    gotoxy(m_left-1, m_top+m_bottom);
    cout << '+';
    for (i=0; i<m_right; i++)
        cout << '-';
    cout << '+';
    gotoxy(1,23); // ���в��ʨ�������T�w���a��, 
              // �_�h�b�e���W�|�@���ݨ��Цb���P�a��{�ڰ{��
}

int Rect::hit(const Point &pt)const{
	return pt.hit(m_left, m_top, m_left + m_right - 1, m_top + m_bottom - 1);
}

int Rect::hit(const Object &obj)const{
	return obj.hit(*this);
}