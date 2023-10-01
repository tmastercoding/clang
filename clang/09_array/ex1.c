#include <stdio.h>

int main(){
    // int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // int arr[10];
    // int arr[10] = { 0,};

    int arr[10];
    
    for(int count = 0; count < 11; count++){
        arr[ count ] = count + 1;
    }

    // printf("Array\'s 3rd index: %d \n", arr[2]);

    for(int count = 0; count < 11; count++){
        printf("%d\n", arr[ count ]);
    }

    return 0;
}