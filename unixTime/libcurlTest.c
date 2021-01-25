/*
If libcurl is not installed yet (curl.h cannot be found):

$ sudo apt-get install libcurl4-openssl-dev

Compilar utilizando gcc en linux:

$ gcc -o libcurlTest libcurlTest.c -Wall -Wextra -lcurl

Testing:
Prueba con OpenWeather

$ ./libcurlTest "https://api.openweathermap.org/data/2.5/forecast?q=buenos aires,AR&&appid=860540b295153b4d5daec5e11b5311e0&cnt=1&units=metric"

*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <curl/curl.h>

typedef struct string_buffer_s
{
    char * ptr;
    size_t len;
} string_buffer_t;

static void string_buffer_initialize( string_buffer_t * sb )
{
    sb->len = 0;
    sb->ptr = malloc(sb->len+1);
    sb->ptr[0] = '\0';
}

static void string_buffer_finish( string_buffer_t * sb )
{
    free(sb->ptr);
    sb->len = 0;
    sb->ptr = NULL;
}

static size_t string_buffer_callback( void * buf, size_t size, size_t nmemb, void * data )
{
    string_buffer_t * sb = data;
    size_t new_len = sb->len + size * nmemb;

    sb->ptr = realloc( sb->ptr, new_len + 1 );

    memcpy( sb->ptr + sb->len, buf, size * nmemb );

    sb->ptr[ new_len ] = '\0';
    sb->len = new_len;

    return size * nmemb;
}

static size_t header_callback(char * buf, size_t size, size_t nmemb, void * data )
{
    return string_buffer_callback( buf, size, nmemb, data );
}

static size_t write_callback( void * buf, size_t size, size_t nmemb, void * data )
{
    return string_buffer_callback( buf, size, nmemb, data );
}

int main( int argc, char * argv[] )
{
    char *datos; // para guardar el string
    char fecha[]=""; //guardar la fecha unix
    CURL * curl;
    CURLcode res;
    string_buffer_t strbuf;

    char * myurl = argv[1];

    string_buffer_initialize( &strbuf );

    curl = curl_easy_init();

    if(!curl)
    {
        fprintf(stderr, "Fatal: curl_easy_init() error.\n");
        string_buffer_finish( &strbuf );
        return EXIT_FAILURE;
    }

    curl_easy_setopt(curl, CURLOPT_URL, myurl );
    //curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L );
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback );
    //curl_easy_setopt(curl, CURLOPT_HEADERFUNCTION, header_callback );
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &strbuf );
    curl_easy_setopt(curl, CURLOPT_HEADERDATA, &strbuf );

    res = curl_easy_perform(curl);

    if( res != CURLE_OK )
    {
        fprintf( stderr, "Request failed: curl_easy_perform(): %s\n", curl_easy_strerror(res) );

        curl_easy_cleanup( curl );
        string_buffer_finish( &strbuf );

        return EXIT_FAILURE;
    }

    printf( "%s\n\n", strbuf.ptr );
    datos = strbuf.ptr;
     while( *datos != '\0')
    {
        if(*datos == 'd' && *(datos+1)== 't' && *(datos+2)== '"' && *(datos+3)== ':')
        {
            printf("Encontro dt --- Procediendo a sacar el dato\n\n");
            datos += 4;
            for (int i=0 ; *(datos+i)!=',' ; i++)
            {
                fecha[i] = *(datos+i)+'\0';
            }
        }
        datos++;
    }

    
    curl_easy_cleanup( curl );
    string_buffer_finish( &strbuf );
    printf("lo extraido: %s\n\n",fecha);

    return EXIT_SUCCESS;
}