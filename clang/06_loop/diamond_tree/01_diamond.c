#include <stdio.h>

int main(){
    int size = 5;
    int middle = size / 2 + 1;

    char star = '*';
    char blank = ' ';

    for(int row = 0; row < size; row++){
        for(int col = 0; col < size; col++){

            char flag;
            // top
            if(row < middle - 1){
                if((size > (col + row + 3)) || (size < (col - row  + 3))){
                        flag = blank;
                }else{
                        flag = star;
                }
            }

            // middle
            if(row == middle -1){
                flag = star;
            } 
            
            // bottom
            if(row > middle - 1) {

                // if( (col < row) || ( ( col_size - row - 1 ) < col )){
                // if((size > (row - col + 2)) || ((col + 1) /2 < row)){
                if((col < row / 2) || ( ( size - row/2 - 1 ) < col )){
                        flag = blank;
                }else{
                        flag = star;
                }
            }

            printf("%c ", flag);

        }
        printf("\n");
    }

    return 0;
}