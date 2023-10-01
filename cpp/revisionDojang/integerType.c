#include <stdio.h>
#include <limits.h>

void ex00(){
    char num1 = CHAR_MIN;
    short num2 = SHRT_MIN;
    int num3 = INT_MIN;
    long num4 = LONG_MIN;
    long long num5 = LLONG_MIN;

    printf("Char : %d\nShort : %d\nInt : %d\nLong : %ld\nLong Long : %lld", num1, num2, num3, num4, num5);
}

void ex01(){
    unsigned char num1 = 256;
    unsigned short num2 = 65536;
    long long int num3 = 9223372036854775808;

    printf("%u %u %lld", num1, num2, num3);
}

// void ex02(){
//     short num1

//     printf("%u %u %lld", num1, num2, num3);
// }

int main(){
    int num1 = 2;
    num1 = num1++ + ++num1;
    printf("%d\n", num1);
    return 0;
}