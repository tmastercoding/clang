#include <stdio.h>

int main(){
    const int size = 5;
    int arr[ size ][5];

    const int row = 5;
    const int col = 5;

    int ar[row][col];

    ar[1][2]= 8;

    // 0xff1692 -> hongkong kuryongcity xxx apt 1f # 101

    int apt[0][0];

    int arr2[3][3] = { 
                      { 1, 2, 3 },
                      { 4, 5, 6 },
                      { 7, 8, 9 } 
                    };

    int arr3[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int arr4[3][3][1] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    // int arr5[3][3][1] = {
    //                      { 1}, {2}, {3},{4},{5}, {6}, {7}, {8}, {9}
    // }

    for( int idx=0; idx < 3; idx++) {
        for( int jdx=0; jdx < 3; jdx++) {
            printf("[%d][%d]->%p ->%d\n", idx, jdx, &arr2[idx][jdx], arr2[idx][jdx]);
        }

    }

    int farr[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    for( int idx=0; idx < 9; idx++) {
            printf("[%d]->%p ->%d\n", idx, &farr[idx], farr[idx]);
    }

    // int axis[x][y][z];
    // int axis[z][x][y];
    // int dynamic[t][z][x][y];

    return 0;  
}