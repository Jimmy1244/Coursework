#include "Object.h"
#include "Rect.h"
#include "graphics.h"

Object::Object()
{
}

Object::Object(int color, const Point position, const Point data[4]) // 建構元
	:m_color(color),m_pos(position)
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
	Point tmp = m_pos;
	m_pos = m_pos + offset;
	int hitFlag = hit(boundary);
	if(hitFlag == -1){//撞到左右
		m_pos = tmp;
		return false;
	}
	else if(hitFlag == 2){//撞到下面或新地板
		return false;
	}
	return true;
}


int Object::hit(const Rect &rect) const{
	int i;
	int allSide = 0;
	for(i = 0; i < 4; i++){
		int side = rect.hit(m_data[i] + m_pos);
		if(side == -1)
			return -1;
		else if(side == 2)
			allSide = 2;
	}
	return allSide;
}

void Object::draw(const int color)const{
	int i;
	for(i = 0; i < 4; i++){
		(m_data[i] + m_pos).draw(color);
	}
}

void Object::rotate(const Rect &boundary){
	int i;
	draw(0);
	for(i = 0; i < 4; i++){
		m_data[i].rotate();
	}
	if(hit(boundary) == -1){
		for(i = 0; i < 4; i++){
			m_data[i].rotateCounter();
		}
	}
	draw(m_color);
	delay(16);
}

void Object::rotateCounter(const Rect &boundary){
	int i;
	draw(0);
	for(i = 0; i < 4; i++){
		m_data[i].rotateCounter();
	}
	if(hit(boundary) == -1){
		for(i = 0; i < 4; i++){
			m_data[i].rotate();
		}
	}
	draw(m_color);
	delay(16);
}

bool Object::getAndDelay(Rect &boundary, Object &next){
	if(boundary.m_previewFlag)
		next.draw(next.m_color);
	char str[20];
	int i;
	for(i = 0; i < 20; i++){
		if(kbhit()){
			char a = getch();
			if(a == 27 || a == 'q')
				return false;
			if(a == 'p'){
				boundary.editIntroduce(40, 250, "Press p to continue");
				while(1){
					char b = getch();
					if(b == 'p'){
						boundary.editIntroduce(40, 250, "Press p to pause    ");
						break;
					}
					else if(b == 27 || a == 'q')
						return false;
				}
			}
			else {
				switch(a) {
				case KEY_LEFT://左
				case '4':
					draw(0);
					move(Point(-1,0), boundary);
					draw(m_color);
					delay(16);
					break;
				case KEY_UP://上
				case '8':
					rotate(boundary);
					break;
				case '5':
					rotateCounter(boundary);
					break;
				case KEY_RIGHT://右
				case '6':
					draw(0);
					move(Point(1,0), boundary);						
					draw(m_color);
					delay(16);
					break;
				case KEY_DOWN://下
				case '2':
					if(hit(boundary) != 2){
						draw(0);
						while(move(Point(0,1), boundary));
						draw(m_color);
						delay(16);
					}
					break;
				case 'i':
					if(boundary.m_speed < 9){
						boundary.m_speed++;
						str[0] = boundary.m_speed + '0';
						str[1] = '\0';
						boundary.editIntroduce(150, 160, str);
					}
					break;
				case 'd':
					if(boundary.m_speed > 1){
						boundary.m_speed--;
						str[0] = boundary.m_speed + '0';
						str[1] = '\0';
						boundary.editIntroduce(150, 160, str);
					}
					break;
				case 'v':
					if(boundary.m_previewFlag){
						boundary.editIntroduce(40, 280, "Press v to preview objects ");
						next.draw(0);
					}
					else {
						boundary.editIntroduce(40, 280, "Press v to disable preview");
						next.draw(next.m_color);
					}
					boundary.m_previewFlag = !boundary.m_previewFlag;
					break;
				default:
					break;
				}
			}
		}
		else 
			delay(30 - boundary.m_speed * 2);
	}
	return true;
}

void Object::setPixelTable(Rect &boundary)const{
	int i;
	for(i = 0; i < 4; i++){
		(m_data[i] + m_pos).setPixelTable(boundary, m_color);
	}
}

bool Object::getStart(Rect& boundary)const{
	if(kbhit()){
		char ch = getch();
		switch (ch){
		case 'v':
			if(boundary.m_previewFlag) {
				boundary.editIntroduce(40, 280, "Press v to preview objects ");
				draw(0);
			}
			else {
				boundary.editIntroduce(40, 280, "Press v to disable preview");
				draw(m_color);
			}
			boundary.m_previewFlag = !boundary.m_previewFlag;
			break;
		case 'g':
			boundary.editIntroduce(40, 340, "                                                     ");
			boundary.editIntroduce(40, 250, "Press p to pause");
			boundary.m_start = true;
			break;
		case 27:
		case 'q':
			boundary.m_gameOver = true;
			return false;
		}
	}
	return true;
}