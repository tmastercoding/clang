#include <stdio.h>
int main(){
    int a;
    int* pa = &a;
    int* pb;

    *pa = 3;
    pb = pa;

    printf("pa is pointing to: %d \n", *pa);
    printf("pb is pointing to: %d \n", *pb);

    return 0;
}