#include <stdio.h> 
#include <time.h>  

int main(void) {
    
    time_t now = 1595451933; //time(&now);
    
    // if (now == -1) {
        
    //     puts("The time() function failed");
    // }
        
    struct tm *ptm; // = gmtime(&now);
    ptm = localtime(&now);
    
    // if (ptm == NULL) {
        
    //     puts("The gmtime() function failed");
    // }    
    
    printf("UTC time: %d",(*ptm).tm_hour); //asctime(ptm));

    return 0;
}