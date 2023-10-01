#include <stdio.h>

int main() {
    
    int ar[5][5];

    int number = 1;

    for( int i = 0; i < 5; i++ ) {
        for( int j = 0; j < 5; j++ ) {
            ar[i][j]= number++;
            printf( "%2d ", ar[i][j]);
        }
        printf( "\n");
    }
    return 0;
}