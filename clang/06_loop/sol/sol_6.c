// 다음 식을 만족하는 자연수 a,b,c 의 개수를 구하여라
//  i) a + b + c = 2000 
// ii) a > b > c, a,b,c 는 모두 자연수

// a + b + c = 2000 
// b + c = 2000 - a
// c = 2000 - a - b

#include <stdio.h>

int main(){
    int a = 0;
    int b = 0;
    int c = 0;



    int sum = 2000;

    for( c = 0; c <= sum; c++ ){

        // printf( "outer : a : %d b : %d c : %d\n", a, b, c );
        for( b = c + 1; b <= sum - c; b++ ){
        //    printf( "inner\n" );
            a = sum - b - c;

            if(a> b){
                printf("a: %d b: %d c: %d\n", a, b, c);

            }
            
        }
    }

    return 0;
}