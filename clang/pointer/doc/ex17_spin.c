#include <stdio.h>

int main(){

    const int user_input = 5;


    int out[user_input][user_input];
    int number = 1;
    int size = user_input;

    int row = 0;
    int col = 0;

    int count_size = 2;
    int dir = 1; 
    int var = row;
    int diff = 1; 

    while( number <= user_input * user_input ) {
        var = row;

        if(dir%2){
            var = col;
            
        }

        for(; var< var+size; var+=diff) {
            (dir%2)?out[row][var] = number++: out[var][col];
            
        }

        // size, changes every 2

        if (count_size > 1){
            size--; 
            count_size = 0;
        }

        count_size++;

        if (dir >= 2){
            diff = -1;
        }

        if (dir == 1){
            col--; row++;
        } else if(dir == 2){
            col--; row--;
        } else if(dir == 3){
            col++;row--;
        } else if(dir == 4){
            col++; row++;
        }
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