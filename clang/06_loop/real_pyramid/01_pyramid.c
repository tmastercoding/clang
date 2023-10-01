#include <stdio.h>

int main(){
    int size = 3;
    int col_size = size * 2 - 1;

    // if( !(size & 1) ) {
    //     size++;
    // }

    for(int row = size - 1; row > -1; row--){
        // printf( "[ %d ] : ", row );
        for(int col = 0; col < col_size; col++){

            if( ( row > col ) || ( ( col_size - row - 1 ) < col ) )    {
            // if( ( col < row ) ||  (col+row > (size + 1)) ){
                printf("_ ");
            } else{
                printf("* ");
            }
    

            /*
            // Case 02.
            if( ( row > col ) )    {
            // if( ( col < row )  ){
                printf("_ ");
            } else if (  ( col_size - row - 1 ) < col  ) {
                printf("_ ");

            }
             else{
                printf("* ");
            }
            */
            
            /*
            // Case 03.
            if( ( row > col ) )    {
            // if( ( col < row )  ){
                printf("_ ");
            } else {

                if (  ( col_size - row - 1 ) < col  ) {
                    printf("_ ");

                }
                else{
                    printf("* ");
                }
            } 
            */




        }   
        printf("\n");
    }

    return 0;
}
