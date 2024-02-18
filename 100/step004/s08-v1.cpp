#include <stdio.h>

int main() {
    const int size = 10;
    // int src[size] = {0,};
    int arr[size] = {0,};

    int temp = 0;
    int flag = 0;
    int uniq_count = 0;
    int num = 0;

    // init 
    for( int i = 0;i < size; i++ ) {
        arr[i] = -1;
    }

    for( int i = 0;i < size; i++ ) {
        scanf( "%d" ,&num);
        temp = num % 42;

        // first
        if ( i == 0 ) {
            arr[i] = temp;
            uniq_count++;
        }

        flag = 0;
        for( int j = 0; j < i+1; j++ ) {
            if(arr[j] == arr[i]) {
                flag =0;
                break;
            }
            if(arr[j] != arr[i]) {
                flag = 1;
            }
        }

        if( flag ) {
            arr[i] = temp;
            uniq_count++;
        }

    }

    return 0;
}