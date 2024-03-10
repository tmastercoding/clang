#include <stdio.h>

int main(){
    /* ver 1
    long nc;

    nc = 0;
    while(getchar() != '\n')
        ++nc;
    
    // ld meanings long integer
    printf("%ld\n", nc);
    */

    // ver 2
    double nc;

    for(nc = 0; getchar()!='\n'; ++nc)
        // null statement
        ;

    // only prints whole number part
    printf("%.0f\n", nc);

    return 0;
}