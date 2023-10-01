#include <stdio.h>

int main(){
    int row = 0;
    int size = 3;
    int col = 0;

    // Outer
    do{
        // inner
        do{
            printf("* ");
        } while(++col < row + 1);
        
        printf("\n");
        col = 0;

    } while(++row < size);

    return 0;
}