// 100 이하의 수 들중  
// prime 인 수만 출력하는 프로그램을 작성하세요.

#include <stdio.h>

int main(){
    int max_number = 100;

    // scanf("%d", number);

    int not_prime = 0;
    for(int number = 2; number <= max_number; number++){
        // printf("outer\n");
        not_prime = 0;
        for(int check = 2; check <= number ; check++){
            // printf("inner\n");

            if (number% check == 0 && number!=check){
                not_prime++;
            }

        }
        
        // if number is prime
        if (not_prime == 0){
            printf("%d is prime\n", number);
        } 
        // else{
        //     printf("number is not prime\n");
        // }    
    }



    return 0;
}