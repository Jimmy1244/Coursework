#include<cassert>
#include<iostream>

#include "utilwin32.h"
#include "Object.h"
#include "Rect.h"
#include "point.h"

int main()
{
    const int orgX = 10, orgY = 5, width = 25, height = 16;
    const Rect canvas(orgX, orgY, orgX+width-1, orgY+height-1);

    clrscr();
	gotoxy(orgX + 2, 2);
	std::cout<< "Press Esc to Stop!!";
	gotoxy(orgX + 2, 3);
	std::cout<< "Press p to pause/ontinue!!\n";
    canvas.draw();

    const Point shape[4] = { Point(-1,0), Point(0,0), 
                             Point(0,1), Point(-1,1) };
	char a = '*';
    Object obj(a, Point(orgX+width/2-1,orgY + 1), shape);
    assert(obj.hit(canvas) != -1);

    obj.jump(canvas);
    gotoxy(orgX,26); system("pause");
}