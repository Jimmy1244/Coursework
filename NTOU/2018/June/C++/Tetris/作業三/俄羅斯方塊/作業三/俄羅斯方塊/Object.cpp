#include "Object.h"
#include "Rect.h"

Object::Object()
{
}

Object::Object(const char face, const Point position, const Point data[4]) // «Øºc¤¸
	:m_face(face),m_pos(position)
{
	int i;
	for(i = 0; i < 4; i++){
		m_data[i] = data[i];
	}
}

Object::~Object()
{
}

bool Object::move(const Point &offset, const Rect &boundary){
	int i;
	for(i = 0; i < 4; i++){
		(m_pos+m_data[i]).draw(' ');
	}
	m_pos = m_pos + offset;
	for(i = 0; i < 4; i++){
		(m_pos+m_data[i]).draw(m_face);
	}
	return false;
}

int Object::hit(const Rect &rect) const{
	int i;
	for(i = 0; i < 4; i++){
		int reflect = rect.hit(m_data[i] + m_pos);
		if(reflect > 0)
			return reflect;
	}
	return 0;
}

void Object::draw(char face)const{
	int i;
	for(i = 0; i < 4; i++){
		(m_data[i] + m_pos).draw(face);
	}
}

void Object::jump(const Rect &rect){
	draw(m_face);
	Point dir(-1, 1);
	int i = 1;
	while(i){
		if(kbhit()){
			char a = getch();
			if(a == 27)
				return;
			if(a == 'p')
				while(1){
					char b = getch();
					if(b == 'p')
						break;
					else if(b == 27)
						return;
				}
		}
		switch(hit(rect)){
		case 0:
			break;
		case 1:
			dir.changeDIR(1);
			break;
		case 2:
			dir.changeDIR(2);
			break;
		case 3:
			dir.changeDIR(3);
			break;
		default:
			i = 0;
			break;
		}
		move(dir, rect);
		gotoxy(1,26);
		delay(50);
	}
}