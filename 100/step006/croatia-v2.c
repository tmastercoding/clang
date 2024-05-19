#include <stdio.h>
#include <string.h>

int main() {
    const int chs_size = 8;
    char chs[chs_size][4] = { "c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z=" };
    int size_of_input = 0;
    int count_of_ch = 0;
    int size_of_keyword = 0;

    // char target[] = "ljes=njak";
    char* target = NULL;
    size_t size = 0;
    getline(&target, &size, stdin);
    printf("%s\n", target);

    for( int idx = 0; idx < chs_size; idx++ ) {
        printf( "[%s]\n", chs[idx] );
    }

    size_of_input = strlen(target)-1;
    printf("len : %d\n", size_of_input );

    int kdx = 0;
    int isFoundMatch = 0;
    while( kdx < size_of_input )    {
        printf( "begin : %s\n", target+kdx );
        // printf("begin char %c\n", target[kdx]);
        for( int idx = 0; idx < chs_size; idx++ ) {
            size_of_keyword = strlen(chs[idx]);
            printf("%d\n", size_of_keyword);
            for( int jdx = 0; jdx < size_of_keyword; jdx++ ) {
                if( chs[idx][jdx] == target[kdx+jdx] ) {
                    printf("same char %c\n", chs[idx][jdx] );
                    if( chs[idx][jdx+1] == '\0') {
                        count_of_ch++;
                        kdx+=jdx;
                        isFoundMatch = 1;
                        break;
                    }
                } else{
                    break;
                }
            } 
            if (isFoundMatch){
                break;
            } 
        }
        if(!isFoundMatch){
            // printf("one letter char %c\n", target[kdx]);
            count_of_ch++;
        }

        isFoundMatch = 0;
        kdx++;
    }

    printf( "%d\n", count_of_ch );

    return 0;
}