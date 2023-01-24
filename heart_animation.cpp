#include <graphics.h>
#include <conio.h>
#include <math.h>
#include <dos.h>
#include <stdlib.h>

int main()
{
    int x,y,r,midx,midy,color;
    float t;
    int gdriver=DETECT,gmode,errorcode;
    initgraph(&gdriver, &gmode, "C:\\TurboC3\\BGI");
    midx=getmaxx()/2;
    midy=getmaxy()/2;
    r=10;
    color=15;
    setcolor(15);
    setfillstyle(1, 15);
    settextstyle(0,0,3);
    do
    {
        outtextxy(midx-35,35,"<I>");
        outtextxy(midx-150,midy+100,"<PROGRAMMING>");
        for(t=0;t<(2*M_PI);t+=0.01)
        {
            x=(r*16*sin(t)*sin(t)*sin(t))+midx;
            y=(r*(1-2)*(13*cos(t)-5*cos(2*t)-2*cos(3*t)-cos(4*t)))+(midy-30);
            pieslice(x,y,0,360,5);
        }
        floodfill(midx,midy,color);
        delay(500);
        cleardevice();
        color=random(15)+1;
        setcolor(color);
        setfillstyle(1,color);
    }
    while(!kbhit());
    getch();
    colosegraph();
    return 0;
}
