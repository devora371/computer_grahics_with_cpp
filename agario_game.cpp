#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <dos.h>
#include <math.h>
void main()
{
   int gdriver=DETECT,gmode,errorcode;
   initgraph(&gdriver, &gmode, "C:\\TurboC3\\BGI");
   Play_Again:
   int angle[]={0,45,-45,90,135,-135,180,270};
   int midx,midy,maxx,maxy,x[3],y[3],ix[3],iy[3],left,i=0,c=0,jj=0,gg=0;
   int poly[16],poly1[16],poly2[16],poly3[16],poly4[16],poly5[16];
   int foodx[100],foody[100],k[3],cx[3],cy[3],yo[3];
   int dx,dy,dr,px=0,py=0,key,dir=0,plx=15,ply=15;
   int j[3],cnt[2],drct[]={1,2,3,4,5,6,7,8};
   float r=7.0;
   char msg[50];
   midx=getmaxx()/2;
   midy=getmaxy()/2;
   maxx=getmaxx();
   maxy=getmaxy();
   for(i=0;i<=2;i++)
   {
     x[i]=midx;
     y[i]=midy;
     iy[i]=0;
     ix[i]=0;
     k[i]=0;
     cx[i]=midx;
     cy[i]=midy;
   }
   left=100;
   c=40;
   for(i=0;i<100;i++)
   {
     foodx[i]=random(maxx/c)*c+20;
     foody[i]=random(maxy/c)*c+20;
   }
   for(i=0;i<=2;i++)
   {
     cnt[i]=0;
     yo[i]=0;
     j[i]=0;
   }
   poly[0]=midx-5;
   poly[1]=midy;
   poly[2]=midx-5;
   poly[3]=midy+20;
   poly[4]=midx+5;
   poly[5]=midy+20;
   poly[6]=midx+5;
   poly[7]=midy;
   poly[8]=midx+10;
   poly[9]=midy;
   poly[10]=midx;
   poly[11]=midy-10;
   poly[12]=midx-10;
   poly[13]=midy;
   poly[14]=midx-10;
   poly[15]=midy;

   poly2[0]=midx-5;
   poly2[1]=midy;
   poly2[2]=midx-5;
   poly2[3]=midy+20;
   poly2[4]=midx+5;
   poly2[5]=midy+20;
   poly2[6]=midx+5;
   poly2[7]=midy;
   poly2[8]=midx+10;
   poly2[9]=midy;
   poly2[10]=midx;
   poly2[11]=midy-10;
   poly2[12]=midx-10;
   poly2[13]=midy;
   poly2[14]=midx-10;
   poly2[15]=midy;

   poly4[0]=midx-5;
   poly4[1]=midy;
   poly4[2]=midx-5;
   poly4[3]=midy+20;
   poly4[4]=midx+5;
   poly4[5]=midy+20;
   poly4[6]=midx+5;
   poly4[7]=midy;
   poly4[8]=midx+10;
   poly4[9]=midy;
   poly4[10]=midx;
   poly4[11]=midy-10;
   poly4[12]=midx-10;
   poly4[13]=midy;
   poly4[14]=midx-10;
   poly4[15]=midy;

   do
   {
    setcolor(RED);
    line(2,2,2,maxy-2);
    line(2,2,maxx-2,2);
    line(maxx-2,maxy-2,maxx-2,2);
    line(maxx-2,maxy-2,2,maxy-2);
    if(kbhit())
    {
      key=getch()+getch();
      if(key==64)
      {
       exit(1);
      }
      else if(key==72)
      {
	py-=10;
	dir=1;
      }
      else if(key==80)
      {
	py+=10;
	dir=2;
      }
      else if(key==75)
      {
	px-=10;
	dir=3;
      }
      else if(key==77)
      {
	px+=10;
	dir=4;
      }
    }
    else
    {
      if(dir==1)
      {
	py-=15;
      }
      else if(dir==2)
      {
	py+=15;
      }
      else if(dir==3)
      {
	px-=15;
      }
      else if(dir==4)
      {
	px+=15;
      }
    }

    for(i=0;i<100;i++)
    {
      setfillstyle(1,GREEN);
      setcolor(GREEN);
      circle(foodx[i],foody[i],2);
    }
    for(i=0;i<=2;i++)
    {
      if(cnt[i]<=15)
      {
	cnt[i]=cnt[i]+1;
	yo[i]=j[i];
      }
      else
      {
	cnt[i]=0;
	again:
	j[i]=random(8)+1;
	gg=yo[i]%2;
	jj=j[i]%2;
	if(gg==1&&jj==0)
	{
	  if(yo[i]==j[i]-1)
	  {
	    goto again;
	  }
	}
	else if(gg==0&&jj==1)
	{
	  if(yo[i]==j[i]+1)
	  {
	    goto again;
	  }
	}
	switch(drct[j[i]-1])
	{
	  case 1:
	  {
	    ix[i]=-15;
	    iy[i]=0;
	    k[i]=7;
	  }
	  break;
	  case 2:
	  {
	    ix[i]=15;
	    iy[i]=0;
	    k[i]=3;
	  }
	  break;
	  case 3:
	  {
	    ix[i]=0;
	    iy[i]=-15;
	    k[i]=0;
	  }
	  break;
	  case 4:
	  {
	    ix[i]=0;
	    iy[i]=15;
	    k[i]=6;
	  }
	  break;
	  case 5:
	  {
	    ix[i]=-15;
	    iy[i]=-15;
	    k[i]=2;
	  }
	  break;
	  case 6:
	  {
	    ix[i]=15;
	    iy[i]=15;
	    k[i]=4;
	  }
	  break;
	  case 7:
	  {
	    ix[i]=-15;//12 34 56 78
	    iy[i]=15;
	    k[i]=5;
	  }
	  break;
	  case 8:
	  {
	    ix[i]=15;
	    iy[i]=-15;
	    k[i]=1;
	  }
	  break;
	}
      }
    }
   /*
   setfillstyle(1,RED);
   setcolor(RED);
   pieslice(x[0],y[0],0,360,17);
   pieslice(x[1],y[1],0,360,17);
   pieslice(x[2],y[2],0,360,17);
   */
   setfillstyle(1,CYAN);
   setcolor(CYAN);
   pieslice(plx+px,ply+py,0,360,r);

   poly[10]=poly[10]+ix[0];
   poly[11]=poly[11]+iy[0];
   poly[0]=poly[10]-5;
   poly[1]=poly[11]+10;
   poly[2]=poly[10]-5;
   poly[3]=poly[11]+30;
   poly[4]=poly[10]+5;
   poly[5]=poly[11]+30;
   poly[6]=poly[10]+5;
   poly[7]=poly[11]+10;
   poly[8]=poly[10]+10;
   poly[9]=poly[11]+10;
   poly[12]=poly[10]-10;
   poly[13]=poly[11]+10;
   poly[14]=poly[10]-5;
   poly[15]=poly[11]+10;

   cx[0]=poly[10];
   cy[0]=poly[11];
   for(i=0;i<=15;i=i+2)
   {
     poly1[i]=poly[i]*cos(angle[k[0]]*M_PI/180)-poly[i+1]*sin(angle[k[0]]*M_PI/180)-cx[0]*cos(angle[k[0]]*M_PI/180)+cy[0]*sin(angle[k[0]]*M_PI/180)+cx[0];//+cy*cy*floor(sin(90*M_PI/180));
     poly1[i+1]=poly[i]*sin(angle[k[0]]*M_PI/180)+poly[i+1]*cos(angle[k[0]]*M_PI/180)-cx[0]*sin(angle[k[0]]*M_PI/180)-cy[0]*cos(angle[k[0]]*M_PI/180)+cy[0];//-cy*cy*floor(cos(90*M_PI/180));
   }
   setcolor(RED);
   setfillstyle(1,RED);
   fillpoly(8,poly1);

   poly2[10]=poly2[10]+ix[1];
   poly2[11]=poly2[11]+iy[1];
   poly2[0]=poly2[10]-5;
   poly2[1]=poly2[11]+10;
   poly2[2]=poly2[10]-5;
   poly2[3]=poly2[11]+30;
   poly2[4]=poly2[10]+5;
   poly2[5]=poly2[11]+30;
   poly2[6]=poly2[10]+5;
   poly2[7]=poly2[11]+10;
   poly2[8]=poly2[10]+10;
   poly2[9]=poly2[11]+10;
   poly2[12]=poly2[10]-10;
   poly2[13]=poly2[11]+10;
   poly2[14]=poly2[10]-5;
   poly2[15]=poly2[11]+10;
   cx[1]=poly2[10];
   cy[1]=poly2[11];

   for(i=0;i<=15;i=i+2)
   {
     poly3[i]=poly2[i]*cos(angle[k[1]]*M_PI/180)-poly2[i+1]*sin(angle[k[1]]*M_PI/180)-cx[1]*cos(angle[k[1]]*M_PI/180)+cy[1]*sin(angle[k[1]]*M_PI/180)+cx[1];//+cy*cy*floor(sin(90*M_PI/180));
     poly3[i+1]=poly2[i]*sin(angle[k[1]]*M_PI/180)+poly2[i+1]*cos(angle[k[1]]*M_PI/180)-cx[1]*sin(angle[k[1]]*M_PI/180)-cy[1]*cos(angle[k[1]]*M_PI/180)+cy[1];//-cy*cy*floor(cos(90*M_PI/180));
   }
   setcolor(RED);
   setfillstyle(1,RED);
   fillpoly(8,poly3);

   poly4[10]=poly4[10]+ix[2];
   poly4[11]=poly4[11]+iy[2];
   poly4[0]=poly4[10]-5;
   poly4[1]=poly4[11]+10;
   poly4[2]=poly4[10]-5;
   poly4[3]=poly4[11]+30;
   poly4[4]=poly4[10]+5;
   poly4[5]=poly4[11]+30;
   poly4[6]=poly4[10]+5;
   poly4[7]=poly4[11]+10;
   poly4[8]=poly4[10]+10;
   poly4[9]=poly4[11]+10;
   poly4[12]=poly4[10]-10;
   poly4[13]=poly4[11]+10;
   poly4[14]=poly4[10]-5;
   poly4[15]=poly4[11]+10;

   cx[2]=poly4[10];
   cy[2]=poly4[11];
   for(i=0;i<=15;i=i+2)
   {
     poly5[i]=poly4[i]*cos(angle[k[2]]*M_PI/180)-poly4[i+1]*sin(angle[k[2]]*M_PI/180)-cx[2]*cos(angle[k[2]]*M_PI/180)+cy[2]*sin(angle[k[2]]*M_PI/180)+cx[2];//+cy*cy*floor(sin(90*M_PI/180));
     poly5[i+1]=poly4[i]*sin(angle[k[2]]*M_PI/180)+poly4[i+1]*cos(angle[k[2]]*M_PI/180)-cx[2]*sin(angle[k[2]]*M_PI/180)-cy[2]*cos(angle[k[2]]*M_PI/180)+cy[2];//-cy*cy*floor(cos(90*M_PI/180));
   }
   setcolor(RED);
   setfillstyle(1,RED);
   fillpoly(8,poly5);
   for(i=0;i<=2;i++)
   {
     x[i]=cx[i];
     y[i]=cy[i];
   }
   if(poly[10]<=0)
   {
     poly[10]=maxx;
   }
   else if(poly[10]>=maxx)
   {
     poly[10]=0;
   }
   if(poly[11]<=0)
   {
     poly[11]=maxy;
   }
   else if(poly[11]>=maxy)
   {
     poly[11]=0;
   }
   if(poly2[10]<=0)
   {
     poly2[10]=maxx;
   }
   else if(poly2[10]>=maxx)
   {
     poly2[10]=0;
   }
   if(poly2[11]<=0)
   {
     poly2[11]=maxy;
   }
   else if(poly2[11]>=maxy)
   {
     poly2[11]=0;
   }
   if(poly4[10]<=0)
   {
     poly4[10]=maxx;
   }
   else if(poly4[10]>=maxx)
   {
     poly4[10]=0;
   }
   if(poly4[11]<=0)
   {
     poly4[11]=maxy;
   }
   else if(poly4[11]>=maxy)
   {
     poly4[11]=0;
   }
   for(i=0;i<=2;i++)
   {
     dx=x[i]-(plx+px-4);
     dy=y[i]-(ply+py-4);
     if(dx<=0)
       dx=-dx;
     if(dy<=0)
       dy=-dy;
     if(dx<=dr&&dy<=dr)
     {
       delay(900);
       left=-1;
     }
   }
   for(i=0;i<100;i++)
   {
     if(((foodx[i]-(plx+px))<=r)&&((foodx[i]-(plx+px))>=-r))
     {
       if(((foody[i]-(ply+py))<=r)&&((foody[i]-(ply+py))>=-r))
       {
	 foodx[i]=-100;
	 foody[i]=-100;
	 r=r+0.15;
	 left-=1;
       }
     }
   }
   dr=r+10;
   setcolor(15);
   sprintf(msg,"Left: %d",left);
   outtextxy(maxx-80,20,msg);
   if((plx+px)<=11)
   {
     px=0+11;
   }
   else if((plx+px)>=(maxx-40))
   {
     px=maxx-45;
   }
   if((ply+py)<=11)
   {
     py=0+11;
   }
   else if((ply+py>=maxy-40))
   {
     py=maxy-45;
   }
   for(i=0;i<=2;i++)
   {
     if(x[i]>maxx)
     {
       x[i]=0;
     }
     else if(x[i]<0)
     {
       x[i]=maxx;
     }
     if(y[i]>maxy)
     {
       y[i]=0;
     }
     else if(y[i]<0)
     {
       y[i]=maxy;
     }
   }
   delay(100);
   cleardevice();
   }while(left>=1);

   cleardevice();
   if(left==0)
   {
     settextstyle(4,0,5);
     setcolor(WHITE);
     sprintf(msg,"Agario");
     outtextxy(midx-110,midy-80,msg);
     settextstyle(1,0,2);
     setcolor(BROWN);
     sprintf(msg,"Congrats,you Win");
     outtextxy(midx-135,midy-10,msg);
     settextstyle(2,0,6);
     setcolor(GREEN);
     sprintf(msg,"Press Enter to play again...");
     outtextxy(150,midy+20,msg);
     if((getch()==13))
     {
       goto Play_Again;
     }
   }
   else
   {
     settextstyle(4,0,5);
     setcolor(WHITE);
     sprintf(msg,"Agario");
     outtextxy(midx-110,midy-80,msg);
     settextstyle(1,0,3);
     setcolor(RED);
     sprintf(msg,"Fail...!");
     outtextxy(midx-90,midy,msg);
     settextstyle(2,0,6);
     setcolor(GREEN);
     sprintf(msg,"Press Enter to play again...");
     outtextxy(150,midy+30,msg);
     if((getch()==13))
     {
       goto Play_Again;
     }
   }
   getch();
   closegraph();
}