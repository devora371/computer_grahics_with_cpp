#include <iostream.h>
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <dos.h>
int main()
{
   int gdriver = DETECT, gmode, errorcode;
   int midx, midy;
   initgraph(&gdriver, &gmode, "");
   midx = getmaxx() / 2;
   midy = getmaxy() / 2;
   int n=0;
   int c=3;
   do{
   int a=n*(137.5*M_PI/180);
   int r=c*sqrt(n);
   int x=r*cos(a)+midx;
   int y=r*sin(a)+midy;
   setcolor(r%15);
   putpixel(x,y,random(15)+1);
   delay(5);
   n++;
   }while(!kbhit());
   getch();
   closegraph();
   return 0;
}
