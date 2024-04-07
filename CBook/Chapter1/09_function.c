#include <stdio.h>

// prototype of func
int power(int base, int exponent);

int main(){
    int i;
    
    for(i = 0; i < 10; ++i){
        // arguments - var named when calling
        printf("%d %d %d\n", i, power(2, i), power(-3, i)); 
    }
    return 0;
}

// Parameters - var named in the paranthesis
int power(int base, int exponent){
    int i, p;

    p = 1;
    for(i = 1; i <= exponent; ++i)
        p = p*base;

    return p;
}