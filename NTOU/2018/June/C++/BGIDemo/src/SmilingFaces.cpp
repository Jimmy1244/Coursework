#include <graphics.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

int around(int left[2], int top[2], int temp1, int temp2);

int main(void)
{
   int area, temp1, temp2, left[2] = {25, 425}, top[2] = {75, 280};
   void *p;
   srand(time(0));
   initwindow(640, 480, "Smiling Faces", 150, 150);

   setcolor(YELLOW);
   circle(50,100,25);
   setfillstyle(SOLID_FILL,YELLOW);
   floodfill(50,100,YELLOW);

   setcolor(BLACK);
   setfillstyle(SOLID_FILL,BLACK);
   fillellipse(44,85,2,6);
   fillellipse(56,85,2,6);

   ellipse(50,100,205,335,20,9);
   ellipse(50,100,205,335,20,10);
   ellipse(50,100,205,335,20,11);

   area = imagesize(left[0], top[0], left[0] + 50, top[0] + 50);
   p = malloc(area);
   getimage(left[0], top[0], left[0] + 50, top[0] + 50, p);
   putimage(left[1], top[1], p, XOR_PUT);

   setcolor(WHITE);
   settextstyle(SANS_SERIF_FONT,HORIZ_DIR,2);
   outtextxy(195,451,"Smiling Face Animation");

   setcolor(BLUE);
   rectangle(0,0,639,449);

   while(!kbhit())
   {
      do
      {
          temp1 = 1 + rand()%588;
          temp2 = 1 + rand()%380;
      }
      while (!around(left, top, temp1, temp2));

      getimage(left[1], top[1], left[1] + 50, top[1] + 50, p);
      putimage(left[1], top[1], p, XOR_PUT);
      putimage(temp1 , temp2, p, XOR_PUT);
      delay(350);
      left[1] = left[0]; top[1] = top[0];
      left[0] = temp1; top[0] = temp2;
   }

   free(p);
   getch();
   closegraph();
   return 0;
}

int around(int left[2], int top[2], int temp1, int temp2)
{
    int i;
    for (i=0; i<2; i++)
        if ( (abs(temp1-left[i])<=50) &&
             (abs(temp2-top[i])<=50) )
            return 0;
    return 1;
}
