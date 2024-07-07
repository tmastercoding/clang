#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @date ??.??.??
 * @author Tay Oh
 * @details code example getline
*/

int main() {

    // a null char ptr
    char* line = NULL;
    // 0 size
    size_t len = 0;

    // while getline is not error
    while( getline( &line, &len, stdin) != -1 ) {
        // print
        puts( line );
        
    }

    // free mem
    free( line );

    return 0;
}
