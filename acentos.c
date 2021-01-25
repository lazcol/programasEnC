#include <stdio.h>
#include <stdlib.h>
int main()
{
    //á –> \xA0; é –> \x82; í –> \xA1; ó –> \xA2; ú –> \xA3; ñ –> \xA4; Ñ –> \xA5;
    //á -> 160; é -> 130; í -> 161; ó -> 162; ú -> 163; ñ -> 164;
    char texto1 [50] = "<<El ant\xA1lope est\xA0 hecho a\xA4icos>>";
    char texto2 [50] = "<<Hoy llueve>>";
    char texto3 [50] = "<<El ca\xA4\xA2n es corto>>";
    char texto4 [50] = "<<aprenderaprogramar>>";
    printf("\t%s\n", texto1);
    printf("\t\t%s\n", texto2);
    printf("\t\t\t%s\n", texto3);
    printf("\t\t\t\t%s\n\n\n", texto4);
    printf("\t<<El ant%clope est%c hecho a%cicos>>\n", 161, 160, 164);
    printf("\t\t<<Hoy llueve>>\n");
    printf("\t\t\t<<El ca%c%cn es corto>>\n", 164, 162);
    printf("\t\t\t\t<<aprenderaprogramar>>\n\n\n");
    return 0;
}