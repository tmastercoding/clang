#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    char* line = NULL;
    size_t len = 0;
    
    const int size = 'z' - 'a' + 1;

    int arr[size];

    // init
    for( int idx=0; idx < size; idx++ ) {
        arr[idx] = -1;
    }

    // write log
    if( getline( &line, &len, stdin) != -1 ) {
        if( !isAllLowerCase()  ) {

        } else if( len <= 100 ) {
            
        } else {

            for( size_t idx = 0; idx < len; idx++ ) {
                if( line[idx] - 'a' >= 0 ) {

                    arr[line[idx] - 'a'] = idx;
                }
            }

            // print result
            for( int idx = 0; idx < size; idx++ ) {
                printf( "%d ", arr[idx] );
            }

            printf("\n");
        }

    } else {

    }

    free( line );

    return 0;
}
