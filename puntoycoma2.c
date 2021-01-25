#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void
replaceString(char *buf, const char *orig, const char *replace)
{
    int olen, rlen;
    char *s, *d;
    char *tmpbuf;

    if (!buf || !*buf || !orig || !*orig || !replace)
        return;

    tmpbuf = malloc(strlen(buf) + 1);
    if (tmpbuf == NULL)
        return;


    olen = strlen(orig);
    rlen = strlen(replace);

    s = buf;
    d = tmpbuf;

    while (*s) {
        if (strncmp(s, orig, olen) == 0) {
            strcpy(d, replace);
            s += olen;
            d += rlen;
        }
        else
            *d++ = *s++;
    }

    *d = '\0';

    strcpy(buf, tmpbuf);
    free(tmpbuf);
}

int
main(int argc, char **argv)
{
    char str[] = "malatya istanbul madrid newyork";

    replaceString(str, "malatya", "ankara");
    printf("%s\n", str);
    replaceString(str, "madrid", "tokyo");
    printf("%s\n", str);

    return 0;
}