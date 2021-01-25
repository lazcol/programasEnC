#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int a;
    system("clear");
    printf("ingrese un numero entero: ");
    scanf("%d", &a);
    printf("El numero %d es %o en octal y %X en hexadecimal.\n",a,a,a);

    return 0;
}