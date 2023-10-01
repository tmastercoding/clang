#include <stdio.h>

int main(){
    int num;
    char c;

    printf("input a number: ");
    scanf("%d", &num);

    fflush( stdin );

    printf("input a number: ");
    scanf("%c", &c);

    printf("num: %d\n c: %c", num, c);

    return 0;
}