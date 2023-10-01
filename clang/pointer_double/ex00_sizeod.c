#include <stdio.h>

int main(){

    int i;

    int ar[] = {1,2,3};

    printf( "i size of %lu\n", sizeof(i) );
    printf( "ar size of %lu\n", sizeof(ar)/sizeof(int) );

    return 0;
}