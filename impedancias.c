#include <stdlib.h>
#include <stdio.h>
#include <complex.h>
#include <math.h>

double complex impRec();
double complex impPol();
void impSer(double complex x , double complex y);
void impPar(double complex x , double complex y);

int main(void)
{   int elec;
    double R1, R2, I1, I2;
    double complex z1;
    double complex z2;
    double complex sum,prod,coc;
    
    while (1)
    {
   
    system("clear");
    
    // Ingreso de la impedancia z1
    printf("1 - Ingresar z1 en rectangulares\n");
    printf("2 - Ingresar z1 en polares\n");
    printf("3 - Salir\n");
    scanf("%d",&elec);
    switch (elec)
    {
    case 1 :
        z1 = impRec();
        break;
    
    case 2 :
        z1 = impPol();
        break;

    case 3 :
        return 0;
        break;
    }
    
    // Ingreso de la impedancia z2
    printf("1 - Ingresar z2 en rectangulares\n");
    printf("2 - Ingresar z2 en polares\n");
    printf("3 - Salir\n");
    scanf("%d",&elec);
    switch (elec)
    {
    case 1 :
        z2 = impRec();
        break;
    
    case 2 :
        z2 = impPol();
        break;

    case 3 :
        return 0;
        break;
    }
    printf("\n\nz1: %+.4lf%+.4lfi = %.4lf e^(%+.4lf) \n",creal(z1),cimag(z1),cabs(z1),carg(z1));
    printf("\n\nz2: %+.4lf%+.4lfi = %.4lf e^(%+.4lf) \n\n",creal(z2),cimag(z2),cabs(z2),carg(z2));
    // Calculo de la impedancia equivalente
    printf("1 - z1 y z2 en serie\n");
    printf("2 - z1 y z2 en paralelo\n");
    printf("3 - Salir\n");
    scanf("%d",&elec);
    switch (elec)
    {
    case 1 :
        impSer(z1,z2);
        break;
    
    case 2 :
        impPar(z1,z2);
        break;

    case 3 :
        return 0;
        break;
    }
    
    }   
    
    return 0;
}

double complex impRec()
{
    double Rimp, Iimp;
    printf("Ingrese la parte Real de z1: ");
    scanf("%lf", &Rimp);
    printf("Ingrese la parte Imaginaria de z1: ");
    scanf("%lf", &Iimp);
    printf("Impedancia inicializada: %.2f%+.2fi\t = %.2f e^(%+.2fi)\n\n",Rimp,Iimp,cabs(Rimp+Iimp*I),carg(Rimp+Iimp*I));
    return Rimp+Iimp*I;
}

double complex impPol()
{
    double Rimp, Iimp;
    printf("Ingrese el modulo de z: ");
    scanf("%lf", &Rimp);
    printf("Ingrese el argumento de z: ");
    scanf("%lf", &Iimp);
    printf("Impedancia inicializada: %.2f%+.2fi\t = %.2fe^(%+.2fi)\n\n",creal(Rimp*cexp(Iimp*I)),cimag(Rimp*cexp(Iimp*I)),Rimp,Iimp);
    return creal(Rimp*cexp(Iimp*I))+cimag(Rimp*cexp(Iimp*I))*I;
}

void impSer(double complex x , double complex y)
{
        double complex sum;
        sum = x + y;
        printf("\tEn serie: z1 + z2 = %.4lf%+.4lfi\n", creal(sum), cimag(sum));
        printf("\tEn polares: %.4lf e^(%+.4lfi) \n",cabs(sum),carg(sum));
        printf("presione ENTER para continuar\n");
        while(getchar()!='\n');
            getchar();
}

void impPar(double complex x , double complex y)
{
        double complex sum, prod, coc;
        sum = x + y;
        prod = x * y;
        coc = prod / sum;
        printf("\t\tEn paralelo: (z1 x z2)/(z1+z2) = %.4lf%+.4lfi\n", creal(coc), cimag(coc));
        printf("\t\tEn polares: %.4lf e^(%+.4lfi) \n",cabs(coc),carg(coc));
        printf("presione ENTER para continuar\n");
        while(getchar()!='\n');
            getchar();
}