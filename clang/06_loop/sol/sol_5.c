// 사용자로 부터 N 값을 입력 받고 1 부터 N 까지의 곱을 출력한다.
// e.g. input = 3, 1 x 2 x 3

#include <stdio.h>

int main(){
    int max;
    scanf("%d", &max);

    int result = 1;
    int num = 1;

    // for(; num <= max; num++){
    //     result *= num;
    // }

    // while(num <= max){
    //     result *= num;
    //     num++;
    // }

    while(num <= max){
        result *= num++;
    }

    printf("%d\n", result);

    return 0;
}