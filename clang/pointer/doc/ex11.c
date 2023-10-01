#include <stdio.h>

int main(){
    int a;
    char b;
    double c;
    int* pa = &a;
    char* pb = &b;
    double* pc = &c;

    printf("pa\'s address: %p\n", pa);
    printf("(pa + 1) address: %p \n", pa+1);
    printf("pb\'s address: %p\n", pb);
    printf("(pb + 1) address: %p \n", pb+1);
    printf("pc\'s address: %p\n", pc);
    printf("(pc + 1) address: %p \n", pc+1);

    return 0;
}