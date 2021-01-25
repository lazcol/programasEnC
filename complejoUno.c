#include <stdlib.h>
#include <stdio.h>
#include <complex.h>
#include <math.h>


int main(void)
{   double complex z1 = 1.0+3.0*I;
    double complex z2 = 400.0+628.0*I;
    double complex sum,prod,coc;
    double complex a[2][4] = { {1.0+1.0*I, 2.0-2.0*I,}, {-2.0+1.0*I, 4.0+1.0*I}};
    double complex y[2][1] = { {4.0+4.0*I}, {-2.0+2.0*I}};
    double complex arrayProd[2][1];
    int i,j;
    system("clear");
    printf("Números Complejos en C:\n\v");
    printf("Variables inicializadas: z1 = %.2f%+.2fi\tz2 = %.2f%+.2fi\n",creal(z1),cimag(z1),creal(z2),cimag(z2));
    sum = z1 + z2;
    printf("La suma: z1 + z2 = %.2f%+.2fi\n", creal(sum), cimag(sum));
    prod = z1 * z2;
    printf("El producto de z1 x z2 = %.2f%+.2fi\n", creal(prod), cimag(prod));
    coc = z1 / z2;
    printf("El cociente de z1 / z2 = %.2f%+.2fi\n", creal(coc), cimag(coc));
    coc = z2 / z1;
    printf("El cociente de z2 / z1 = %.2f%+.2fi\n", creal(coc), cimag(coc));
    printf("z1 en Amplitud y Fase: %.2f e^(%+.2fi) \n",cabs(z1),carg(z1));
    printf("z2 en Amplitud y Fase: %.2f e^(%+.2fi) \n",cabs(z2),carg(z2));
    printf("El mismo de antes en Amplitud y Fase: %.2f e^(%+.2fi) \n",cabs(coc),carg(coc));
    printf("\nUn coseno complejo:\n");
    printf("coseno de z1 = %+.2f%+.2fi\n\n",ccos(z1));
    printf("que tendría que dar lo mismo que la exponencial compleja:\n");
    printf("el valor de la exponencial compleja es: %.2f%+.2fi\n\n",0.5*cexp(z1*I)+0.5*cexp(-z1*I));
    printf("Ahora un logaritmo como los que no hay en los reales:\n");
    printf("log(-1) = %.2f%+.2fi\n\n",clog(-1));
    printf("Podemos probar la validez de la ecuación más bella\n");
    printf("e^(i pi)+1 = %.2f%+.2fi\n\n",cexp(M_PI*I)+1);
    printf("Elevamos z1² = %.2f%+.2fi\n",cpow(z1,2.0));
    printf("que da lo mismo que z1*z1 = %.2f%+.2fi\n\n",z1*z1);
    printf("Algunas de las básicas conocidas: raíz cuadrada de -1 = %.2f%+.2fi\n\n",csqrt(-1));
    printf("La raíz cuadrada de i = %.2f%+.2fi\n\n",csqrt(I));
    printf("El producto de z1 por z1 conjugado = %.2f%+.2fi \n\n",z1*conj(z1));
    printf("El producto de z1 por el opuesto del conjugado = %.2f%+.2fi\n\n",z1*-conj(z1));
    printf("Supongamos el complejo 1+i, el logaritmo debería ser el logaritmo del modulo + el angulo\n");
    printf("es decir log(2^½)+pi/4i,veamos log(1+i) = %.2f%+.2fi\n\n",clog(1.0+1.0*I));
    printf("\n\nAhora uno con Matrices:\n\n");
    printf("Las definiciones de los arreglos:\n\n");
    // se imprime la matriz a
    printf("La matriz a de 2x2:\n");
    for(i=0; i<2; i++) {
      for(j=0;j<2;j++) {
         printf("%.2f%+.2fi   ", a[i][j]);
         if(j==1){
            printf("\n");
         }
      }
    }
    // se imprime el vector y
    printf("\nEl vector y de 2x1:\n");
    for(i=0; i<2; i++) {
      printf("%.2f%+.2fi \n", y[i][0]);
    }
    // se hace el producto a*y
    sum = 0;
    for (i = 0; i < 2; i++) {
      for (j = 0; j < 2; j++) {
            sum = sum + a[i][j]*y[j][0];
        }
 
        arrayProd[i][0] = sum;
        sum = 0;
    }
    // se imprime el resultado del producto
    printf("\n\nEl vector producto de a*y:\n");
    for(i=0; i<2; i++) {
      printf("%.2f%+.2fi \n", arrayProd[i][0]);
    }
    printf("\nLo único malo es que no están las funciones productos de matrices definidas\n");
    printf("Igual por ahí debe haber alguna lbrería dandov ueltas\n");
    return 0;
}