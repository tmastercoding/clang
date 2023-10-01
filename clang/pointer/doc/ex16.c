#include <stdio.h>

int main(){

    // right -> bottom -> left -> up
    /*
        user_input = 5;

        - first
        as right : 5 
        as bottom : 4
        as left : 4 
        as up : 3

        - second
        as right : 3 
        as bottom : 2
        as left : 2 
        as up : 1

        - third
        as right : 1

    */
    const int user_input = 5;


    int out[user_input][user_input];
    int number = 1;
    int size = user_input;
    int row = 0;
    int col = 0;
    int col2 = col;
    int row2 = row;
    // int inc = 1;
    // inc *= -1;

    // col = col + 1
    // col += inc

    while( number <= user_input * user_input ) {
        


        // as right
        for(; col< col2+size; col++) {
            printf("right number = %d, row = %d, col = %d\n", number, row, col);
            out[row][col] = number++;
        }
        size--; 
        col--; row++;
        col2 = col;
        row2 = row;

        // as bottom
        for(; row< row2+size; row++) {
            // printf("down number = %d, row = %d, col = %d\n", number, row, col);

            out[row][col] = number++;
        }
        col--;
        row--;

        col2 = col;
        row2 = row;

        // as left

        for(; col> col2-size; col--){
            // printf("left number = %d, row = %d, col = %d\n", number, row, col);

            out[row][col] = number++;
        }
        size--;
        row--;
        col++;

        col2 = col;
        row2 = row;

        // as up

        for(;row > (row2-size) ;row--){
            // printf("up number = %d, row = %d, col = %d\n", number, row, col);

            out[row][col] = number++;

        }
        row++;
        col++;
        col2 = col;
        row2 = row;

    }

    // output 
    for( int  row = 0; row < user_input; row++ ) {
        for( int col = 0; col < user_input; col++ ) {

            printf( "%3d", out[row][col] );
        }
        printf("\n");
    }


    return 0;
}