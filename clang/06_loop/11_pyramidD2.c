#include <stdio.h>

int main(){
    int size = 3;
    int row = 0;

    while(row < size){
        int col = 0;
        
        while(col < row){
            printf("  ");
            col++;
        }

        int times = 3;
        while(times > row){
            printf("* ");
            times--;
        }

        printf("\n");
        row++;
    }

    return 0;
}