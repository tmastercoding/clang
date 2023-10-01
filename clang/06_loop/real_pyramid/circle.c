#include <stdio.h>

int main(){
    int size = 5;

    for(int row=0; row < size; row++){
        for(int col=0; col<size; col++){
            if(((col+row) == size-5) || ((col+row) > (size + 2)) || ((col-row) == size-1)){
                printf("_ ");
            } else {
                printf("* ");
            }
        }
        printf("\n");
    }

    return 0;
}