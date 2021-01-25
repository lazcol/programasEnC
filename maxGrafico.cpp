#include<graphics.h>
// #include<conio.h>
#include<stdio.h>

int main()
{
   int gd = DETECT, gm, X, Y;
   char a[100];
   
   initgraph(&gd,&gm,"");

   X = getmaxx();
   Y = getmaxy();

   sprintf(a, "Maximum X and Y coordinates for current graphics mode and driver are %d and %d respectively.", X, Y);
   outtext(a);
   
   getch();
   closegraph();
   return 0;
}