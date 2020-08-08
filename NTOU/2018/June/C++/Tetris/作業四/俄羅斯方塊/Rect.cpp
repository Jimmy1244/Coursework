#include "Rect.h"
#include "Object.h"
#include "point.h"
#include "graphics.h"

Rect::Rect(const int left, const int top, const int right, const int bottom)
	:m_left(left), m_top(top), m_right(right), m_bottom(bottom), m_speed(3), m_previewFlag(0), m_start(false), m_gameOver(false)
{ // 建構元
	int i, j;
	m_pixelTable = new int*[bottom - top];
	for(i = 0; i < bottom - top; i++){
		m_pixelTable[i] = new int[right - left];
		for(j = 0; j < right - left; j++){
			m_pixelTable[i][j] = 0;
		}
	}
}

Rect::~Rect(){
	int i;
	for(i = 0; i < m_bottom - m_top; i++){
		delete[] m_pixelTable[i];
	}
	delete[] m_pixelTable;
}

void Rect::drawBoundary()const{//m_left, m_top, m_right, m_bottom;
    initwindow(pixelSize * 40, pixelSize * 30, "First Sample");
	rectangle(m_left * pixelSize - 2, m_top * pixelSize - 1, m_right * pixelSize + 1, (m_bottom) * pixelSize + 1);//左邊-2是除了方塊還要邊線，上面一開始會畫黑
	outtextxy(m_right * pixelSize + 40, m_top * pixelSize + 10, "Use numeric keypad to play:");
	outtextxy(m_right * pixelSize + 80, m_top * pixelSize + 40, "← [4] : left");
	outtextxy(m_right * pixelSize + 80, m_top * pixelSize + 70, "→ [6] : right");
	outtextxy(m_right * pixelSize + 80, m_top * pixelSize + 100, "↓ [2] : down");
	outtextxy(m_right * pixelSize + 80, m_top * pixelSize + 130, "↑ [5,8] : rotate");
	outtextxy(m_right * pixelSize + 40, m_top * pixelSize + 160, "Current speed is 3");//預設為3之後function再改
	//outtextxy(m_right * pixelSize + 135, m_top * pixelSize + 160, str);
	outtextxy(m_right * pixelSize + 80, m_top * pixelSize + 190, "i:increase speed");
	outtextxy(m_right * pixelSize + 80, m_top * pixelSize + 220, "d:decrease speed");
	outtextxy(m_right * pixelSize + 40, m_top * pixelSize + 280, "Press v to preview objects");
	outtextxy(m_right * pixelSize + 40, m_top * pixelSize + 310, "Press q or <ESC> to exit the program");
	outtextxy(m_right * pixelSize + 40, m_top * pixelSize + 340, "Press g to start the game");
	outtextxy(m_right * pixelSize + 40, m_top * pixelSize + 400, "Current score is 0");
	delay(16);
}

int Rect::hit(const Point &pt)const{
	return pt.hit(m_left, m_top, m_right, m_bottom, m_pixelTable);
}

int Rect::hit(const Object &obj)const{
	return obj.hit(*this);
}

void Rect::setPixelTable(int x, int y, int set){
	m_pixelTable[y - m_top][x - m_left] = set;
}


void Rect::drawPixelTable()const{
	int i, j;
	for(i = 0; i < m_bottom - m_top; i++){
		for(j = 0; j < m_right - m_left; j++){
			Point(j + m_left, i + m_top).draw(m_pixelTable[i][j]);
		}
	}
}

bool Rect::isFullLine(const int line)const{
	int i;
	for(i = 0; i < m_right - m_left; i++){
		if(!m_pixelTable[line][i])
			return false;
	}
	return true;
}

int Rect::countScore(){
	int count = 0, i;
	for(i = m_top; i < m_bottom; i++){
		if(isFullLine(i - m_top)){
			int j;
			for(j = i; j > m_top; j--){
				int k;
				for(k = m_left; k < m_right; k++)
					setPixelTable(k, j, m_pixelTable[j-1 - m_top][k - m_left]);
			}
			count++;
		}
	}
	drawPixelTable();
	return count;
}

void Rect::editIntroduce(const int x, const int y, char *str){
	outtextxy(m_right * pixelSize + x, m_top * pixelSize + y, str);
}

void Rect::Teris(){
	const Point shape[6][4] = { {Point(-1,0), Point(0,0), Point(0,1), Point(-1,1)},
								{Point(-1,0), Point(0,0), Point(1,0), Point(1,1)},
								{Point(-1,1), Point(-1,0), Point(0,0), Point(1,0)},
								{Point(-1,0), Point(0,0), Point(1,0), Point(2,0)},
								{Point(-1,0), Point(0,0), Point(0,1), Point(1,1)},
								{Point(-1,1), Point(0,1), Point(0,0), Point(1,0)}};
	const int colorTable[6] = {LIGHTGREEN, LIGHTRED, LIGHTCYAN, LIGHTBLUE, LIGHTMAGENTA, YELLOW};
	int next = rand() % 6;
	delay(16);
	char a = '*';
	int score = 0;
	while(!m_gameOver){//gameNotOver
		int shapeNum = next;
		next = rand() % 6;
		Object obj(colorTable[shapeNum] , Point((m_left + m_right)/2,m_top), shape[shapeNum]);
		int a;
		if(a = obj.hit(*this)){
			outtextxy((m_left) * pixelSize, (m_bottom + 1) * pixelSize, "Game over !!! Press any key to continue!");
				return;
		}
		Object next(colorTable[next] , Point(2,m_top + 3), shape[next]);
		while(!m_start){
			if(!next.getStart(*this)){
				outtextxy((m_left) * pixelSize, (m_bottom + 1) * pixelSize, "Game over !!! Press any key to continue!");
				return;
			}
		}
		obj.draw(colorTable[shapeNum]);
		if(!obj.getAndDelay(*this, next)){
			outtextxy((m_left) * pixelSize, (m_bottom + 1) * pixelSize, "Game over !!! Press any key to continue!");
			return;//game over
		}
		while(true){//objectNotToBottom
			if(obj.hit(*this) == 2)
			{
				//obj.move(Point(0,-1), canvas);//因為此時已超過地板
				obj.setPixelTable(*this);
				score+=countScore();
				break;
			}
			obj.draw(0);
			obj.move(Point(0,1), *this);
			obj.draw(colorTable[shapeNum]);
			if(!obj.getAndDelay(*this, next)){
				outtextxy((m_left) * pixelSize, (m_bottom + 1) * pixelSize, "Game over !!! Press any key to continue!");
				return;//game over
			}
		}
		next.draw(0);
		int tmp = score, divend = 1000, i = 0;
		while(tmp && !(tmp / divend) && divend){
			divend /= 10;
		}
		char str[20];
		while(tmp && divend){
			int num = tmp / divend;
			str[i] = num + '0';
			tmp -= num * divend;
			divend /= 10;
			i++;
		}
		str[i] = '\0';
		editIntroduce(148, 400, str);
		delay(16);
	}
}