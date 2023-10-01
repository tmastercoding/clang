#include <stdio.h>

int main(){
    int size = 9;
    int py_size = (size) / 2;
    int col_size = py_size * 2 - 1;
    int stump_size = size - py_size + 0.5;

    for(int row = size -1; row > -1; row--){
        for(int col = 0; col < size; col++){

            // if () {
            //     // 피라미드  상단
            // }
            // if (/* condition */)
            // {
            //     /* center */
            // }
            // if(){
            //     // bottom
            // }
            

            if(row > py_size -1){
                if( ( (row -py_size-0.5) > col)  || ( ( col_size - (row-py_size-0.5) + 1 ) < col )) {
                    printf("_ ");
                } else{
                    printf("* ");
                }
            } else{
                if((col>stump_size )|| (col + stump_size - 0.5<stump_size)){
                    printf("_ ");
                }else{
                    printf("* ");
                }
            }
        }
        printf("%d \n", row);
    }


    return 0;
}