#include <stdio.h>

struct test{
    int a, b;
};

int main(){
    struct test st;
    struct test *ptr;

    ptr = &st;

    (*ptr).a = 1;
    (*ptr).b =2;

    ptr->a = 3;

    printf("st\'s a member var : %d \n", st.a);
    printf("st\'s b member var : %d \n", st.b);

    return 0;
}