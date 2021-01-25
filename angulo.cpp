#include <stdlib.h>
#include <stdio.h>
#include <complex.h>
#include <math.h>
#include <iostream>
#include <cmath>
#include <graphics.h>

const float Pi = 3.1415926535897931f;

int main() //angular displacement
{
    float angle = 45.0;
    float T = 2.0*Pi;
    float t = 0.5;
    //Simple Harmonic Motion equation
    float res = angle * cos((2.0*Pi / T) * t); //let additional const be 0
    printf("angulo: \t %+.4f\n\n",res);
    return 0;
}