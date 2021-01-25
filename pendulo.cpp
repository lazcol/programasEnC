#include <stdlib.h>
#include <stdio.h>
#include <complex.h>
#include <math.h>
#include <iostream>
#include <cmath>
#include <graphics.h>

const float Pi = 3.1415926535897931f;

float angular_disp(float t, float angle, float T) //angular displacement
{
    //Simple Harmonic Motion equation
    float res = angle * cos((2.0*Pi / T) * t); //let additional const be 0
    return res;
}

void animate_pendulum(float x1, float y1,
                      float l, float g, float angle, float T)
{
   int gd = DETECT, gm;
   
   initgraph(&gd, &gm, NULL);

  float angular_acc;  //angular acceleration

  for(float t = 1.0; t < 100.0;)
  {
     float new_angle = angular_disp(t, angle, T);
     angular_acc = -(g/l) * sin(new_angle);

     //To know other end coordinates
     float base = l * cos(new_angle);
     float height = l * sin(new_angle);

     //end coordinates
     float y2 = y1 + base;
     float x2 = x1 + height;

     setlinestyle(DASHED_LINE,0,NORM_WIDTH);
     setcolor(WHITE);
     line(x1, y1-20.0, x1, y1+250.0);

     setlinestyle(SOLID_LINE,0,THICK_WIDTH);
     setcolor(BLUE);
     line(x1, y1, x2, y2);

     setcolor(RED);
     circle(x2, y2, 10);
     floodfill(x2, y2, RED);

     delay(100);
     cleardevice();

     t = t + 1.0;
  }
  delay(100);
  closegraph();
}

int main()
{
   float x1 = 250, y1 = 100; //start coordinates of pendulum

   float l = 200; //length of pendulum
   float g = 10; //acceleration of gravity (assumed)

   float angle = Pi/4; // in radians

   float T = (2 * Pi) * sqrt(l/g); //period of swing

   animate_pendulum(x1, y1, l, g, angle, T);

   return 0;
}

