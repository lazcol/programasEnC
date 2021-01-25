#include <stdlib.h>
#include <stdio.h>

int main()
{
	printf("+++ comienza el programa +++\n");
	printf("asignacion de variable int a = 5 \n");
	int a = 5;
	printf("prueba de asignación con a |= 2\n");
	a |= 2; // que es lo mismo que a = a|2
	printf("a= %d\n es 7 porque subí el bit 1 que corresponde a 2\n",a);
	printf("ahora lo querenmos volver a 5 \n");
	a ^= 2;
	printf("a=%d es 5 porque bajé el bit que corresponde a 2\nahora lo volvemos a 7\n",a);
	a ^= 2;
	printf("a= %d es 7\nahora lo volvemos al 5\n",a);
	a ^= 2;
	printf("a= %d\n es 5\n",a);
	printf("ahora hacemos 4 veces a|=2\n");
	a |= 2;
	a |= 2;
	a |= 2;
	a |= 2;
	printf("a= %d \n es 7, no se sumó 4 veces el 2\n",a);
	printf("ahora hacemos 4 veces a+=2\n");
	a += 2;
	a += 2;
	a += 2;
	a += 2;
	printf("a= %d \n ahora cambia el valor\n",a);
	// RESUMIENDO
	a = 5;
	// quiero cambiar el bit 1 que esté sí o sí en 1
	printf("a= %d deberia ser 7\n",a|2);
	// quiero cambiar el bit 1 que esté sí o sí en 0
	printf("a= %d debería ser 5\n",a&~2);
	// quiero cambiar el bit 1 a su complemento
	printf("a= %d debería ser 7\n",a^2);

	// PARA EL CASO DE LAS MASCARAS //
	    a = 0b10010101;
	int M = 0b01010110;
	int b = (a^M)|(a&M);
	printf("   a= %d%d%d%d%d%d%d%d \n",(a>>7&1?1:0),(a>>6&1?1:0),(a>>5&1?1:0),(a>>4&1?1:0),(a>>3&1?1:0),(a>>2&1?1:0),(a>>1&1?1:0),(a&1?1:0));
	printf("   M= %d%d%d%d%d%d%d%d \n",(M>>7&1?1:0),(M>>6&1?1:0),(M>>5&1?1:0),(M>>4&1?1:0),(M>>3&1?1:0),(M>>2&1?1:0),(M>>1&1?1:0),(M&1?1:0));
	printf("   b= %d%d%d%d%d%d%d%d \n",(b>>7&1?1:0),(b>>6&1?1:0),(b>>5&1?1:0),(b>>4&1?1:0),(b>>3&1?1:0),(b>>2&1?1:0),(b>>1&1?1:0),(b&1?1:0));
	printf(" b|M= %d%d%d%d%d%d%d%d \n",((b|M)>>7&1?1:0),((b|M)>>6&1?1:0),((b|M)>>5&1?1:0),((b|M)>>4&1?1:0),((b|M)>>3&1?1:0),((b|M)>>2&1?1:0),((b|M)>>1&1?1:0),((b|M)&1?1:0));
	printf("bajamos el bit 1 de b con b&=~2\nque es lo mismo que b=b&~2\ntambien lo mismo que b=b&~0b00000010\nque es lo mismo que b=b&~0b11111101\n");
	printf("que es lo mismo que b=b&~0x02\ntambien lo mismo que b=b&FD\n");
	b&=~2;
	printf("b= %d%d%d%d%d%d%d%d \n",(b>>7&1?1:0),(b>>6&1?1:0),(b>>5&1?1:0),(b>>4&1?1:0),(b>>3&1?1:0),(b>>2&1?1:0),(b>>1&1?1:0),(b&1?1:0));
	return 0;
}
