#include<cassert>
#include<iostream>
#include<ctime>
#include "graphics.h"
#include "Rect.h"
#include "Object.h"
#include "point.h"

//#include "utilwin32.h"
/*#include "Object.h"
#include "Rect.h"
#include "point.h"*/

int main()//bug :�q����I��ground�S�P�_��A�s��Ū������A������
{
	srand((unsigned)time(NULL));
	const int orgX = 6, orgY = 2, width = 16, height = 24;
	Rect canvas(orgX, orgY, orgX + width, orgY + height);
	canvas.drawBoundary();
	canvas.Teris();
	canvas.editIntroduce(40, 280, "                                           ");
	canvas.editIntroduce(40, 310, "                                                            ");
	canvas.editIntroduce(40, 340, "                                         ");
	while(!kbhit());
    closegraph();
	return 0;
}