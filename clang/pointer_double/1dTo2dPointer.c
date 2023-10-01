#include <stdio.h>

int main()  {
    int a, b;
    int *ptrA;
    int *ptrB;

    int **ptr2PtrA;
    int **ptr2PtrB;

    ptrA = &a;
    ptrB = &b;

    ptr2PtrA = &ptrA;
    ptr2PtrB = &ptrB;

    a = 10;
    b = 20;

    printf("a addr > %p\n", &a);
    printf("b addr > %p\n", &b);
    printf("\n");

    printf("ptrA refer to addr > %p\n", ptrA);
    printf("ptrB refer to addr > %p\n", ptrB);
    printf("\n");

    printf("ptrA addr > %p\n", &ptrA);
    printf("ptrB addr > %p\n", &ptrB);
    printf("\n");

    printf("*ptr2PtrA refer to addr > %p\n", *ptr2PtrA);
    printf("*ptr2PtrB refer to addr > %p\n", *ptr2PtrB);
    printf("\n");

    printf("ptr2PtrA refer to addr > %p\n", ptr2PtrA);
    printf("ptr2PtrB refer to addr > %p\n", ptr2PtrB);
    printf("\n");

    printf("ptr2PtrA addr > %p\n", &ptr2PtrA);
    printf("ptr2PtrB addr > %p\n", &ptr2PtrB);
    printf("\n");

    printf("**ptr2PtrA refer to addr > %d\n", **ptr2PtrA);
    printf("**ptr2PtrB refer to addr > %d\n", **ptr2PtrB);

    return 0;
}