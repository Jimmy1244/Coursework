// cl /GX SineCount.cpp libbgi.lib gdi32.lib comdlg32.lib uuid.lib oleaut32.lib ole32.lib user32.lib
// bgi SineCount.cpp

// devcpp, -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32 

#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <graphics.h>

#define PI 3.141592

void main(void)
{
    int i, iCount[50], max;
    double x;
    char   strBuf[20];

    initwindow(640, 480, "Sine Count", 100, 100);

    for (i=0; i<50; i++)
        iCount[i] = 0;

    for (x=0; x<=PI; x+=0.001)
        for (i=0; i<50; i++)
            if (sin(x)<=(i+1)*0.02)
            {
                iCount[i]++;
                break;
            }

    max = 0;
    for (i=0; i<50; i++)
        if (iCount[i]>max)
            max = iCount[i];

    for (i=0; i<50; i++)
        iCount[i] = iCount[i]/((double)max)*460.0;

    line(40,460, 630,460);
    outtextxy(620, 470, "50");

    line(40,460, 40,0);

    for (i=0; i<5; i++)
    {
        sprintf(strBuf, "%4d",(int)(max/4.0*i));
        outtextxy(1, 460-i*460/4.0, strBuf);
    }

    moveto(40, 460-iCount[0]);
    for (i=1; i<50; i++)
        lineto(40+i/49.0*600, 460-iCount[i]);

    getch();

    closegraph();
}
