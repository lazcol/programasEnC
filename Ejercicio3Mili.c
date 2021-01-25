/*
 * File:   Ejercicio3.c
 * Author: mili
 *
 * Created on May 8, 2020, 6:38 PM
 */

#define MIPS 30

#include <p30F4013.h>		// si se cambia de DSC cambiar tb p30FXXXX.gld linker
#include <stdio.h>
#include <string.h>
#include <dsp.h>
#include <time.h>           // tic toc
#include <uart.h>
#include "terminal.h"		// hiperterminal colores
#include "delays.h"
#include "config.h"

clock_t start, stop;
unsigned int j, i;
static double count=0;
double x[3][3];
fractional srcA[3][3]={{Q15(0.02/8),Q15(0.12/8),Q15(-0.12/8)},{Q15(0.13/8),Q15(-0.15/8),Q15(1.2/8)},{Q15(0.28/8),Q15(-0.28/8),Q15(0.1/8)}};
fractional srcB[3][3]={{Q15(1.3/8),Q15(0.13/8),Q15(-0.15/8)},{Q15(0.21/8),Q15(0.18/8),Q15(-0.01/8)},{Q15(-0.03/8),Q15(0.17/8),Q15(0.13/8)}};
float A[3][3]={{0.02,0.12,-0.12},{0.13,-0.15,1.2},{0.28,-0.28,0.1}};
float B[3][3]={{1.3,0.13,-0.15},{0.21,0.18,-0.01},{-0.03,0.17,0.13}};
fractional dstM[3][3]; //En esta variable se guarda la inversa en fractional con DSP
fractional y[3][3];// En esta variable se guarda la inversa en fractional con DSP
float C[3][3]; //En esta variable se guarda la inversa en float con DSP
float M[3][3]; //En esta variable se guarda el producto en float sin DSP
float I[3][3]; //En esta variable se guarda la inversa en float sin DSP
float pivotFlag[3];
int swappedRows[3];
int swappedCols[3];

void producto_matrices (fractional* dstM, fractional* srcA, fractional* srcB);
void prod_matrices_Float (float* m1, float* m2);
void matriz_inversa (float* C, float* A);
void invertir_matriz(float* m);

int main(void) {
    printf("\n\n\t\t\t ///EJERCICIO 3///\r\n\n");
    printf("Producto de matrices con DSP:\r\n");
    printf("A.B:\r\n");
    producto_matrices(&(dstM[0][0]),&(srcA[0][0]),&(srcB[0][0]));
    printf("B.A:\r\n");
    producto_matrices(&(dstM[0][0]),&(srcB[0][0]),&(srcA[0][0]));
    printf("Producto de matrices sin DSP:\r\n");
    printf("A.B:\r\n");
    prod_matrices_Float(&(A[0][0]),&(B[0][0]));
    printf("B.A:\r\n");
    prod_matrices_Float(&(B[0][0]),&(A[0][0]));
    printf("Inversa matrices sin DSP:\r\n");
    printf("Inversa de B:\r\n");
    invertir_matriz(&(B[0][0]));
    printf("Inversa de A:\r\n");
    invertir_matriz(&(A[0][0]));
    printf("Producto de A por su inversa sin DSP:\r\n");
    prod_matrices_Float(&(A[0][0]),&(I[0][0]));
    printf("Inversa matrices con DSP:\r\n");
    printf("Inversa de B:\r\n");
    matriz_inversa(&(C[0][0]),&(B[0][0]));
    printf("Inversa de A:\r\n");
    matriz_inversa(&(C[0][0]),&(A[0][0]));
    printf("Producto de A por su inversa con DSP:\r\n");
    //Paso la inversa a fractional porque el DSP me da el resultado en float y para hacer el producto me pide una matriz fractional
    for (i=0;i<3;i++)
		{
        for(j=0;j<3;j++)
        {
            y[i][j]=Q15(C[i][j]/8);
        }
		}
    producto_matrices(&(dstM[0][0]),&(srcA[0][0]),&(y[0][0]));
    while (1);
}
void producto_matrices (fractional* dstM, fractional* srcA, fractional* srcB)
{
	start = clock();   // Comienza a contar los Tcy (tic)
    MatrixMultiply (3, 3, 3, dstM, srcA, srcB);// library function del DSP
    stop = clock(); // toc
	count=(stop-start)-19.0;  // 19 Tcy le lleva ejecutar el start clock
    //Se los resto porque quiero medir los Tcy que le lleva al programa hacer la operación
	printf("# TCY: %.1f\r\n",count);
	printf("# TCY: En realidad deberia dar: [36 + numFilas1*(8+numColumnas2*(7+4*numCol1Fil2))]= 36+3*(8+3*(7+4*3))=231 !\r\n\n");
    for (i=0;i<3;i++)
	{
        for(j=0;j<3;j++)
        {
            x[i][j]=Fract2Float(dstM[i*3+j])*64;	
            printf(" %.3f  ",x[i][j]);
        }
        printf("\r\n");
	}
    printf("\n");
}

void prod_matrices_Float(float* m1, float* m2)
{
    int f1,c1,f2;
    start=clock(); // Comienza a contar los Tcy (tic)
    for (f1=0;f1<=2;f1++){
        for (c1=0;c1<=2;c1++){
            M[f1][c1]=0;
            for(f2=0;f2<=2;f2++){
                M[f1][c1]=M[f1][c1]+m1[f1*3+f2]*m2[f2*3+c1];
            }
        }
    }
    stop=clock(); //toc
    count=(stop-start)-19.0;  // 19 Tcy le lleva ejecutar el start clock
    //Se los resto porque quiero medir los Tcy que le lleva al programa hacer la operación
	printf("# TCY: %.1f\r\n",count);
    for (j=0;j<=2;j++){
        for (i=0;i<=2;i++){
            x[j][i]=M[j][i];
            printf(" %.3f  ",x[j][i]);
        }
        printf("\r\n");
	}
    printf("\n");
}

void matriz_inversa (float* C, float* A)
{
	start = clock();   // Comienza a contar los Tcy (tic)
    MatrixInvert ( 3, C, A, pivotFlag, swappedRows, swappedCols); // library function del DSP
    stop = clock(); // toc
	count=(stop-start)-19.0;  // 19 Tcy le lleva ejecutar el start clock
    //Se los resto porque quiero medir los Tcy que le lleva al programa hacer la operación
	printf("# TCY: %.1f\r\n",count);
	for (i=0;i<3;i++)
	{
        for(j=0;j<3;j++)
        {
            x[i][j]=C[i*3+j];	
            printf(" %.3f  ",x[i][j]);
        }
        printf("\r\n");
	}
    printf("\n");
}
void invertir_matriz(float* m)
{
    float determinante=0;
    start=clock(); // Comienza a contar los Tcy (tic)
    for(i=0;i<3;i++){
      determinante = determinante + (m[0*3+i]*(m[1*3+((i+1)%3)]*m[2*3+((i+2)%3)]-m[1*3+((i+2)%3)]*m[2*3+((i+1)%3)]));
    }
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
           I[i][j]=(((m[((j+1)%3)*3+((i+1)%3)] * m[((j+2)%3)*3+((i+2)%3)])-(m[((j+1)%3)*3+((i+2)%3)]*m[((j+2)%3)*3+((i+1)%3)]))/ determinante);
        }
    }
    stop=clock(); //toc
    count=(stop-start)-19.0;  // 19 Tcy le lleva ejecutar el start clock
    //Se los resto porque quiero medir los Tcy que le lleva al programa hacer la operación
	printf("# TCY: %.1f\r\n",count);
    for (j=0;j<=2;j++){
        for (i=0;i<=2;i++){
            x[j][i]=I[j][i];
            printf(" %.3f  ",x[j][i]);
        }
        printf("\r\n");
	}
    printf("\n");
}
