#include <stdio.h>

int main(){

    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int* parr;

    // case 01
    parr = &arr[0];
    // case 02
    parr = arr;

    for(int i = 0; i < 10; i++){
        // access to array with index
        printf("arr[%d] address: %p \n", i, &arr[i]);
        printf("arr[%d] address: %d \n", i, arr[i]);

        // access to pointer
        // case 01.
        printf("(parr + %d) value: %p \n", i, (parr + i));
        printf("(parr + %d) value: %d \n", i, *(parr + i));
        // case 02.
        printf("(parr + %d) value: %p \n", i, ++parr);
        printf("(parr + %d) value: %d \n", i, *(++parr));

        if(&arr[i] == (parr + i)) {
            printf("--> same \n");
        }else {
            printf("--> not same\n");
        }
    }


    return 0;
}