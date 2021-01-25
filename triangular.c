#include <stdlib.h>
#include <stdio.h>
#include <complex.h>
#include <math.h>
#include <graphics.h>
#include <X11/Xlib.h>
 
int main() {
    double __complex__ h2;
    int gd = DETECT, gm; // esto es de la ventana de ploteo
    double A = 1.0; // La amplitud de la señal triangular
    double T = 1.0; // periodo de la señal
    double f = 1.0/T; // frecuencia de la señal
    double w = 2*M_PI*f; // pulsación de la señal
    int term = 15; // cantidad de términos dependientes de t
    int P = 3; // periodos a graficar
    double Ampli = 200; // amplificación de la grafica
    double j; // variable para el vector de tiempos
    int k ; // variable para contar en el for
    int largo = 600.0; // largo del vector tiempo o cantidad de muestras
    double h; // variable en donde se guardan los parciales de la funcion
    //double x,y; // para las coordenadas del gráfico
     
    initgraph(&gd, &gm, ""); // inicializamos la parte gráfica
    printf("Grafico de una Senal triangular A.t con %d terminos\n\n",term);
    printf("con una amplitud A=%+.2lf, con una frecuencia f=%.2lf Hz\n\n",A,f);
    printf("y se grafican en total %d periodos\n\n",P);

    line(0, getmaxy() / 2, getmaxx(), getmaxy() / 2);
    for(j=0.0 ; j<P*T ; j=j+P*T/largo) {
        h = 0.0;
        h2 = 0.0 + I*0.0;
        for(k = 1; k <= term; k++) {
            h = h -4.0*A/pow(M_PI,2)/pow((2*k-1),2) * cos((2*k-1)*w*j) ; // Serie Trigonométrica de Fourier

            h2 = h2-4.0*A/pow(M_PI,2)/pow((2*k-1),2) * cexp(I*(2*k-1)*w*j); // Serie Compleja de Fourier
        }
        putpixel(j*Ampli, getmaxy()/2 - Ampli*(h+A/2), 15);  // Serie trigonométrica de Fourier
        putpixel(j*Ampli, getmaxy()/2 - Ampli*(h2+A/2), 5);  // Serie Compleja de Fourier
        //printf(" %+.2f \t %+.2f \n",j,h+A/2);  // para probar la función antes de imprimir
    }

    getch();
    // closegraph();
    return (0);
}