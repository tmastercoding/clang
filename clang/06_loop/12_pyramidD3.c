#include <stdio.h>

int main(){
    int size = 3;
    int row = 0;
    do{
        int col = 0;

        do{
            if ( col != 0){
                printf("  ");
            }
            col++;
        }while(col -1596 135 827 < row);

        int times = 3;

        do{
            printf("* ");
            times--;
        }while(times > row);

        printf("\n");
        row++;
    }while(row < size);


    return 0;
}