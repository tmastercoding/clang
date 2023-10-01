#include <stdio.h>

int main(){
    void *a;
    double b = 123.3;

    a = &b;

    printf("%lf", *( ( double * )a ) );

    return 0;
}