#include <stdio.h>

int main(){
    const int user_input = 5;
    int size = user_input;

    int number = 0;
    int out[user_input][user_input];
    int s_count = 2;


    int row = 0;
    int col = 0;
    int var = row;
    int diff = 1;
    int dir = 1;
    int s_diff;
    while(number <= user_input * user_input){

        // incr or dcr?

        if(dir>2){
            diff = -1;
        }

        // row or col?
        var = row;

        if(dir&2){
            var = col;
        }

        if(diff >= 1){
            s_diff = size;
        } else{
            s_diff = 0-size;
        }
        

        for(; (dir > 2)?var < var + s_diff: var > var+s_diff ; var+=diff){

            if(dir&2){
                out[row][var] = number++;
                
            } else {
                out[var][col] = number++;
                
            }
        }

        if (dir & 2){
            col = var;
        } else{
            row = var;
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


        if(s_count > 1){
            s_count = 0;
            size--;
        }
        
        s_count++;
        dir++;
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