#include <stdlib.h>
#include <graphics.h>
#include <time.h>

int main(void)
{
   int i = 0, key, num, midx, gd = DETECT, gm;
   char a[10];

   initwindow(640, 480, "Captcha", 50, 50);

   midx = getmaxx()/2;

   settextstyle(SCRIPT_FONT,HORIZ_DIR,5);
   settextjustify(CENTER_TEXT,CENTER_TEXT);
   setcolor(YELLOW);
   outtextxy(midx,30,"CAPTCHA");
   settextstyle(SCRIPT_FONT,HORIZ_DIR,2);
   outtextxy(midx,125,"Press any key to change the generated random code \"captcha\"");
   outtextxy(midx,150,"Press escape key to exit...");

   setcolor(WHITE);
   setviewport(100,200,600,400,1);
   setcolor(WHITE);
   srand(time(0L));

   while(1)
   {
      while(i<6)
      {
         num = rand()%3;

         if ( num == 0 )
            a[i] = 65 + rand()%26;     /* 65 is the ASCII value of A */
         else if ( num == 1)
            a[i] = 97 + rand()%26;     /* 97 is the ASCII value of a */
         else
            a[i] = 48 + rand()%10;     /* 48 is the ASCII value of 0 */
         i++;
      }
      a[i] = '\0';
      outtextxy(210,100,a);
      key = getch();

      if( key == 27 )                     /* escape key*/
         exit(0);
      clearviewport();
      i = 0;
   }
}
