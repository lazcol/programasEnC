#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{   
    double x, result;
    system("clear");
    x = -1.5;
    result = fabs(x);
    printf("|%+.2lf| =  %.2lf\n", x, result);

    x = 11.3;
    result = fabs(x);
    printf("|%+.2lf| =  %.2lf\n", x, result);

    x = -54.96546543;
    result = fabs(x);
    printf("|%+.2lf| =  %.2lf\n", x, result);

    return 0;

}