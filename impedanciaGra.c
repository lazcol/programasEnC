#define pi 3.141592654

#include <stdlib.h>
#include <stdio.h>
#include <complex.h>
#include <math.h>


int main(void)
{   int elec=0;
    char salir;
    double R, II;
    double complex z;
    double complex sum,prod,coc;
    
    while(elec!=3){
    system("clear");
    printf("1 - para ingresar impedancia en cartesianas\n");
    printf("2 - para ingresar impedancia en polares\n");
    printf("3 - salir\n");
    scanf("%d", &elec);

    switch (elec)
    {
    case 1 :
        printf("Ingrese la parte Real de z: ");
        scanf("%lf", &R);
        printf("Ingrese la parte Imaginaria de z: ");
        scanf("%lf", &II);
        z = R + II*I;
        printf("Variable inicializada: z = %.4f%+.4fi\n",creal(z),cimag(z));
        printf("z en polares: %.4f e^(%+.4f) \n",cabs(z),carg(z)*180.0/pi);
        printf("presione ENTER para continuar\n");
        while(getchar()!='\n');
        getchar();
        break;

    case 2 :
        printf("Ingrese el modulo de z: ");
        scanf("%lf", &R);
        printf("Ingrese el argumento de z: ");
        scanf("%lf", &II);
        II = II*pi/180.0;
        z = R*cexp(II*I);
        printf("Variable inicializada: z = %.4f e^(%+.4fi)\n",cabs(z),carg(z)*180.0/pi);
        printf("z en cartesianas: %.4f%+.4fi \n",creal(z),cimag(z));
        printf("presione ENTER para continuar\n");
        while(getchar()!='\n');
            getchar();
        break;
            
    case 3 :
        system("clear");
        return 0;
        break;
    }
    }
    return 0;
}