#include <stdio.h>

int main(){
    // get the amount of space the black squares take up

    int square_num = 3;
    int area = 0;
    int b_area = 100;

    const int row = 3;
    const int col = 2;

    int pos_arr[row][col] = {
                            {3, 7},
                            {15, 7},
                            {5, 2}
                        };
    
    // first num = dist away from the left side
    // second num = dist away from the bottom edge
    
    int my_pos[row][col] = {{0,}, {0,}, {0,}};

    for(int jdx = 0; jdx < row; jdx++){

        for(int idx = 0; idx < col; idx++){
            area += b_area;
            my_pos[jdx][idx] =  pos_arr[jdx][idx];
            printf("%d\n", my_pos[jdx][idx]);
        }

    }

    return 0;
}