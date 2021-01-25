#include <stdlib.h>
#include <stdio.h>
#include <complex.h>
#include <iostream>
#include <cmath>
#include <math.h>
#include <graphics.h>
#include <X11/Xlib.h>
//#include <dos.h>
 
int main() {
    double __complex h2;
    int gd = DETECT, gm; // esto es de la ventana de ploteo
    double A = 1.0; // La amplitud de la señal triangular
    double T = 1.0; // periodo de la señal
    double f = 1.0/T; // frecuencia de la señal
    double w = 2*M_PI*f; // pulsación de la señal
    int term = 2; // cantidad de términos dependientes de t
    int P = 3; // periodos a graficar
    double Ampli = 100; // amplificación de la grafica
    double j; // variable para el vector de tiempos
    int k ; // variable para contar en el for
    int largo = 600.0; // largo del vector tiempo o cantidad de muestras
    double h; // variable en donde se guardan los parciales de la funcion
    double x,y; // para las coordenadas del gráfico
     
    initgraph(&gd, &gm, ""); // inicializamos la parte gráfica

    line(0, getmaxy() / 2, getmaxx(), getmaxy() / 2);
    for(j=0.0 ; j<P*T ; j=j+P*T/largo) {
        h = 0.0;
        for(k = 1; k <= term; k++) {
            h = h -4.0*A/pow(M_PI,2)/pow((2*k-1),2) * cos((2*k-1)*w*j) ;
        }
        putpixel(j*Ampli, getmaxy()/2 - Ampli*(h+A/2), 15); 
        //printf(" %+.2f \t %+.2f \n",j,h+A/2);  // para probar la función antes de imprimir
    }

    getch();
    // closegraph();
    return (0);
}