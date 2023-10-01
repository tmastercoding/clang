#include <stdio.h>

int main(){

    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int* parr;

    // case 01.
    parr = arr;
    
    // case 02.
    parr = &arr[0];

    // case 01.
    printf("arr[3] = %d, *(parr + 3) = %d \n", arr[3], *(parr + 3));

    // case 02.
    printf("arr[3] = %d, *(parr + 3) = %d \n", arr[3], arr[3]);
    
    return 0;
}