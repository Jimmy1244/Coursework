// cl /GX SineGraph.cpp libbgi.lib gdi32.lib comdlg32.lib uuid.lib oleaut32.lib ole32.lib user32.lib
// bgi SineGraph.cpp

// devcpp, -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32 

#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>
#define PI 3.14159

void main(void)
{
    int i, ix, iy;
    double x, y;

    initwindow(640, 480, "Sine", 100, 100);
    
    line(0,240, 640,240);
    line(320,0, 320,480);

    ix = (x=-PI)/PI * 319 + 320;
    iy = sin(x) * 239 + 240 + 0.5;
    moveto(ix,iy);
    for (i=-318; i<=319; i++)
    {
        x = PI / 319 * i;
        y = sin(x);
        ix = i + 320;
        iy = y * 239 + 240 + 0.5;
        lineto(ix, iy);
    }

    getch();

    closegraph();
}
