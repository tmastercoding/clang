#include <stdio.h> 

// What is the largest prime factor of the number 600851475143 ?

int main(){
    int count = 2;
    long num = 600851475143;

    while(num > 1){
        count = 2;
        while(count <= num){

            if( !(num % count) ){
                int pcount = 1;
                while(){

                }

                printf("%d\n", count);
                num /= count;
                break;
            }
            count++;
        }
    }

    return 0;
}