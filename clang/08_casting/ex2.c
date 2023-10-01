#include <stdio.h>

int main(){
    int a, b;
    float c,d;

    printf("input two numbers: \n");
    scanf("%d %d", &a, &b);

    c = a / b;

    d = (float)a / b;

    printf("two numbers\' ratio: %f %f\n", c, d);

    return 0;
}