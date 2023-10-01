#include <stdio.h>

int main(){
    int size = 3;
    int col_size =  size * 2 - 1;

    int row = 0;
    do{
        int col = 0;
        do{
            if( (col < row) || ( ( col_size - row - 1 ) < col )){ 
                printf("  ");
            } else{
                printf("* ");
            }
            col++;
        }while(col < col_size);
        printf("\n");
        row++;
    }while(row < size);
    
}