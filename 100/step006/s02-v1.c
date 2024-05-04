#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {

    char *line = NULL;
    size_t size = 0;
    char sep[] = " ";
    char *ch = NULL;

    char original_state[] = {1, 1, 2, 2, 2, 8};
    int idx = 0;

    if( getline( &line, &size, stdin) != -1 ) {
        ch = strtok( line, sep );

        while( ch !=0 ) {
            printf( "%d ", original_state[idx++] - atoi(ch) );
            ch = strtok( NULL, sep );
        }
    }

    return 0;
}