#include "graphics.h"
//#include <graphics.h>

#include <conio.h>

int main(void)
{
    initwindow(400, 300, "First Sample");
    circle(100, 50, 40);
    moveto(0, 100);
    lineto(400, 300);
    moveto(0, 300);
    lineto(400, 100);
	setfillstyle(SOLID_FILL, LIGHTCYAN);
	bar(100, 150, 300, 250);
	setcolor(WHITE); // ¥Õ¦â
	rectangle(100, 150, 300, 250); // left, top, right, bottom
    while (!kbhit())
        delay(200);
    closegraph();
    return 0;
}