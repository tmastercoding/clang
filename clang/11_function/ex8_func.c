#include <stdio.h>

// prototype
int swap(int *p_pre, int *p_post);

int main(){
    int pre = 3;
    int post = 5;

    printf("before call: pre: %d, post: %d\n", pre, post);

    swap(&pre, &post);

    printf("after call: pre: %d, post: %d\n", pre, post);

    return 0;
}

int swap(int *p_pre, int *p_post){
    int temp = *p_pre;

    *p_pre = *p_post;
    *p_post = temp;

    return 0;
}
