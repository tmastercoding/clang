#include <stdio.h>

int copy_str(char *dest, char *src);

struct TEST {
    int i;
    char str[20];
};

int main(){
    struct TEST a, b;

    b.i = 3;
    copy_str(b.str, "hello, world");

    // a = b;
    a.i = b.i;
    copy_str(a.str, b.str);

    printf("a.str : %s \n", a.str);
    printf("a.i : %d \n", a.i);
    
    return 0;
}

int copy_str(char *dest, char *src){
    while( *src ){
        *dest = *src;
        src++;
        dest++;
    }

    *dest = '\0';

    return 1;
}