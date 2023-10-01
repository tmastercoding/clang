#include <stdio.h>

int main(){

    int a = 10;

    int* ptr;
    ptr = &a;

    *ptr += 1;

    printf("*ptr: %d\n", *ptr);

    (*ptr)++;

    printf("*ptr: %d\n", *ptr);

    printf("*ptr addr: %p\n", ptr);
    ptr++;
    printf("*ptr addr: %p\n", ptr);
    ptr+=3;
    printf("*ptr addr: %p\n", ptr);

    float fa = 10;
    float* fptr= &fa;

    printf("*fptr addr: %p\n", fptr);
    fptr++;
    printf("*fptr addr: %p\n", fptr);
    fptr+=2;
    printf("*fptr addr: %p\n", fptr);

    int ar[2] ={ 1, 9 };
    int* par = ar;

    printf( "%p ar value\n", ar );

    printf("*pptr addr: %d\n", *par);
    par++;
    printf("*pptr addr: %d\n", *par);






    return 0;
}