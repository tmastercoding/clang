#include <stdio.h>

int main(){

    for ( int i = 2; i <= 9; i++){
        printf("%d times table\n", i);
        
        for (int m = 1; m <= 9; m++){
            
            printf("%d * %d = %d\n", i, m, i*m);
        }

    }

    return 0;
}