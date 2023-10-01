#include <stdio.h>
#include <stdlib.h>

/*
    If array is a secondary array you should:

    1. Allocate from the starting index to the last index

    2. To free, free from the last index to starting index
     
    FILO: First In Last Out

*/

int main(int argc, char **argv){
    int i;
    int x, y;
    int **arr; // arr[x][y]

    printf("we are going to make arr[x][y].\n");
    scanf("%d %d", &x, &y);

    arr = (int **)malloc(sizeof(int *) * x);
    
    for (i = 0; i < x; i++){
        arr[i] = (int *)malloc(sizeof(int) * y);
    }
    
    printf("created!\n");

    for(i = 0; i < x; i++){
        free(arr[i]);
    }

    free(arr);

    return 0;
}