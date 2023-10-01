// 1000 이하의 3 또는 5 의 배수인 자연수들의 합을 구한다.
#include <stdio.h>

/*
 as clang
 there is not Boolean type
 true ? ! 0
 false ? 0
*/
int main(){
    int max = 1000;
    int sum = 0;
    
    for(int num = 3; num <= max; num++){

        if( !(num % 3) || !( num % 5 )){
        // if((num % 3 == 0)||(num % 5 == 0)){
            // printf("%d ", num);
            sum += num;
        }

        // sum  += ( !(num % 3) || !( num % 5 )) 
        //         ? num 
        //         : 0; 

    }
    printf("sum is : %d\n", sum);

    printf( " true false : %d\n", 10 == 0);

    return 0;
}