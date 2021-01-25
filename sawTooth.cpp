/* -------------------------------------------------
    Programa que grafica una función diente de sierra
    con parámetros de la serie de Fourier.

    Parámetros que se pueden cambiar:
        A : la amplitud de la señal desde 0.
        T : el periodo de la señal. Tiempo de un ciclo.
        term : la cantidad de términos de fourier que se quiere utilizar
        P : la cantidad de períodos a graficar
        largo : son la cantidad total de puntos a graficar
        Ampli : es una amplificación dependiento los monitores y resoluciones -> hay que probar

Diego Lazcano - Análisis III - UCEMA
----------------------------------------------------*/

#include <stdlib.h>
#include <stdio.h>
#include <complex.h>
#include <iostream>
#include <cmath>
#include <math.h>
#include <graphics.h>
//#include <X11/Xlib.h>
 
int main() {
    int gd = DETECT, gm;    // esto es de la ventana de ploteo
    double A = 1.0;         // La amplitud de la señal triangular
    double T = 1.0;         // periodo de la señal
    double f = 1.0/T;       // frecuencia de la señal
    double w = 2*M_PI*f;    // pulsación de la señal
    int term = 5;          // cantidad de términos dependientes de t
    int P = 5;              // periodos a graficar
    double Ampli = 100;      // amplificación de la grafica
    double t;               // variable para el vector de tiempos
    int n ;                 // variable para contar en el for
    int largo = 1800;       // largo del vector tiempo o cantidad de muestras
    double h1;               // variable en donde se guardan los parciales de la funcion
    double complex h2 ; 

    initgraph(&gd, &gm, ""); // inicializamos la parte gráfica
    printf("Grafico de Senial Diente de Sierra con %d terminos",term);
    line(0, getmaxy() / 2, getmaxx(), getmaxy() / 2);   // genera la línea de las abcisas

    for(t=0.0 ; t<P*T ; t=t+P*T/largo) {                // primer for: cada espacio de tiempo
        h1 = 0.0; h2 = 0.0 + I*0.0; 
        for(n = 1; n <= term; n++) {                    // segundo for : para cada espacio de tiempo, genera los términos solicitados

            h1 = h1 -2*A/T/n/w*sin(n*w*t) ;               // Esta línea sería la Serie Trigonométrica de Fourier

            h2 = h2 -2*A/T/n/w/2*cexp(-I*n*w*t) ;
        }
        putpixel(t*Ampli, getmaxy()/2 - Ampli*(h1+A/2), 15); // pone un punto en la gráfica con las coordenadas halladas
        //printf(" %+.2f \t %+.2f \n",t,h+A/2);  // para probar la función antes de imprimir
    }

    grgetch();      // Espera una entrada exterior : teclado, mouse
    closegraph();   // cierra la ventana del gráfico
    return 0;       // retorna un int porque la función principal en c es int main() y debe devolder una int, en este caso 0
}