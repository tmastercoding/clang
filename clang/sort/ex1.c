#include <stdio.h>

int main(){
    const int size = 10;
    int arr[ size ] = { 1, 10, 4, 9, 2, 3, 8, 5, 7, 6};

    int x = 0;

    while( x < 1 || 10000 < x ) {
        scanf( "%d", &x);

    }
    
    for(int count = 0; count < size; count++){
        if(x > arr[count]){
            printf("%d ", arr[count]);
        }
    }


    return 0;
}