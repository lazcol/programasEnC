/* -------------------------------------------------
    Programa que grafica una función cuadrática de periodo T=b-a
    con parámetros de la serie de Fourier.

    Parámetros que se pueden cambiar:
        A : la amplitud de la señal desde 0.
        a : Límite izquierdo del periodo de la señal (inicio)
        b : Límite derecho del periodo de la señal (final)
        term : la cantidad de términos de fourier que se quiere utilizar
        P : la cantidad de períodos a graficar
        largo : son la cantidad total de puntos a graficar
        Ampli : es una amplificación dependiento los monitores y resoluciones -> hay que probar

Diego Lazcano - Análisis Matemático III - UCEMA
----------------------------------------------------*/

#include <stdlib.h>
#include <stdio.h>
#include <complex.h>
#include <math.h>
#include <graphics.h>
#include <X11/Xlib.h>
 
int main() {

    // ---  DECLARACIÓN DE VARIABLES ---
    int gd = DETECT, gm;    // esto es de la ventana de ploteo
    double A = 1.0;         // La amplitud de la señal triangular
    double a = -1.0;        // Límite izquirdo del periodo de la señal
    double b = 1.0;         // Límite derecho del periodo de la señal
    double T = b-a;         // periodo de la señal
    double f = 1.0/T;       // frecuencia de la señal
    double w = 2*M_PI*f;    // pulsación de la señal
    double a0 ;             // termino independiente de la serie de Fourier
    int term = 10;           // cantidad de términos dependientes de t
    int P = 2 ;             // periodos a graficar
    double Ampli = 150;     // amplificación de la grafica
    double t;               // variable para el vector de tiempos
    int n ;                 // variable para contar en el for
    int largo = 1800 ;      // largo del vector tiempo o cantidad de muestras
    double h1 ;             // variable en donde se guardan los parciales de la serie trigonométrica
    double complex h2 = 0.0+0.0*I ; // variable en donde se guardan los parciales de la serie compleja
    double y ;              // en esta variable guardaremos t² para graficarla
    // --- FIN DE LA DECLARACIÓN DE CARIABLES ---

    initgraph(&gd, &gm, ""); // inicializamos la parte gráfica
    printf("Grafico de una Senal periodica A.t^2 con %d terminos\n\n",term);
    printf("Siendo A=%+.2lf, con una frecuencia f=%.4lf\n\n",A,f);
    printf("definida en el intervalo (a,b) = (%+.2lf,%+.2lf)\n\n",a,b);
    printf("y se grafican en total %d periodos\n\n",P);
    line(0, getmaxy() / 2, getmaxx(), getmaxy() / 2);   // genera la línea de las abcisas

    a0 = 2*A*(pow(b,3)-pow(a,3))/3/T;                   // generación del término independiente a0

    for(t=0.0 ; t<P*T ; t=t+P*T/largo) {                // primer for: cada espacio de tiempo
        h1 = 0.0; h2 = 0.0 + I*0.0; 
        for(n = 1; n <= term; n++) {                    // segundo for : para cada espacio de tiempo, genera los términos solicitados

            h1 = h1 + 4*pow(-1,n)/pow(n,2)/pow(w,2)*cos(n*w*t) ;    // Esta línea es la Serie Trigonométrica de Fourier

            h2 = h2 + 4*pow(-1,n)/pow(n,2)/pow(w,2)*cexp(I*n*w*t) ; // Esta línea es la Serie Compleja de Fourier
        }
        
        putpixel(t*Ampli, getmaxy()/2 - Ampli*(h1+a0/2), 15);       // pone un punto en la gráfica con las coordenadas halladas (Serie Trigonométrica)
        
        putpixel(t*Ampli, getmaxy()/2 - Ampli*(creal(h2)+1.0/3), 5);// pone un punto en la gráfica con las coordenadas halladas (Serie Compleja)

        // Los siguientes 2 if son para reproducir 2 parábolas
        // una centrada en cero como es la original
        // y otra desplazada hacia la derecha un periodo
        // para ver la convergencia
        if(t<=b) {
            y = pow(A*t,2); // Parábola centrada en cero
            putpixel(t*Ampli, getmaxy()/2 - Ampli*y, 9);
        }
        if(t>b && t<=3*b) {
            y = pow(A*t-T/A,2); // Parábola centrada en "b"
            putpixel(t*Ampli, getmaxy()/2 - Ampli*y, 9);
        }
        
    }

    grgetch();      // Espera una entrada exterior : teclado, mouse
    
    closegraph();   // cierra la ventana del gráfico
    
    return 0;       // retorna un int porque la función principal en c es int main() y debe devolver una variable int, en este caso 0
}