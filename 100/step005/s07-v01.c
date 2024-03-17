#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int times = 0;
    char* buffer = NULL;
    size_t size = 0;

    int* count_arr = NULL;

    char* line = NULL;
    char** lines = NULL;

    int idx = 0;
    char sep[] = " ";

    char* temp = NULL;

    scanf("%d", &times );
    fflush( stdin );

    count_arr = ( int* )malloc( times * sizeof( int ) );
    lines = ( char** )malloc( times * sizeof( char* ) );

    while( getline( &buffer, &size, stdin ) > -1  ) {

        temp = strtok( buffer, sep );
        count_arr[ idx ] = atoi( temp );

        temp = strtok( NULL, sep );
        lines[idx] = ( char* )malloc( strlen( temp ) * sizeof( char ) );
        strcpy( lines[idx], temp );
        lines[idx][ strlen( temp )-1 ] = '\0';

        if( ++idx == times ) break;

    }

    idx = 0;
    while( 1 ) {
        for( int count = 0; count< strlen( lines[idx] ); count++ ){
            for( int jdx = 0; jdx < count_arr[ idx ]; jdx++ ){
                putchar( lines[idx][count] );
            }
        }
        puts("");

        if( ++idx == times ) break;
    }

    return 0;
}