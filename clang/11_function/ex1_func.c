#include <stdio.h>

int f_sum( int pre, int post) {
    return pre + post;
}

void f_sum2( int pre, int post){
    // pre + post;

    return;
}

// proto type
float f_avg( int pre, int post );

int main(){

    int pre;
    int post;

    int sum;

    int number;

    printf("input a number\n");
    scanf("%d", &pre );
    scanf("%d", &post);

    sum = pre + post;

    sum = f_sum(pre, post);
    f_sum2(pre, post);

    number = printf("sum: %d\n", sum);

    printf( " how many : %d", number );

    return 0;
}

float f_avg( int pre, int post ) {
    return (pre + post) / 2;
}
