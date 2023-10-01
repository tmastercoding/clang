#include <stdio.h>

int main(){
    int size;
    printf("input size or number of rows \n>");
    scanf("%d", &size);
    int col_size =  size * 2 - 1;

    if( !(size & 1) ) {
        size++;
    }

    for(int row = 0; row < size; row++){
        for(int col = 0; col < col_size; col++){

            // if( (col < row) || ( ( col_size - size - row -1 ) > col )){
            
            // char flag;
            if( (col < row) || ( ( col_size - row - 1 ) < col )){
            // if( (col < row) || ((size - row + 1) < col)){
            // generates an empty row if size != 3  
                printf("  ");
                // flag = ' ';
            } else{
                printf("* ");
                // flag = '*';
            }
            // printf( "%c ", flag);
        }
        printf("\n");
    }

    // 2nd way USING Ternary

    // for(int row = 0; row < size; row++){
    //     for(int col = 0; col < col_size; col++){

    //         ( (col < row) || ( ( col_size - row - 1 ) < col ))? printf("_ ") :printf("* "); 
    //        printf( "%c ", ( (col < row) || ( ( col_size - row - 1 ) < col ))? ' ' :'*' ); 
    //     }
    //     printf("\n");
    // }

    
    return 0;
} 