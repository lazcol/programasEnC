#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
	int muestras = 100 ;
	float f=1.0, w=2.0*3.141592654*f, y[muestras], add=0.0;
	int g;
	for(g=0;g<muestras;g++)
	{
		y[g]=cos(w*g/muestras);
		add=add+pow(y[g],2);
		//printf("el seno al cuadrado de la posición %d es %.3f \n",i,pow(y[i],2));
	}
	printf("La suma de los cuadrados %.3f \n",add);
	printf("La suma de los cuadrados %.3f dividido %d muestras es %.5f \n",add,sizeof(y)/sizeof(int),add*sizeof(int)/sizeof(y));
	printf("El largo de y es %d \n ",sizeof(y)/sizeof(y[0]));
	printf("El valor cuadratico medio de la señal es %.3f\n\n",sqrt(add*sizeof(int)/sizeof(y)));
	return 0;
}