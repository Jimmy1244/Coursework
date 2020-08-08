#include<graphics.h>
#include<conio.h>

int main(void)
{
   int x, y, color, angle = 0;
   struct arccoordstype a, b;

   initwindow(640, 480, "Circles in Circles", 50, 50);
   delay(200);

   while(angle<=360)
   {
      setcolor(BLACK);
      arc(getmaxx()/2,getmaxy()/2,angle,angle+2,100);
      setcolor(YELLOW);
      getarccoords(&a);
      circle(a.xstart,a.ystart,25);
      setcolor(BLACK);
      arc(getmaxx()/2,getmaxy()/2,angle,angle+2,150);
      getarccoords(&a);
      setcolor(12);
      circle(a.xstart,a.ystart,25);
      angle = angle+5;
      delay(50);
   }

   getch();
   closegraph();
   return 0;
}
