#include <stdio.h>

int main(){
    int a;
    int b;
    int* p;

    p = &a;
    *p = 2;

    p = &b;
    *p = 4;

    printf("a : %d \n", a);
    printf("b : %d \n", b);

    a++;
    b++;

    printf("a : %d \n", a);
    printf("b : %d \n", b);
    printf("*p : %d \n", *p);


    return 0;
}