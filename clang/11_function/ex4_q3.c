#include <stdio.h>

// 1 부터 n 까지의 합을 구하는 함수를 작성해보세요. 
// (난이도: 下1부터n까지의합을구하는 함수를 작성해보세요. 
// 수학적인 공식을 써도 되지만 for 문으로 작성하는 것이 연습 하는데에는 도움이 될듯 합니다

int f_sum( int n){

    int sum = 0;
 
    for(int i = 1; i < n+1; i++ ){
        sum += i;

    }

    return sum;
}

int main(){
    int sum;
    int n = 4;
    sum = f_sum(n);

    printf("%d\n", sum);


    return 0;
}