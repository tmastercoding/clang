#include <stdio.h>

int main(){
    int size = 3;
    int col_size = size *2 -1;
    int row = size -1;

    while(row > -1){
        int col = 0;
        while(col < col_size){

            if( ( row > col ) || ( ( col_size - row - 1 ) < col ) )    {
                printf("_ ");
            } else{
                printf("* ");
            }
            
            col++;
        }

        printf("\n");
        row--;
    }

    return 0;
}