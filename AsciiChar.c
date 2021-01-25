#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i;
        for (i=0;i<=127;i++)
	{
		printf("\n Caracter %c es el numero %d",i,i);
	}
	printf("\n"); 
    printf("\u2500\u2501\n");
        return 0;
}