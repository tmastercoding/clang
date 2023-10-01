// 자기 자신을 호출하는 함수를 이용해서 
// 1 부터 특정한 수까지의 곱을 구하는 프로그램을 만들어보 세요. (난이도 : 下)

#include <stdio.h>

int multiply(int num);

int main(){

    const int number = 4;

    printf(" %d\n", multiply( number ) );
    
    return 0;
}

int multiply(int num) {
    if( num > 1 ) {
        return num * multiply( num - 1 );
    } else {
        return num;
    }

}
