#include <stdio.h>

int main(){

    int a;
    double b;

    a = 10;
    b = 3;

    printf("a / b is: %f \n", a / b);
    printf("b/a is: %f \n", b /a);
    printf("a / b is: %d \n", a / b);
    printf("b/a is: %d \n", (int)(b /a) );

    return 0;
}