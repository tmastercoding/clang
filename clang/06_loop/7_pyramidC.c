// * * *
// * * 
// *


// *
// * *
// * * *

//     *
//   * *
// * * *
#include <stdio.h>

int main(){
    int size = 3;

    for(int row = 0; row < size; row++ ){
        for(int col = 3; col > row; col--){
            printf("* ");
        }
        printf("\n");
    }

    return 0;
}