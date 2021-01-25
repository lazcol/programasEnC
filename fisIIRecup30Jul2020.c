#define pi 3.141592654

#include <stdlib.h>
#include <stdio.h>
#include <complex.h>
#include <math.h>

double complex impSer(double complex x , double complex y);
double complex impPar(double complex x , double complex y);

int main(void)
{   double R,S,T;
    // Para corriente continuation
    double R1, R2, R3, R4, R5, R6, Ir1, Ir2, Ir3, Ir4, Ir41, Ir5, Ir6, V1, V2, V3, IV1, IV2, IV3, vb;
    // Para corriente alterna
    double complex zr, zl, zc, zeq1, zeq2, Itot, Ilc, Ir, f;
    double complex sum, prod, coc;
    double complex V; // = 72.0*cexp(-80.0*pi/180.0*I);
    // para Espejos y Lentes
    double fl, fe, xol, xil, xoe, xie, Al, Ae;
    {
   
    system("clear");
    
    // Ingreso de los datos S, T y W
    printf("Ingresar R\n");
    scanf("%lf",&R);
    printf("Ingresar S\n");
    scanf("%lf",&S);
    printf("Ingresar T\n");
    scanf("%lf",&T);
    
    // Ejercicio 1 - Circuito de Corriente Continua
    printf("Ejercicio 1 - Circuito de Corriente Continua\n");
    printf("============================================\n");
    // Calculo de los valores constantes
    R1 = S+T;
    R2 = R+S;
    R3 = T;
    R4 = S;
    R5 = R;
    R6 = R+S+T;
    V1 = R*S;
    V2 = R*T;
    V3 = 1;
    Ir2 = (V1+V2)/R2;
    printf("La fuente V1 = %.6lf\n",V1);
    printf("La fuente V2 = %.6lf\n",V2);
    vb = (V1/R3+ V2*(1/R3+1/(R1+R4)) + V3/(R5+R6) )/(1/R3 + 1/(R1+R4) + 1/(R5+R6));
    printf("VB = %.6lf\n",vb);
    Ir3 = (V1+V2-vb)/R3; 
    Ir6 = (vb-V3)/(R5+R6);
    Ir1 = (vb - V2)/(R1+R4);
    Ir4 = Ir2 + Ir6 ;
    Ir41 = Ir2 + Ir3 - Ir1 ;
    Ir5 = Ir4 + Ir1 ;
    printf("La corriente Ir1 que pasa por R1 Y R4 = %.6lf\n",Ir1);
    printf("La corriente Ir2 que pasa por R2 = %.6lf\n",Ir2);
    printf("La corriente Ir3 que pasa por R3 = %.6lf\n",Ir3);
    printf("La corriente Ir4 que pasa por V2 = %.6lf\n",Ir4);
    printf("La corriente Ir5 que pasa por V1 = %.6lf\n",Ir5);
    printf("La corriente Ir6 que pasa por V3 = %.6lf\n",Ir6);
    printf("\t\t\tIr6x(R5+R6)+V3 == +Ir2XR2-Ir3XR3\n");
    printf("\t\t\t   %.3lf    %.3lf\n", Ir6*(R5+R6)+V3 ,Ir2*R2-Ir3*R3);
    printf("La Potencia de V1 = %.6lf\n",V1*Ir5);
    printf("La potencia de V2 = %.6lf\n",V2*Ir4);
    printf("La potencia de V3 = %.6lf\n",V3*Ir6);
    printf("La potencia de R1 = %.6lf\n",pow(Ir1,2.0)*R1);
    printf("La potencia de R2 = %.6lf\n",pow(Ir2,2.0)*R2);
    printf("La potencia de R3 = %.6lf\n",pow(Ir3,2.0)*R3);
    printf("La potencia de R4 = %.6lf\n",pow(Ir1,2.0)*R4);
    printf("La potencia de R5 = %.6lf\n",pow(Ir6,2.0)*R5);
    printf("La potencia de R6 = %.6lf\n",pow(Ir6,2.0)*R6);

    // Ejercicio 2 - Corriente Alterna
    f = T*pow(10,3);
    zc = 1/(2*pi*f*25*T*pow(10,-9)*I);
    zl = 2*pi*f*10*S*pow(10,-3)*I;
    zr = 10*R;
    V = R*S*cexp(60*pi/180*I);
    printf("\n\n Ejercicio 2 - Circuito de Corriente Alterna\n");
    printf(" ===========================================\n");
    // Calculo los valores constantes
    printf("zr= %.0lf \n",zr);
    printf("frecuencia = %.0lf \n",f);
    printf("zl = %+.3lfi \n",cimag(zl));
    printf("zc = %+.3lfi \n",cimag(zc));
    zeq1 = impSer(zc,zl);
    printf("serie de L y C = %.3lf%+.3lfi \t\t",creal(zeq1),cimag(zeq1));
    printf("exponencialmente = %.3lf e^(%.3lfi) \n",cabs(zeq1),carg(zeq1)*180/pi);
    zeq2 = impPar(zeq1,zr);
    printf("En paralelo con R = %.3lf%+.3lfi \t\t\t",creal(zeq2),cimag(zeq2));
    printf("exponencialmente = %.3lf e^(%.3lfi) \n",cabs(zeq2),carg(zeq2)*180/pi);
    Itot = V/zeq2;
    printf("la corriente total = %+.3lf%+.3lfi \t\t",creal(Itot),cimag(Itot));
    printf("exponencialmente = %.3lf e^(%.3lfi) \n",cabs(Itot),carg(Itot)*180/pi);
    Ilc = Itot*zr/(zr+zeq1);
    printf("la corriente por L y C = %+.3lf%+.3lfi \t\t",creal(Ilc),cimag(Ilc));
    printf("exponencialmente = %.3lf e^(%.3lfi) \n",cabs(Ilc),carg(Ilc)*180/pi);
    Ir = Itot*zeq1/(zr+zeq1);
    printf("la corriente por R = %+.3lf%+.3lfi \t\t",creal(Ir),cimag(Ir));
    printf("exponencialmente = %.3lf e^(%.3lfi) \n",cabs(Ir),carg(Ir)*180/pi);
    // Tensiones y potencias
    printf("La caida de tensión en L = %.3f%+.3fi",creal(Ilc*zl),cimag(Ilc*zl));
    printf(" = %.3f e^(%+.3f)\n",cabs(Ilc*zl),carg(Ilc*zl)*180/pi);
    printf("Potencia en L = %.3f%+.3fi",creal(Ilc*Ilc*zl),cimag(Ilc*Ilc*zl));
    printf(" = %.3f e^(%+.3f)\n",cabs(Ilc*Ilc*zl),carg(Ilc*Ilc*zl)*180/pi);
    printf("La caida de tensión en C = %.3f%+.3fi",creal(Ilc*zc),cimag(Ilc*zc));
    printf(" = %.3f e^(%+.3f)\n",cabs(Ilc*zc),carg(Ilc*zc)*180/pi);
    printf("Potencia en C = %.3f%+.3fi",creal(Ilc*Ilc*zc),cimag(Ilc*Ilc*zc));
    printf(" = %.3f e^(%+.3f)\n",cabs(Ilc*Ilc*zc),carg(Ilc*Ilc*zc)*180/pi);
    printf("La caida de tensión en R = %.3f%+.3fi",creal(Ir*zr),cimag(Ir*zr));
    printf(" = %.3f e^(%+.3f)\n",cabs(Ir*zr),carg(Ir*zr)*180/pi);
    printf("Potencia en R = %.3f%+.3fi",creal(Ir*Ir*zr),cimag(Ir*Ir*zr));
    printf(" = %.3f e^(%+.3f)\n",cabs(Ir*Ir*zr),carg(Ir*Ir*zr)*180/pi);
    printf("La caida de tensión en la fuente = %.3f%+.3f",creal(V),cimag(V));
    printf(" = %.3f e^(%+.3f)\n",cabs(V),carg(V)*180/pi);
    printf("La potencia de la fuente = %.3f%+.3fi",creal(V*Itot),cimag(V*Itot));
    printf(" = %.3f e^(%+.3f)\n",cabs(V*Itot),carg(V*Itot)*180/pi);
    printf("prueba1: V = Vc + Vl\n");
    printf("%.2f%+.2fi = %.2f%+.2fi\n",creal(V),cimag(V),creal(Ilc*zc+Ilc*zl),cimag((Ilc*zc+Ilc*zl)));
    printf("prueba2: V = Vr \n");
    printf("%.2f%+.2fi = %.2f%+.2fi\n",creal(V),cimag(V),creal(Ir*zr),cimag((Ir*zr)));

    // Ejercicio 3 - Espejos y Lentes
    printf("\n\n Ejercicio 3 - Espejos y Lentes\n");
    printf(" ==============================\n");
    fl = 1; //cm
    fe = 5; //cm
    xol = 1.5; //cm
    
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

    xoe = R+S+T+5; //cm
    printf("Ahora vamos respecto del espejo, entonces es 90 más la distancia de la imagen, es decir: %.4lf\n",xoe);
    xie = (xoe*fe)/(-xoe+fe);
    printf("la distancia de la imagen es %.4lf\n",xie);
    Ae = xie/xoe;
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