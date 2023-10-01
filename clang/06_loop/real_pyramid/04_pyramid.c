#include <stdio.h>

int main(){
    int size = 5;
    int col_size = (int)((size + 1) /2);

    for(int row = size - 1; row > -1; row--){
        for(int col = 0; col < col_size; col++){
            
            if( (col_size > (row + col + 1)) || ((row - col + 1) > col_size)){
                printf("  ");
            }else{
                printf("* ");
            }
            // TERANRY VER
            // ( (col_size > (row + col + 1)) || ((row - col + 1) > col_size))? printf("_ "): printf("* ");
        }
        printf("\n");
    }

    return 0;
}