// N값을 입력 받아서 1부터 N까지의 
// 소수의 개수를 출력하는 함수를 제작해보세요
#include <stdio.h>

// prototype
int is_Prime(int i);

// checks if num = prime

int num_Prime(int num);

int main(){
    int sum = 0;
    int num = 5;
    sum = num_Prime(num);

    printf("%d\n", sum);

    return 0;
}

int is_Prime(int i){
    int bool = 0;
    int count = 0;
    for(int check = 2; check < i+1; check++){
        if(i % check <= 1){
            count++;
        }
    }

    if(count > 1){
        bool = 1;
    }

    return bool;
}

int num_Prime(int num){
    int count = 0;
    
    if(num > 1){
        for(int i = 2; i < num+1; i++){
            printf("%d\n", is_Prime(i));
            if(is_Prime(i)){
                count++;
            }
        }
    }

    return count;

}