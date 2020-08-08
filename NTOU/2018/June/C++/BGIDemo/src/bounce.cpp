//
// Project Name: Bouncing Ball
//
// Author: Matthew Weathers
// Modified by: Pei-yih Ting for WinBGIm and devcpp 4.9.9.2
//
// Date  : 14-Oct-2004

#include <time.h>
#include <graphics.h>

using namespace std;

#define ESC 0x1b

int main()
{
	bool KeepGoing=true;
	char KeyPressed;

	int ballX, ballY;
	int prevX, prevY;
	int XVel, YVel;

	// Initial Position
	ballX = 100;
	ballY = 40;

	// Initial Velocity
	XVel = 10;
	YVel = 15;

	srand((unsigned int)time(NULL));  // Seed the random number generator
    initwindow(800, 600, "Bounding Balls", 100, 100); // Start Window

	//Main Loop
	while ( KeepGoing )
    {
		delay( 50 );
        outtextxy(320, 550, "Press q or ESC to exit!");

		// Remember previous position
		prevX = ballX;
		prevY = ballY;

		// Move the ball (Add Velocity to Position)
		ballX += XVel;
		ballY += YVel;

		// Erase old Ball
		setcolor(BLACK);
        setfillstyle(EMPTY_FILL, BLACK); // see getfillsettings()
		fillellipse(prevX, prevY, 40, 40);

		// Draw New ball
		setcolor(YELLOW);
        setfillstyle(SOLID_FILL, YELLOW); // see getfillsettings()
		fillellipse(ballX, ballY, 40, 40);

		// Bounch off left/right walls
		if ( ballX > 760  || ballX < 40) {
			XVel *= -1;
		}

		// Bounch off top/bottom walls
		if ( ballY > 560  || ballY < 40) {
			YVel *= -1;
		}

		// Check to see if a key has been pressed
		if (kbhit()) {
			KeyPressed = getch();

			if ((KeyPressed == 'q')||
                (KeyPressed == ESC)) {  // q or <ESC> - quit
				KeepGoing = false;
			}

		}//end if kbhit()

	} // end while kbhit

	//getch(); //Wait for a key. (When main function ends, the window will close)
	closegraph();
	return 0;
} //end of main()
