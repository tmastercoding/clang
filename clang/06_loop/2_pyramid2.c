#include <stdio.h>

int main(){
    int size = 3;
    int row = 0;
    int col = 0;

    scanf( "%d", &size );

    // Outer
    while(row < size){
        // Inner
        while(col < row+1){
            printf("* ");
            col++;
        }
        col = 0;
        printf("\n");
        row++;
    }

    return 0;
}