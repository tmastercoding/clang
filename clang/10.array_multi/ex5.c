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

    int measurements[col] = {0,}; 
    // height and length of overlapping area

    for(int jdx = 0; jdx < row; jdx++){
        // int overlap = 1;
        area += b_area;

        for(int idx = 0; idx < col; idx++){
            my_pos[jdx][idx] =  pos_arr[jdx][idx];
            printf("%d\n", my_pos[jdx][idx]);

            if( jdx >= 1 ){ // getting the overlapping area

                for(int left = 0; left < jdx; left++ ){
                    printf("jdx: %d, idx: %d, left:%d\n", jdx, idx, left);

                    if(( ( pos_arr[jdx][idx] > my_pos[left][idx] ) || ( pos_arr[jdx][idx] <= (my_pos[left][idx]+10)) ) && ( ( (pos_arr[jdx][idx]+10) >= my_pos[left][idx] ) && ( pos_arr[jdx][idx] < my_pos[left][idx]) )){
                        printf("(( %d > %d ) and ( %d <= %d)) and (( %d >= %d ) && ( %d < %d))\n", 
                                pos_arr[jdx][idx], 
                                my_pos[left][idx], 
                                pos_arr[jdx][idx], 
                                my_pos[left][idx]+10,
                                pos_arr[jdx][idx]+10,
                                my_pos[left][idx],
                                pos_arr[jdx][idx],
                                my_pos[left][idx]
                                );
                        
                        // overlap *= 10 - my_pos[jdx][idx] - pos_arr[left][idx];
                        measurements[idx] = 10 + my_pos[left][idx] - pos_arr[jdx][idx]; // e.g. height = 10 - 7- 2
                        printf("measurements: %d\n", measurements[idx]);
                        // if(measurements[idx] < 1){
                        //     printf("breaking\n");
                        //     break;
                        // }

                    }
                    
                }
                // printf("overlap: %d\n", overlap);
            }

            
        }
        int overlap = 1;

        for(int len = 0; len < col; len++){
            overlap *= measurements[len];
            printf("len: %d\n", measurements[len]);
        }
        printf("overlap: %d\n", overlap);
        area -= overlap;

        printf("area: %d\n", area);

    }


    return 0;
}