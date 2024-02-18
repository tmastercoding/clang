#include <stdio.h>
#include <stdlib.h>

int main() {

    int size = 5;
    int buffered_number = 0;

    int* ptr = (int *)malloc( size );

    for( int idx = 0; idx < size; idx++ ) {
        scanf( "%d", &buffered_number );
        *( ptr + idx ) = buffered_number;
    }

    for( int idx = 0; idx < size; idx++ ) {
        printf( "%d", *( ptr + idx ) );
    }

    return 0;
}