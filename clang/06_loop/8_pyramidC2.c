#include <stdio.h>

int main(){
    int size = 3;
    int row = 0;

    while(row < size){
        int col = 3;

        while(col > row){
            printf("* ");
            col--;
        }
        printf("\n");
        row++;
    }



    return 0;
}