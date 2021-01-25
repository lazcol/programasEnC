/**
 * C program to convert Hexadecimal to Decimal number system
 */
#include <stdio.h>
#include <math.h>
#include <string.h>


// argc es el numero de cosas que se ingresan por la linea de comandos
// *argv[] es el puntero a los valores que se ingresaron
int main(int argc, char *argv[])
{
    char hex[17];
    long long decimal, place;
    int i = 0, val, len;

    decimal = 0;
    place = 1;

    if (argc == 1){
        /* Input hexadecimal number from user */
        printf("Ingrese un numero Hexadecimal: ");
        gets(hex);
    }
    else
    {
        strncpy(hex, argv[1], strlen(argv[1]));
    }
    
    /* Find the length of total number of hex digit */
    len = strlen(hex);
    len--;

    /*
     * Iterate over each hex digit
     */
    for(i=0; hex[i]!='\0'; i++)
    {
 
        /* Find the decimal representation of hex[i] */
        if(hex[i]>='0' && hex[i]<='9')
        {
            val = hex[i] - 48;
        }
        else if(hex[i]>='a' && hex[i]<='f')
        {
            val = hex[i] - 97 + 10;
        }
        else if(hex[i]>='A' && hex[i]<='F')
        {
            val = hex[i] - 65 + 10;
        }

        decimal += val * pow(16, len);
        len--;
    }

    printf("Hexadecimal = %s \t Decimal = %d\n", hex, decimal);

    return decimal;
}