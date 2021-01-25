#define pi 3.141592654
#define C 0.000000220
#define L 0.000470

#include <stdlib.h>
#include <stdio.h>
#include <complex.h>
#include <math.h>

double complex impSer(double complex x , double complex y);
double complex impPar(double complex x , double complex y);

int main(void)
{   double S,T,W,f;
    // Para corriente continuation
    double R1 = 20.0, R2 = 25.0, R3, R4 = 30.0, Ir1, Ir2, Ir3, Ir4, V1, V2 = 8.0, IV1, IV2;
    // Para corriente alterna
    double complex zr, zl, zc, zeq1, zeq2, Itot, Ic, Ir;
    double complex sum,prod,coc;
    double complex V = 72.0*cexp(-80.0*pi/180.0*I);
    // para Espejos y Lentes
    double fl = -40.0, fe = -15.0, xol, xil, xoe, xie, Al, Ae;
    {
   
    system("clear");
    
    // Ingreso de los datos S, T y W
    printf("Ingresar S\n");
    scanf("%lf",&S);
    printf("Ingresar T\n");
    scanf("%lf",&T);
    printf("Ingresar W\n");
    scanf("%lf",&W);
    
    // Ejercicio 1 - Circuito de Corriente Continua
    printf("Ejercicio 1 - Circuito de Corriente Continua\n");
    printf("============================================\n");
    // Calculo de los valores constantes
    R3 = 16.0+W;
    V1 = 12.0+T;
    Ir1 = V1/R1;
    printf("La fuente V1 = %.6lf\n",V1);
    printf("La fuente V2 = %.6lf\n",V2);
    printf("La corriente Ir1 que pasa por R1 = %.6lf\n",Ir1);
    Ir2 = (V1-((V1/R2-V2/R3)*(R1*R3*R4/(R1*R3+R1*R4+R3*R4))))/R2;
    printf("La corriente Ir2 que pasa por R2 = %.6lf\n",Ir2);
    Ir3 = (((V1/R2-V2/R3)*(R1*R3*R4/(R1*R3+R1*R4+R3*R4)))+V2)/R3;
    printf("La corriente Ir3 que pasa por R3 = %.6lf\n",Ir3);
    Ir4 = ((V1/R2-V2/R3)*(R1*R3*R4/(R1*R3+R1*R4+R3*R4)))/R4;
    printf("La corriente Ir4 que pasa por R4 = %.6lf\n",Ir4);
    printf("La corriente que atraviesa V1 = %.3lf\n",Ir1+Ir2);
    printf("\t\t\tIr4 x R4 == -V2+(Ir3 x R3)\n");
    printf("\t\t\t   %.3lf    %.3lf\n",Ir4*R4,-V2+(Ir3*R3));
    printf("La Potencia de V1 = %.6lf\n",V1*(Ir1+Ir2));
    printf("La potencia de V2 = %.6lf\n",V2*Ir3);
    printf("La potencia de R1 = %.6lf\n",pow(Ir1,2.0)*R1);
    printf("La potencia de R2 = %.6lf\n",pow(Ir2,2.0)*R2);
    printf("La potencia de R3 = %.6lf\n",pow(Ir3,2.0)*R3);
    printf("La potencia de R4 = %.6lf\n",pow(Ir4,2.0)*R4);

    // Ejercicio 2 - Corriente Alterna
    printf("\n\n Ejercicio 2 - Circuito de Corriente Alterna\n");
    printf(" ===========================================\n");
    // Calculo los valores constantes
    printf("zr= %.0lf \n",zr = 39.0 + S);
    printf("frecuencia = %.0lf \n",f = (7.0 + T)*1000);
    printf("zl = %+.3lfi \n",cimag(zl = 2*pi*f*L*I));
    printf("zc = %+.3lfi \n",cimag(zc = -I/(2*pi*f*C)));
    zeq1 = impPar(zc,zr);
    printf("paralelo de R y C = %.3lf%+.3lfi \t\t",creal(zeq1),cimag(zeq1));
    printf("exponencialmente = %.3lf e^(%.3lfi) \n",cabs(zeq1),carg(zeq1)*180/pi);
    zeq2 = impSer(zeq1,zl);
    printf("En serie con L = %.3lf%+.3lfi \t\t\t",creal(zeq2),cimag(zeq2));
    printf("exponencialmente = %.3lf e^(%.3lfi) \n",cabs(zeq2),carg(zeq2)*180/pi);
    Itot = V/zeq2;
    printf("la corriente total = %+.3lf%+.3lfi \t\t",creal(Itot),cimag(Itot));
    printf("exponencialmente = %.3lf e^(%.3lfi) \n",cabs(Itot),carg(Itot)*180/pi);
    Ic = Itot*zr/(zr+zc);
    printf("la corriente por C = %+.3lf%+.3lfi \t\t",creal(Ic),cimag(Ic));
    printf("exponencialmente = %.3lf e^(%.3lfi) \n",cabs(Ic),carg(Ic)*180/pi);
    Ir = Itot*zc/(zr+zc);
    printf("la corriente por R = %+.3lf%+.3lfi \t\t",creal(Ir),cimag(Ir));
    printf("exponencialmente = %.3lf e^(%.3lfi) \n",cabs(Ir),carg(Ir)*180/pi);
    // Tensiones y potencias
    printf("La caida de tensión en L = %.3f%+.3fi",creal(Itot*zl),cimag(Itot*zl));
    printf(" = %.3f e^(%+.3f)\n",cabs(Itot*zl),carg(Itot*zl)*180/pi);
    printf("Potencia en L = %.3f%+.3fi",creal(Itot*Itot*zl),cimag(Itot*Itot*zl));
    printf(" = %.3f e^(%+.3f)\n",cabs(Itot*Itot*zl),carg(Itot*Itot*zl)*180/pi);
    printf("La caida de tensión en C = %.3f%+.3fi",creal(Ic*zc),cimag(Ic*zc));
    printf(" = %.3f e^(%+.3f)\n",cabs(Ic*zc),carg(Ic*zc)*180/pi);
    printf("Potencia en C = %.3f%+.3fi",creal(Ic*Ic*zc),cimag(Ic*Ic*zc));
    printf(" = %.3f e^(%+.3f)\n",cabs(Ic*Ic*zc),carg(Ic*Ic*zc)*180/pi);
    printf("La caida de tensión en R = %.3f%+.3fi",creal(Ir*zr),cimag(Ir*zr));
    printf(" = %.3f e^(%+.3f)\n",cabs(Ir*zr),carg(Ir*zr)*180/pi);
    printf("Potencia en R = %.3f%+.3fi",creal(Ir*Ir*zr),cimag(Ir*Ir*zr));
    printf(" = %.3f e^(%+.3f)\n",cabs(Ir*Ir*zr),carg(Ir*Ir*zr)*180/pi);
    printf("La caida de tensión en la fuente = %.3f%+.3f",creal(V),cimag(V));
    printf(" = %.3f e^(%+.3f)\n",cabs(V),carg(V)*180/pi);
    printf("La potencia de la fuente = %.3f%+.3fi",creal(V*Itot),cimag(V*Itot));
    printf(" = %.3f e^(%+.3f)\n",cabs(V*Itot),carg(V*Itot)*180/pi);
    printf("prueba1: V = Vc + Vl\n");
    printf("%.2f%+.2f = %.2f%+.2f\n",creal(V),cimag(V),creal(Ic*zc+Itot*zl),cimag((Ic*zc+Itot*zl)));
    printf("prueba2: V = Vr + Vl\n");
    printf("%.2f%+.2f = %.2f%+.2f\n",creal(V),cimag(V),creal(Ir*zr+Itot*zl),cimag((Ir*zr+Itot*zl)));

    // Ejercicio 3 - Espejos y Lentes
    printf("\n\n Ejercicio 3 - Espejos y Lentes\n");
    printf(" ==============================\n");
    xol = 110.0+W+S;
    // para la lente
    xil = fl*xol/(fl-xol);
    printf("distancia de la imágen a la lente: %.4lf\n",xil);
    Al = xil/xol;
    printf("La magnificación de la lente es de %+.4lf\n",Al);
    if(Al>0)
        printf("La imagen es derecha\n");
        else
        {
            printf("La imagen es invertida\n");
        }   

    xoe = 90 + xil;
    printf("Ahora vamos respecto del espejo, entonces es 90 más la distancia de la imagen, es decir: %.4lf\n",xoe);
    xie = (xoe*fe)/(xoe-fe);
    printf("la distancia de la imagen es %.4lf\n",xie);
    Ae = -xie/xoe;
    printf("La magnificación es: %+.4lf\n",Ae);
    if(Ae>0)
        printf("La imagen es derecha\n");
        else
        {
            printf("La imagen es invertida\n");
        }   
    printf("La magnificación total es: %+.4lf\ny la imagen es ",Al*Ae);
    if(Ae*Al>0)
        printf("derecha\n");
        else
        {
            printf("invertida\n");
        }   
    
    return 0;
}}

double complex impSer(double complex x , double complex y)
{
        double complex sum;
        sum = x + y;
        return sum;
}

double complex impPar(double complex x , double complex y)
{
        double complex sum, prod, coc;
        sum = x + y;
        prod = x * y;
        coc = prod / sum;
        return coc;
}