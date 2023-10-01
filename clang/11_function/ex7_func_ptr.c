#include <stdio.h>

int change_val(int *pi);

int main(){
    int i = 0;

    printf("i\'s address: %p\n", &i);
    printf("before call i value: %d\n", i);
    change_val(&i);
    printf("after call i value: %d\n", i);

    return 0;
}

int change_val(int *pi){
    printf("---- inside change_val function ------\n");
    printf("pi\'s value: %p\n", pi);
    printf("pi\'s point value: %d\n", *pi);

    *pi = 3;

    printf("------ end of change_val function----------\n");

    return 0;
}
