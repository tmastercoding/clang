#include <stdio.h>

void bubble_sort(int arr[], int count){
    int temp;
    int inner_count = count;

    for( int i = 0; i < count; i++ ){ // N

        printf( "count : %d, inner_count: %d\n", count, inner_count);
        for( int j = 0; j < inner_count - 1; j++ ){ // N
            if( arr[j] > arr[j+1] ){

                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
        inner_count--;
    }
}

int main(){
    int numArr[] = {4, 8, 2, 9, 1, 5};
    int size = sizeof(numArr)/sizeof(int);
    bubble_sort(numArr, size);

    for(int i = 0; i < size; i++){
        printf("%d ", numArr[i]);
    }
    printf("\n");

    return 0;
}