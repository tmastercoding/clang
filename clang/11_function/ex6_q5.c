#include <stdio.h>
// 특정한수 N을 입력받아서 
// N을 소인수분해한 결과가 출력되게 해보세요
// 예) factorize(10); 출력결과 : 2 Œ 5
// factorize(180);출력결과: 2Œ2Œ3Œ3Œ5

int try(int i);
int factorize(int i);

int main(){
    factorize(180);
    return 0;
}


int try(int i){

    for(int count = 2; count < i + 1; count++){

        if(!(i % count)){
            return count;
        }

    }
}
int factorize(int i){

    while(i > 1){
        int temp = try(i);

        printf("%d Œ ", temp);

        i /= temp;
    }

    printf("\n");

    return 0;
}
