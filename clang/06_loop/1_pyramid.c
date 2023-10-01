#include <stdio.h>

int main(){
    int size = 5;

    // Outer
    for(int row = 0; row < size; row++){
        // Inner
        for(int col = 0; col < row+1; col++ ){
            printf("* ");
        }
        printf("\n");
    }
    return 0;
}