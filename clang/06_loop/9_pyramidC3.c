#include <stdio.h>

int main(){
    int size = 3;
    int row = 0;

    do{
        int col = 3;
        do{
            printf("* ");
            col--;
        }while(col > row);

        printf("\n");

        row++;
    }while(row < size);


    return 0;
}