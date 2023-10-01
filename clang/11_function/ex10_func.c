#include <stdio.h>

int max_number(int *parr, int elem);

int main(){
    int arr[10];
    // int i;

    for(int i = 0; i < 10; i++){
        scanf("%d", &arr[i]);
    }

    printf("max number: %d \n", max_number(arr, 10));
    return 0;
}

int max_number(int *parr, int elem){
    // int i;
    // Case 1.
    // int max = parr[0];

    // for (int i = 1; i < elem; i++){
    //     if(parr[i] > max){
    //         max = parr[i];

    //     }
    // }

    // Case 2.
    // int max = *parr;

    // for (int i = 1; i < elem; i++){
    //     parr++;
    //     if(*parr > max){
    //         max = *parr;
    //     }
    // }

    // Case 3.
    int max = *parr;

    for (int i = 1; i < elem; i++){
        if(*(parr + i ) > max){
            max = *(parr + i );
        }
    }

    return max;
}