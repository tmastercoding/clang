#include <stdio.h>

int main(){
    int arr[6] = {1,2,3,4,5,6};
    int* parr = arr;

    printf("Sizeof(arr) : %lu \n", sizeof(arr));
    printf("Sizeof(parr) : %lu \n", sizeof(parr));

    return 0;
}