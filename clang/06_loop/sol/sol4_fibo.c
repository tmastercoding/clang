// 1,000,000 이하의 피보나치 수열 O
// ( N번째항이 N - 1번째항과 N - 2번째 항으로 표현되는 수열, O
// 시작은 1,1,2,3,5,8,...) 의 `짝수` 항들의 합을 구한다 O
// first number 1, second number 1

#include <stdio.h>

int main(){
    int first = 1;
    int second = 1;

    int next = first + second;

    int max = 1000000;

    int sum = 0;

    // printf( "%d %d ", first, second );
    while( next<= max){
        next = first + second;

        first = second;

        second = next;
        
        if( !( next & 1 )){
            // printf("%d ", next);
            sum += next;
        }

    }
    printf("%d \n", sum);

    return 0;
}


