#include <stdio.h>

int main(){
    int size = 0;
    int length = 0;

    scanf("%d", &size);
    length = size*2-2;
    
    for(int row = length; row > -1; row--){
        for(int col = 0; col < length+1; col++){
            if (row - size+1 >col){
                printf(" ");
            } else if (length-row-size+1>col){
                printf(" ");
            } else if ((length+size > length-row+col) && (length+size > row+col)){
                printf("*");
            }
        }
        printf("\n");
    }

    return 0;
}