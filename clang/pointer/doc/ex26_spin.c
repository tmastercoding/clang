#include <stdio.h>

int main(){
    /*
        for(; {col or row} {< or >} {col or row} {+ or -} size; {col or row} {++ or --} {

            out[row][col] = number++;
        }

    */
    const int user_input = 5;
    int out[user_input][user_input];
    int number = 1;
    int size = user_input;
    int row = 0;
    int col = 0;
    int par;
    int dir = 1;
    int diff;
    while(number <= user_input * user_input){

        par = row;
        if (dir & 2){
            par = col;
        }

        diff = 1;
        if(dir > 2){
            diff = -1; 
        }
        printf("row: %d col: %d\n", row, col);
        
        for(; (dir > 2)?par< par+size:par> par-size ; par += diff) {
            row = par;
            if(dir &2){
                col = par;
            }
            number++;
            // out[row][col] = number++;
        }
        dir++;
    }




    for( int  row = 0; row < user_input; row++ ) {
        for( int col = 0; col < user_input; col++ ) {

            printf( "%3d", out[row][col] );
        }
        printf("\n");
    }

    return 0;
}