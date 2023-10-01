#include <stdio.h>

int main(){
    int size = 3;
    int col_size =  size * 2 - 1;

    int row = 0;
    while(row < size){
        int col = 0;
        while(col < col_size){

            if( (col < row) || ( ( col_size - row - 1 ) < col )){ 
                printf("  ");
            } else{
                printf("* ");
            }
            col++;
        }

        printf("\n");
        row++;
    }
}