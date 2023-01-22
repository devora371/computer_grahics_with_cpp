/*
		       ********* ASTRO GAME *********

		      Use: Right Arrow key to move right
			   Left Arrow key to move left
			   Upper Arrow to Fire
			   Esc+Esc to exit
*/
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <dos.h>
#include <math.h>
void main()
{
Play_Again:
  int gdriver=DETECT,gmode,errorcode;
  int i,j,count,score,gx,rc,key,midx,maxx,maxy,midy;
  int ix[5],iy[5],cx[5],cy[5],k[5],gunc[5],colorG[5],poly[20],gunx[20],guny[20],pg1x[20],pg1y[20],pg2x[20],pg2y[20];
  int poly1[14],poly2[14],poly3[14],poly4[14],poly5[14],
      poly6[14],poly7[14],poly8[14],poly9[14],poly10[14];
  int angle[]={0,45,90,135,180,-135,270,-45};
  char msg[20];
  initgraph(&gdriver, &gmode, "C:\\TurboC3\\BGI");
  midx=getmaxx()/2;
  midy=getmaxy()/2;
  maxx=getmaxx();
  maxy=getmaxy();
  gx=midx;
  rc=10;
  count=0;
  score=0;
  for(i=0;i<20;i++)
  {
   gunx[i]=NULL;
   guny[i]=NULL;
  }
  for(i=0;i<5;i++)
  {
   ix[i]=random(maxx-80)+40;
   iy[i]=2;
   k[i]=random(8);
   gunc[i]=0;
   colorG[i]=15;
  }

  poly[0]=gx;
  poly[1]=getmaxy()-120;

  poly1[0]=ix[0];
  poly1[1]=random(150)*(1-2);

  poly3[0]=ix[1];
  poly3[1]=random(150)*(1-2);

  poly5[0]=ix[2];
  poly5[1]=random(150)*(1-2);

  poly7[0]=ix[3];
  poly7[1]=random(150)*(1-2);

  poly9[0]=ix[4];
  poly9[1]=random(150)*(1-2);

  do
  {
   if(kbhit())
   {
     key=getch()+getch();
     if(key==75)            //Left Arrow key
       gx-=8;
     else if(key==77)       //Right Arrow key
       gx+=8;
     else if(key==54)       //Esc+Esc key
END:   break;
     else if(key==72)       //Up Arrow key
     {
       for(i=0;i<20;i++)
       {
	 if(gunx[i]==NULL)
	 {
	  sound(500);
	  delay(20);
	  nosound();
	  gunx[i]=poly[0];
	  guny[i]=poly[1];
	  setcolor(RED);
	  line(gunx[i],guny[i],gunx[i],guny[i]+15);
	  break;
	 }
       }
     }
   }

  poly1[0]=ix[0];
  poly1[1]=poly1[1]+iy[0];

  poly1[2]=poly1[0]+30;
  poly1[3]=poly1[1]+20;

  poly1[4]=poly1[0]+20;
  poly1[5]=poly1[1]+45;

  poly1[6]=poly1[0]-20;
  poly1[7]=poly1[1]+45;

  poly1[8]=poly1[0]-30;
  poly1[9]=poly1[1]+20;

  poly1[10]=poly1[0];
  poly1[11]=poly1[1];

  poly1[12]=poly1[0];
  poly1[13]=(poly1[1]+poly1[7])/2;

  cx[0]=poly1[12];
  cy[0]=poly1[13];

  for(i=0;i<=13;i=i+2)        //For Obstacle Rotation
  {
    poly2[i]=poly1[i]*cos(angle[k[0]]*M_PI/180)-poly1[i+1]*sin(angle[k[0]]*M_PI/180)-cx[0]*cos(angle[k[0]]*M_PI/180)+cy[0]*sin(angle[k[0]]*M_PI/180)+cx[0];
    poly2[i+1]=poly1[i]*sin(angle[k[0]]*M_PI/180)+poly1[i+1]*cos(angle[k[0]]*M_PI/180)-cx[0]*sin(angle[k[0]]*M_PI/180)-cy[0]*cos(angle[k[0]]*M_PI/180)+cy[0];
  }

  poly3[0]=ix[1];
  poly3[1]=poly3[1]+iy[1];

  poly3[2]=poly3[0]+25;
  poly3[3]=poly3[1]+20;

  poly3[4]=poly3[0]+20;
  poly3[5]=poly3[1]+45;

  poly3[6]=poly3[0]-20;
  poly3[7]=poly3[1]+45;

  poly3[8]=poly3[0]-25;
  poly3[9]=poly3[1]+20;

  poly3[10]=poly3[0];
  poly3[11]=poly3[1];

  poly3[12]=poly3[0];
  poly3[13]=(poly3[1]+poly3[7])/2;

  cx[1]=poly3[12];
  cy[1]=poly3[13];

  for(i=0;i<=13;i=i+2)           //For Obstacle Rotation
  {
    poly4[i]=poly3[i]*cos(angle[k[1]]*M_PI/180)-poly3[i+1]*sin(angle[k[1]]*M_PI/180)-cx[1]*cos(angle[k[1]]*M_PI/180)+cy[1]*sin(angle[k[1]]*M_PI/180)+cx[1];
    poly4[i+1]=poly3[i]*sin(angle[k[1]]*M_PI/180)+poly3[i+1]*cos(angle[k[1]]*M_PI/180)-cx[1]*sin(angle[k[1]]*M_PI/180)-cy[1]*cos(angle[k[1]]*M_PI/180)+cy[1];
  }

  poly5[0]=ix[2];
  poly5[1]=poly5[1]+iy[2];

  poly5[2]=poly5[0]+30;
  poly5[3]=poly5[1]+20;

  poly5[4]=poly5[0]+20;
  poly5[5]=poly5[1]+45;

  poly5[6]=poly5[0]-20;
  poly5[7]=poly5[1]+45;

  poly5[8]=poly5[0]-30;
  poly5[9]=poly5[1]+20;

  poly5[10]=poly5[0];
  poly5[11]=poly5[1];

  poly5[12]=poly5[0];
  poly5[13]=(poly5[1]+poly5[7])/2;

  cx[2]=poly5[12];
  cy[2]=poly5[13];

  for(i=0;i<=13;i=i+2)           //For Obstacle Rotation
  {
    poly6[i]=poly5[i]*cos(angle[k[2]]*M_PI/180)-poly5[i+1]*sin(angle[k[2]]*M_PI/180)-cx[2]*cos(angle[k[2]]*M_PI/180)+cy[2]*sin(angle[k[2]]*M_PI/180)+cx[2];
    poly6[i+1]=poly5[i]*sin(angle[k[2]]*M_PI/180)+poly5[i+1]*cos(angle[k[2]]*M_PI/180)-cx[2]*sin(angle[k[2]]*M_PI/180)-cy[2]*cos(angle[k[2]]*M_PI/180)+cy[2];
  }

  poly7[0]=ix[3];
  poly7[1]=poly7[1]+iy[3];

  poly7[2]=poly7[0]+30;
  poly7[3]=poly7[1]+20;

  poly7[4]=poly7[0]+20;
  poly7[5]=poly7[1]+45;

  poly7[6]=poly7[0]-20;
  poly7[7]=poly7[1]+45;

  poly7[8]=poly7[0]-30;
  poly7[9]=poly7[1]+20;

  poly7[10]=poly7[0];
  poly7[11]=poly7[1];

  poly7[12]=poly7[0];
  poly7[13]=(poly7[1]+poly7[7])/2;

  cx[3]=poly7[12];
  cy[3]=poly7[13];

  for(i=0;i<=13;i=i+2)            //For Obstacle Rotation
  {
    poly8[i]=poly7[i]*cos(angle[k[3]]*M_PI/180)-poly7[i+1]*sin(angle[k[3]]*M_PI/180)-cx[3]*cos(angle[k[3]]*M_PI/180)+cy[3]*sin(angle[k[3]]*M_PI/180)+cx[3];
    poly8[i+1]=poly7[i]*sin(angle[k[3]]*M_PI/180)+poly7[i+1]*cos(angle[k[3]]*M_PI/180)-cx[3]*sin(angle[k[3]]*M_PI/180)-cy[3]*cos(angle[k[3]]*M_PI/180)+cy[3];
  }

  poly9[0]=ix[4];
  poly9[1]=poly9[1]+iy[4];

  poly9[2]=poly9[0]+30;
  poly9[3]=poly9[1]+21;

  poly9[4]=poly9[0]+21;
  poly9[5]=poly9[1]+45;

  poly9[6]=poly9[0]-21;
  poly9[7]=poly9[1]+45;

  poly9[8]=poly9[0]-30;
  poly9[9]=poly9[1]+21;

  poly9[10]=poly9[0];
  poly9[11]=poly9[1];

  poly9[12]=poly9[0];
  poly9[13]=(poly9[1]+poly9[7])/2;

  cx[4]=poly9[12];
  cy[4]=poly9[13];

  for(i=0;i<=13;i=i+2)            //For Obstacle Rotation
  {
    poly10[i]=poly9[i]*cos(angle[k[4]]*M_PI/180)-poly9[i+1]*sin(angle[k[4]]*M_PI/180)-cx[4]*cos(angle[k[4]]*M_PI/180)+cy[4]*sin(angle[k[4]]*M_PI/180)+cx[4];
    poly10[i+1]=poly9[i]*sin(angle[k[4]]*M_PI/180)+poly9[i+1]*cos(angle[k[4]]*M_PI/180)-cx[4]*sin(angle[k[4]]*M_PI/180)-cy[4]*cos(angle[k[4]]*M_PI/180)+cy[4];
  }

  settextstyle(0,0,2);
  setcolor(WHITE);
  sprintf(msg," %d",score);
  outtextxy(maxx-55,20,msg);

  //Draws Rotating Obstacles.....
  setfillstyle(1,colorG[0]);
  setcolor(colorG[0]);
  fillpoly(6,poly2);

  setfillstyle(1,colorG[1]);
  setcolor(colorG[1]);
  fillpoly(6,poly4);

  setfillstyle(1,colorG[2]);
  setcolor(colorG[2]);
  fillpoly(6,poly6);

  setfillstyle(1,colorG[3]);
  setcolor(colorG[3]);
  fillpoly(6,poly8);

  setfillstyle(1,colorG[4]);
  setcolor(colorG[4]);
  fillpoly(6,poly10);


  //FighterPlane co-ordinates:
  poly[0]=gx;
  poly[1]=poly[1];

  poly[2]=poly[0]-20;
  poly[3]=poly[1]+50;

  poly[4]=poly[0]-15;
  poly[5]=poly[1]+65;

  poly[6]=poly[0]-5;
  poly[7]=poly[1]+65;

  poly[8]=poly[0]-3;
  poly[9]=poly[1]+75;

  poly[10]=poly[0]+3;
  poly[11]=poly[1]+75;

  poly[12]=poly[0]+5;
  poly[13]=poly[1]+65;

  poly[14]=poly[0]+15;
  poly[15]=poly[1]+65;

  poly[16]=poly[0]+20;
  poly[17]=poly[1]+50;

  poly[18]=poly[0];
  poly[19]=poly[1];

  //draw FighterPlane
  setcolor(BLUE);
  setfillstyle(1,BLUE);
  fillpoly(10,poly);
  setcolor(RED);
  setfillstyle(1,RED);
  pieslice(poly[0],maxy-30,0,360,rc);

  //Draws gun and check for Collision Detection
  for(i=0;i<20;i++)
  {
   if(gunx[i]!=NULL)
   {
    guny[i]=guny[i]-10;
    setcolor(RED);
    line(gunx[i],guny[i],gunx[i],guny[i]+15);

    for(j=0;j<=4;j++)
    {
     if(((gunx[i]>=(cx[j]-25))&&(gunx[i]<=(cx[j]+25)))&&((guny[i]>=(cy[j]-25))&&(guny[i]<=(cy[j]+25))))
     {
      sound(1000);
      delay(40);
      nosound();
      gunx[i]=NULL;
      guny[i]=NULL;
      gunc[j]=gunc[j]+1;
      colorG[j]=6;
      if(gunc[j]>=2)
	colorG[j]=4;
      if(gunc[j]==4)
      {
       colorG[j]=15;
       gunc[j]=0;
       ix[j]=random(maxx-80)+40;
       if(j==0)
	poly1[1]=random(150)*(1-2);
       else if(j==1)
	poly3[1]=random(150)*(1-2);
       else if(j==2)
	poly5[1]=random(150)*(1-2);
       else if(j==3)
	poly7[1]=random(150)*(1-2);
       else if(j==4)
	poly9[1]=random(150)*(1-2);
       score+=1;
      }
     }
    }
    if(guny[i]<0)
    {
     gunx[i]=NULL;
     guny[i]=NULL;
    }
   }
  }

  count++;
  if(count==2)
    count=0;
  if(count==0)
  {
   for(i=0;i<=4;i++)
     k[i]+=1;
   if(rc==10)
     rc=15;
   else
     rc=10;
  }
  if(cy[0]>=maxy)
  {
   colorG[0]=15;
   gunc[0]=0;
   ix[0]=random(maxx-80)+40;
   poly1[1]=random(150)*(1-2);
  }
  if(cy[1]>=maxy)
  {
   colorG[1]=15;
   gunc[1]=0;
   ix[1]=random(maxx-80)+40;
   poly3[1]=random(150)*(1-2);
  }
  if(cy[2]>=maxy)
  {
   colorG[2]=15;
   gunc[2]=0;
   ix[2]=random(maxx-80)+40;
   poly5[1]=random(150)*(1-2);
  }
  if(cy[3]>=maxy)
  {
   colorG[3]=15;
   gunc[3]=0;
   ix[3]=random(maxx-80)+40;
   poly7[1]=random(150)*(1-2);
  }
  if(cy[4]>=maxy)
  {
   colorG[4]=15;
   gunc[4]=0;
   ix[4]=random(maxx-80)+40;
   poly9[1]=random(150)*(1-2);
  }

  for(i=0;i<=4;i++)
    if(k[i]==8)
      k[i]=0;

  for(i=0;i<=4;i++)
  {
   if(score>=20)
    iy[i]=6;
   else if(score>=15)
    iy[i]=5;
   else if(score>=10)
    iy[i]=4;
   else if(score>=5)
    iy[i]=3;
  }

  //Obstacle and FighterPlane Collision Detection
  for(j=0;j<=4;j++)
  {
   if(((poly[0]>=(cx[j]-40))&&(poly[0]<=(cx[j]+40)))&&((poly[1]>=(cy[j]-40))&&(poly[1]<=(cy[j]+15))))
   {
    sound(1000);
    delay(100);
    sound(800);
    delay(80);
    sound(500);
    delay(100);
    nosound();
    goto END;
   }
  }
  delay(60);
  cleardevice();
  }while(1);

  cleardevice();
  settextstyle(4,0,5);
  setcolor(15);
  sprintf(msg,"Astro");
  outtextxy(midx-110,midy-80,msg);
  settextstyle(1,0,2);
  setcolor(BROWN);
  sprintf(msg,"Your Score is %d",score);
  outtextxy(midx-135,midy-10,msg);
  settextstyle(2,0,6);
  setcolor(GREEN);
  sprintf(msg,"Press Enter to play again...");
  outtextxy(150,midy+20,msg);
  if((getch()==13))          //Press Enter to play.....
  {
   goto Play_Again;
  }
  closegraph();
}