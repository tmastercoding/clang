#include <stdio.h>

int main(){
    int size = 3;
    int row = 0;

    do{
        int col = 3;

        do{
            printf("  ");
            col--;
        } while(col > row);
        
        int times = 0;
        do{
            printf("* ");
            times++;
        } while( times < (col * 2 + 1- row));

        printf("\n");

        row++;
    } while(row < size);


    return 0;
}