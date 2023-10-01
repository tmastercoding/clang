#include <stdio.h>

int main(){
    int* p;
    int a;

    p = &a;

    a = 10;

    printf("p\'s value: %d\n", *p);

    printf("a\'s address: %p\n", &a);

    printf("p\'s address: %p\n", p);
    printf("p\'s address: %p\n", &p);

    return 0;
}