#include <stdio.h>
#include <complex.h>

int main(void)
{   double complex z1 = 1.0+3.0*I;
    double complex z2 = 1.0-4.0*I;
    double complex sum,prod,coc;
    double imag, real, modulo1 = 0.0, modulo2 = 0.0, fase;

    printf("Números Complejos en C:\n\v");
    printf("Variables inicializadas: Z1 = %.2f + %.2fi\tZ2 = %.2f %+.2fi\n",creal(z1),cimag(z1),creal(z2),cimag(z2));

    sum = z1 + z2;
    printf("La suma: Z1 + Z2 = %.2f %+.2fi\n", creal(sum), cimag(sum));
    prod = z1 * z2;
    printf("El producto de z1 x z2 = %.2f %+.2fi\n", creal(prod), cimag(prod));
    coc = z1 / z2;
    printf("El cociente de z1 / z2 = %.2f %+.2fi\n", creal(coc), cimag(coc));
    coc = z2 / z1;
    printf("El cociente de z2 / z1 = %.2f %+.2fi\n", creal(coc), cimag(coc));
    printf("El mismo de antes en Amplitud y Fase: %.2f %.2f \n",abs(coc),abs(coc));
    return 0;
}