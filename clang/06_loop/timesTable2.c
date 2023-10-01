#include <stdio.h>

int main(){

    // Outer Column
    for (int post = 0; post <= 9; post++){
        // Inner Row
        for ( int pre = 2; pre <= 9; pre++){

            if ( post == 0){
                printf("%d times table\t",  pre );
            }
            else {
                printf("%2d x%2d = %2d\t", pre, post, pre * post );
            }
        }
        printf( "\n" );

    }

    return 0;
}