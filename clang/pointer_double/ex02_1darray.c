#include <stdio.h>

int main(){
    const int size = 5;

    int arr[size] = {1, 2, 3, 4, 5};

    int* parr = arr;
    int sum = 0;

    while (parr - arr < size){
        sum += ( *parr );
        parr++;
    }

    printf("my grade average: %d \n", sum/size);

    return 0;
}