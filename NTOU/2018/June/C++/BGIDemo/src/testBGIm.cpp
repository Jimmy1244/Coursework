#include <graphics.h>

int main(void)
{
    initwindow(400, 300, "First Sample");
    circle(100, 50, 40);
    moveto(0, 100);
    lineto(400, 300);
    moveto(0, 300);
    lineto(400, 100);
    while (!kbhit())
        delay(200);
    closegraph();
    return 0;
}
