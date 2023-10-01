#include <stdio.h>

int main(){
    const int row = 3;
    const int col = 2;
    int score[row][col]; // 2d array

    /*
        student             1, 2, 3
        grade type, korean,  math
                   1 99      99
                   2 0       0
                   3 89      1
                 
    */

    for(int i = 0; i < row; i++){ // input the 3 pupils' data
        for( int j = 0; j < col; j++){
            if(j == 0){

                printf("%d th student\'s korean score : ", i+1);
                scanf("%d", &score[i][j]);
            } else {

                printf("%d th student\'s math score : ", i+1);
                scanf("%d", &score[i][j]);
            }

        }

    }
    printf("\n");

    for(int i = 0; i < row; i++){ // output
        printf("%d th student\'s  ", i + 1 );
        for(int j = 0; j < col; j++){
            if(j == 0){
                printf("korean score : %d, ", score[i][j]);

            } else {
                printf("math score : %d ",score[i][j]);

            }     
        }
        printf("\n");
    }


    return 0;
}