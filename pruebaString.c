#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {
   char src[40];
   int a = 1023;
     
   memset(src, '\0', sizeof(src));
   strncpy(src, "puta madre",38);
   
   printf("Final copied string : %s\n", src);
   printf("%c \n", src[0]);

    itoa(a,src);

   return(0);
}