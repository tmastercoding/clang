#include <stdio.h>

int main(){
    int size = 3;
    int col_size = size *2 -1;
    int row = size -1;
    do{
        int col = 0;

        do{
            if( ( row > col ) || ( ( col_size - row - 1 ) < col ) )    {
                printf("_ ");
            } else{
                printf("* ");
            }
            col++;
        }while(col < col_size);
        row--;

        printf("\n");
    }while(row > -1);
    


    return 0;
}