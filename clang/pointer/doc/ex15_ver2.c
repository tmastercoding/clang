 #include <stdio.h>

int main(){
    /*
        1   2   3   4   5
        16  17  18  19  6
        15  24  25  20  7
        14  23  22  21  8
        13  12  11  10  9
    */

    // RIGHT DOWN LEFT UP
   
    const int size = 5;

    int arr[size][size] = {
                            {1, 2, 3, 4, 5},
                            {6, 7, 8, 9, 10},
                            {11, 12, 13, 14, 15},
                            {16, 17, 18, 19, 20},
                            {21, 22, 23, 24, 25}   
                        };

    // ouput

    int out[size][size] = {0,};

    int way = 0;
    int len = size - 1;
    int coords[2] = {0, };
    int row;
    int col;

    while(len > 1){
        printf("len: %d\n", len);
        printf("coords: %d, %d\n", coords[0], coord[1]);

        for(int row = coords[0]; row < size; row++){
            for(int col = coords[1]; col < size; col++){
                printf("%2d ", out[row][col]);
            }
            printf("\n");
        }

        for(row; row < len; row++){
            way++;

            for(col = coords[1]; col < len; col++){

                if( way == 1 ){ // going right
                    out[row][col] = arr[row][col];

                } else if( way == 2 ){ // going down
                    out[col][size-row] = arr[row][col-row];

                } else if( way == 3){ // going left
                    out[size-row + 1][size-col - 1] = arr[row][col - row];

                } else if( way == 4 ){ // going up
                    out[size-col - 1][size - row - 2] = arr[row][col -row ];

                }

            }


            for(int row = 0; row < size; row++){
                for(int col = 0; col < size; col++){
                    printf("%2d ", out[row][col]);
                }
                printf("\n");
            }

        }

        coords[0] = row;
        coords[1] = col;
        len /= 2;

    }





    return 0;
}