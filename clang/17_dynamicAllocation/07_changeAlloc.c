#include <stdio.h>
#include <stdlib.h>

int* assign_memory( int size );
void print_size( int* arr, int size);

int main(){
    // make arr
    int* arr;
    int size;

    // user input
    printf("input size: ");
    scanf("%d", &size);

    // malloc
    arr = assign_memory( size );

    // check sizeof
    print_size( arr, size);

    free( arr );

    // change user input
    printf("input size that array will change to: ");
    scanf("%d", &size);

    // malloc
    arr = assign_memory( size );

    // check sizeof
    print_size( arr, size);

    free( arr );

    return 0;
}

int* assign_memory( int size ) {
    return (int *)malloc(sizeof(int) * size);
}

void print_size( int* arr, int size ) {
    int sizeCheck = 0;
    for(int idx = 0; idx < size; idx++){
        sizeCheck++;
    }

    printf("size: %d\n", sizeCheck); 
}