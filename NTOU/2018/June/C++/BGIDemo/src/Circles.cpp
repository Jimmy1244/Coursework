#include <graphics.h>

int main()
{
   int x = 320, y = 240, radius;
   initwindow(640, 480, "Concentric Circles", 50, 50);


   for ( radius = 25; radius <= 125 ; radius = radius + 20)
      circle(x, y, radius);

   getch();
   closegraph();
   return 0;
}
