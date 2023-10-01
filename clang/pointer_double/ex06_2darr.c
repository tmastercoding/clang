#include <stdio.h>

int main(){
    int arr[2][3] = {
                        {1, 2, 3},
                        {4, 5, 6}
                    };

    printf("total size: %lu \n", sizeof(arr));
    printf("total number of col: %lu \n", sizeof(arr[0])/ sizeof(arr[0][0]));
    printf("total number of row: %lu \n", sizeof(arr)/sizeof(arr[0]));

    return 0;
}