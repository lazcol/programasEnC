#include <stdio.h>
#include <stdlib.h>

void deleteSpaces(FILE *handle)
{
    FILE *output1,*output2;
    char p;

    output1 = fopen("mailsCorregidos1.txt","r+");
    output2 = fopen("mailsCorregidos2.txt","w");
    fseek(handle,0,SEEK_SET);
    while((p=getc(handle))!=EOF)
    {
        if(p!=9 && p!=10 && p!=13 && p!=32)
            fputc(p,output1);
    }
    fputc(EOF,output1);
    fseek(output1,0,SEEK_SET);
    while((p=getc(output1))!=EOF)
    {
        fputc(p,output2);
        if(p==';')
            fputc('\n',output2);
    }
    fputc(EOF,output2);
    fclose(output1);
    fclose(output2);
}

int main(int argc, char** argv)
{
    //if (argc < 4) return -1; /* quit if argument list not there */

    FILE* handle = fopen(argv[1], "r+"); /* open the file for reading and updating */
    
    if (handle == NULL) return -1; /* if file not found quit */
    char current_char = 0;
    char to_replace = '\n'; // argv[1][0]; /* get the character to be replaced */
    char replacement = ';'; // argv[2][0]; /* get the replacing character */

    while ((current_char  = fgetc(handle)) != EOF) /* while it's not the end-of-file */
    {                                              /*   read a character at a time */

        if (current_char == to_replace || current_char == ' ') /* if we've found our character */
        {
            fseek(handle, ftell(handle) - 1, SEEK_SET); /* set the position of the stream
                                                           one character back, this is done by
                                                           getting the current position using     
                                                           ftell, subtracting one from it and 
                                                           using fseek to set a new position */

            fprintf(handle, "%c", replacement); /* write the new character at the new position */

            while (((current_char  = fgetc(handle)) == '\n' || current_char == ' ') && current_char != EOF )
            {
                printf("enocntro\n");
                fseek(handle, ftell(handle) - 1, SEEK_SET);
                fprintf(handle, " ");
                //handle++; //fseek(handle, ftell(handle)+1, SEEK_SET);
            }
        }
        
    }
    deleteSpaces(handle);

    fclose(handle); /* it's important to close the file_handle 
                       when you're done with it to avoid memory leaks */

    return 0;
}