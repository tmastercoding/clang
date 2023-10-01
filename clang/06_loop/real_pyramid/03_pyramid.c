#include <stdio.h>

int main(){
    int size;

    printf("pls input number of rows or size\n> ");
    scanf("%d", &size);

    int col_size = (int)((size + 1) / 2);

    for(int row = 0; row < size; row++){
        for(int col = 0; col < col_size; col++){

            if( (size < (row+col + 1)) || (col > row)){
                printf("  ");
            } else{
                printf("* ");
            }
            // USING Ternary
            // ( (size < (row+col + 1)) || (col > row))? printf("_ "):printf("* ");
        }
        printf("\n");
    }

    return 0;
}

for ( a ; b; c ) {
    code_block
}

a
while ( b ) {
    code_block
    c
}

a
do {
    code_block
    c
} while( b ( -1 ) )