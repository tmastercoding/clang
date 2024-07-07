#include <stdio.h>
#include <stdlib.h>

/**
 * @date ??.??.??
 * @author Tay Oh
 * @details code explaining scanf
 *          input to array
*/

int main() {

    int size = 5;
    int buffered_number = 0;

    // malloc
    int* ptr = (int *)malloc( size );

    // get input for size
    for( int idx = 0; idx < size; idx++ ) {
        scanf( "%d", &buffered_number );
        // input to ptr
        *( ptr + idx ) = buffered_number;
    }

    // output
    for( int idx = 0; idx < size; idx++ ) {
        printf( "%d", *( ptr + idx ) );
    }

    return 0;
}