#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){
    int SizeOfArray;
    int *arr;
    int arr2[10];

    printf("how much array size do you want? ");
    scanf("%d", &SizeOfArray);

    arr = (int *)malloc(sizeof(int) * SizeOfArray);

    // runtime
    // malloc -> memory allocation

    free(arr);

    return 0;
}
