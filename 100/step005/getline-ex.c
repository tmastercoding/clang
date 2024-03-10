#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    char* line = NULL;
    size_t len = 0;
    FILE* stream = stdin;

    while( getline( &line, &len, stdin) != -1 ) {
        puts( line );
        
    }

    free( line );

    return 0;
}
