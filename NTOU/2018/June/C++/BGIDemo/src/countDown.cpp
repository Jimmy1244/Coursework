#include<graphics.h>
#include<conio.h>

int main()
{
   int i;
   char a[5];

   initwindow(640, 480, "Count down", 50, 50);

   settextjustify( CENTER_TEXT, CENTER_TEXT );
   settextstyle(DEFAULT_FONT,HORIZ_DIR,6);
   setcolor(YELLOW);

   for(i = 5 ; i >=0 ; i--)
   {
      sprintf(a,"%d",i);
      outtextxy(getmaxx()/2, getmaxy()/2, a);
      delay(1000);

      if ( i == 0 )
         break;
      cleardevice();
   }

   getch();
   closegraph();
   return 0;
}
