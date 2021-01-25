#include <stdio.h> 
#include <time.h>  

int unix2norm(int ahora, int *horas);

int unix2norm(int ahora, int *horas) {
    
    time_t now = ahora; //1595451933; //time(&now);
    
    // if (now == -1) {
        
    //     puts("The time() function failed");
    // }
        
    struct tm *ptm; // = gmtime(&now);
    ptm = localtime(&now);
    
    // if (ptm == NULL) {
        
    //     puts("The gmtime() function failed");
    // }    
    
    //printf("UTC time: %d",(*ptm).tm_hour); //asctime(ptm));

    horas[0] = (*ptm).tm_hour;
    horas[1] = (*ptm).tm_min;
    horas[2] = (*ptm).tm_sec;

    return 0;
}