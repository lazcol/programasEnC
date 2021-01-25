#include<stdio.h>
          #include<stdlib.h>
          int main()
         {                          
          int x,y;
           for(y=10;y>=-10;y--)
          {
               for(x=-10;x<=10;x++)
                  {
                        if(y==(x-1)*(5-x))
                            {
                                printf("* ");
                            }
                        else
                           {
                               printf("  ");
                           }
                  }printf("\n");
          }
           return 0;

          }