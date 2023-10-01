#include <stdio.h>
// * * *
//   * *
//     *
/*
int main(){
    int size = 3;

    for(int row = 0; row < size; row++){
        for(int col = 0; col < row; col++){
            // spaces
            printf("  ");
        }

        for(int times = 3; times > row; times--){
            printf("* ");
        }
        printf("\n");
    }

    return 0;
}
*/

int main(){
    int size = 0;

    for( int row = 0; row< 3; row++){
        for( int col = 3; col > 0; col--){

            // if (spaces)
            if( row <= col ){
                printf("*");
            } else{
                printf("_");
            }
            // else (markings)

        }
        printf("\n");
    }

    return 0;
}