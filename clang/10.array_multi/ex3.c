#include <stdio.h>

int main(){
    const int row = 3;
    const int col = 3;

    int arr1[row][col] = {
                            {12, 33, 55},
                            {45, 66, 74},
                            {12, 54, 56}
                        };

    int arr2[row][col] = {
                            {12, 54, 56},
                            {12, 33, 55},
                            {45, 66, 74}
                        };

    for(int idx = 0; idx < row; idx++){
        for(int jdx = 0; jdx < col;  jdx++){
            printf("%d, ", arr1[idx][jdx] + arr2[idx][jdx]);
        }
        printf("\n");
    }

    return 0;
}