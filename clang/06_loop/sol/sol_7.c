// 임의의 자연수 N을 입력받아 N을 소인수 분해한 결과를 출력하여라. 
// 예를 들어서 N = 18일 경우,
// N = 18 = 2 * 3 * 3

// #include <stdio.h>

// int main(){
//     int num = 120;
    
//     // int result = num;
//     while (num > 1){

//         for(int prime = 2; prime < num/2; prime++ ){
//             if(num % prime == 0){
//                 // printf("test num: %d\n", prime);
//                 int is_prime = 0;
//                 for(int check = 2; check < prime ; check++){
//                     if (prime% check == 0){
//                         is_prime++;
//                     }

//                 }
//                 // if number is prime
//                 if (is_prime == 0){
//                     printf("prime: %d \n", prime);
//                     num /= prime;
//                 }
//             }
//         }
//     }
//     // printf("prime: %d\n", num/result);

//     return 0;
// }

// 100 이하의 수 들중  
// prime 인 수만 출력하는 프로그램을 작성하세요.

#include <stdio.h>

int main(){
    int num;

    // is_prime variable initialize by 0-> false
    int is_prime = 0;

    printf("Pls input a number \n>");
    scanf("%d", &num);

    if (num >1){
        while(num != 1){
        // printf("num: %d\n", num);
        // for(int test = 2; test < num/2; test++ ){

            for(int test = 2; test <= num; test++ ){
                if(num % test == 0){
                    // printf("test: %d\n", test);
                    is_prime = 0;

                    for(int check = 2; check < test ; check++){
                        // printf("%d\n", test);
                        if (test% check == 0){
                            is_prime = 1;
                            break;
                        }

                    }
                    // if number is prime
                    if (is_prime == 0){
                        printf("prime: %d \n", test);
                        num /= test;
                        // printf("num: %d\n", num);
                        break;
                    }
                }
            }
        };
    }

    // int result = num;

    // printf("prime: %d\n", num/result);

    return 0;
}