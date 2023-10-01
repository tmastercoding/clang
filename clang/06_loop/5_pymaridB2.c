#include <stdio.h>

int main(){
    int size = 3;
    int row = 0;

    while(row < size){
        int col = 3;

        while(col > row){
            printf("  ");
            col--;
        }
        int times = 0;

        while(times < (col*2 + 1 - row)){
            printf("* ");
            times++;
        }

        printf("\n");

        row++;
    }

    return 0;
}