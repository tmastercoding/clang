#include <stdio.h>

int main(){
    int arr[3] = {1, 2, 3};
    int (*parr)[3] = &arr;
    
    printf("arr[1] : %d \n", arr[2]);
    printf("parr[1] : %d \n", (*parr)[2]);

    printf("arr : %p \n", arr);
    printf("parr: %p \n", parr);

    return 0;
}