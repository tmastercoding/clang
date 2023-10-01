#include <stdio.h>

int main(){
    const int row = 100;
    const int col = 100;
    
    // prepare shapes
    int shapes[3][2] ={
        {3,7},
        {15, 7},
        {5, 2}
    };

    // prepare n initialize map
    int s_arr[row][col] = {0,};

    int shape[2];
    // shape[0] = shapes[0][0];
    // shape[1] = shapes[0][1];

    for( int n = 0; n < 3; n++ ) {
        shape[0] = shapes[n][0];
        shape[1] = shapes[n][1];
        
        for(int idx = shape[0]; idx < shape[0] + 10; idx++ ){
            for(int jdx = shape[1]; jdx < shape[1] + 10; jdx++){
                s_arr[idx][jdx] = 1;
            }
        }

    }

    int count = 0;

    for(int idx = 0; idx < row; idx++){
        for(int jdx = 0; jdx < col; jdx++){
            if( s_arr[idx][jdx] & 1 ){
            // if( s_arr[idx][jdx] == 1 ){
                count++;
            }
        }
    }

    printf("area: %d\n", count);

    return 0;
}