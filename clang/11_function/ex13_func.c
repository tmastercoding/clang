#include <stdio.h>

int pswap(int **pa, int **pb);

int main(){

    int a = 3, b = 5;

    int *pa, *pb;
    
    pa = &a;
    pb = &b;

    printf("a address : %p \n", &a);
    printf("pa is pointing to: %p \n", pa);
    printf("pa address: %p \n", &pa);

    printf("b address : %p \n", &b);
    printf("pb pointing to: %p \n", pb);
    printf("pb address: %p\n", &pb);

    printf("------- call func ---------\n");
    pswap(&pa, &pb);
    printf("------- afte call ---------\n");

    printf("a address : %p \n", &a);
    printf("pa is pointing to: %p \n", pa);
    printf("pa address: %p \n", &pa);

    printf("b address : %p \n", &b);
    printf("pb pointing to: %p \n", pb);
    printf("pb address: %p\n", &pb);

    return 0;
}

int pswap(int **ppa, int **ppb){
    int *temp = *ppa;

    printf("ppa is pointing to address: %p \n", ppa);
    printf("ppb is pointing to: %p \n", ppb);

    printf("*ppa is pointing to address: %p \n", *ppa);
    printf("*ppb is pointing to: %p \n", *ppb);

    printf("a is pointing to address: %d \n", **ppa);
    printf("b is pointing to: %d \n", **ppb);

    *ppa = *ppb;
    *ppb = temp;

    return 0;
}