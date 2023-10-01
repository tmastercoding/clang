#include <stdio.h>

void main() {
    int a = 4;
    const int b = 4;

    a = 5;
    a++;
    printf( "a -> %d ", a );

    b = 10;
    b++;
    
    printf( "b -> %d ", b );
}