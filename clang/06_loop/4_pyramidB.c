#include <stdio.h>

//     *
//   * *
// * * *

int main(){
    /*
    
    int size = 3;

    // Outer
    for (int row = 0; row < size; row++){
        // Inner
        int col;
        for(col = 2; col > row; col--){
            // spaces
            printf("  ");
        }
        for(int times = 0; times < (col * 2 + 1 - row); times++){
            // actual markings
            printf("* ");
        }
        printf("\n");

    //     for (col = size - row + 1; col > row; col--){
    //         printf("%d", col);
    //     }
    //     for(int times = 0; times < (col + 1 -row); times++){
    //         printf("* ");
    //     }   
    //     printf("\n");
    // }
    }
    */


   // Case 01.
   int size = 3;

   for( int row = 0; row < 3; row++ ) {
    for( int col = 3; col > 0; col-- ) {

        if( ( row + 1 - col ) < 0 ) {
            printf( " " );

        } else {
            printf( "*" );
        }
    }
    printf( "\n" );
   }

   // Case 02.
   /*
   int size = 3;
   char p;

   for( int row = 0; row < 3; row++ ) {
    for( int col = 3; col > 0; col-- ) {

        p =  ( ( row + 1 - col ) < 0 )? ' ' : '*';

        printf( "%c", p );
        // printf( "%c", ( ( row + 1 - col ) < 0 )? ' ' : '*' );
        // %d %f %x %o %b %c
    }
    printf( "\n" );
   }
   */

    return 0;
}