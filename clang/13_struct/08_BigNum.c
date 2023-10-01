#include <stdio.h>

struct BigNum {
    int i_digit[100]; // real part
    int d_digit[100]; // image part
    
    int i_total_digit; // the amount of digits being used (real)
    int d_total_digit; // the amount of digits being used (image)
    
    char sign; // positive = 1; negative = 0;

}; 

int printBigNum(struct BigNum *num);
int addBigNum(struct BigNum *pre, struct BigNum *post);
// 123.045

int main(){
    struct BigNum num;

    num.i_total_digit = 3;

    for(int pos = 0; pos < 100 - num.i_total_digit; pos++){
        num.i_digit[pos] = 0;
    }

    num.i_digit[97] = 1;
    num.i_digit[98] = 2;
    num.i_digit[99] = 3;

    num.d_total_digit = 3;

    for(int pos = 0; pos < 100; pos++){
        num.d_digit[pos] = 0;
    }

    num.d_digit[0] = 0;
    num.d_digit[1] = 4;
    num.d_digit[2] = 5;

    num.sign = '1';

    printBigNum(&num);
}

int printBigNum(struct BigNum *num){
    if ( !( num->sign ) ){
        printf("-");
    }
                                
    for(int pos = 0; pos < num->i_total_digit; pos++){
        printf("%d", num -> i_digit[100-(num -> i_total_digit - pos)]);
    } 
    
    if(num->d_total_digit){
        printf(".");

        for(int pos = 0; pos < num -> d_total_digit; pos++){
            printf("%d", num->d_digit[pos]);
        }
    }

    printf("\n");

    return 1;
}

int addBigNum(struct BigNum *pre, struct BigNum *post){
    if(pre->d_total_digit || post->d_total_digit){
        if(pre ->)

    }
}
