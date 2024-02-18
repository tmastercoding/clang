#include <stdio.h>
#include <stdlib.h>

// reverse func
void reverse(int start, int end, int size, int* arr);

int main(){
    // set vals
    int basketSize = 0;
    int commands = 0;
    int start, end = 0;
    int idx = 0;

    // input vals
    scanf("%d %d", &basketSize, &commands);

    // set array
    int* baskets = (int* )malloc(sizeof(int) * basketSize);

    while(idx < basketSize){
        baskets[idx] = idx+1;
        idx++;
    }

    idx = 0;
    // loop for commands
    while(idx < commands){
        // get input
        scanf("%d %d", &start, &end);
        // call func
        reverse(start, end, basketSize, baskets);

        idx++;
    }

    // ouput
    int jdx = 0;

    while(jdx < basketSize){
        printf("%d\n", baskets[jdx++]);
    }

    return 0;
}

void reverse(int start, int end, int size, int* arr){

    // set variables
    int base = start-1;
    // printf("base: %d\n", base);

    int length = end-base;
    // printf("length: %d\n", length);

    int gap = size-end;
    // printf("gap: %d\n", gap);

    // loop for (start, end) pairs
    for(int idx = 0; idx < length/2; idx++){   
        // printf("start: %d\n", arr[idx+base]);
        // printf("end: %d\n", arr[size-gap-1-idx]);

        // swap
        int temp = (int) (arr[idx+base]);

        arr[idx+base] = (int) (arr[size-gap-1-idx]);
        arr[size-gap-1-idx] = temp;
    }
}