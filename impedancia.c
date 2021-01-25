#include <stdlib.h>
#include <stdio.h>
#include <complex.h>
#include <math.h>


int main(void)
{   int elec=0;
    double R, II;
    double complex z; // = 1.0+3.0*I;
    
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
        printf("Variable inicializada: z = %.2f%+.2fi\n",creal(z),cimag(z));
        printf("z en polares: %.4f e^(%+.4f) \n",cabs(z),carg(z));
        printf("presione ENTER para continuar\n");
        while(getchar()!='\n');
        getchar();
        break;

    case 2 :
        printf("Ingrese el modulo de z: ");
        scanf("%lf", &R);
        printf("Ingrese el argumento de z: ");
        scanf("%lf", &II);
        z = R*cexp(II*I);
        printf("Variable inicializada: z = %.2f e^(%+.2fi)\n",cabs(z),carg(z));
        printf("z en cartesianas: %.2f%+.2fi) \n",creal(z),cimag(z));
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