#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(){
    long long num1;
    char text[30];

    printf("Input integer: ");
    scanf("%lld", &num1);
    printf("%lld\n", num1);

    // long long int to string
    sprintf(text, "%lld", num1);

    int length;
    bool isPalindrome = true;
    
    length = strlen(text);

    int begin = 0;
    int end = length - 1;
    while(begin < end){
        if(text[begin] != text[end]){
            isPalindrome = false;
            break;
        }
        begin++;
        end--;
    }

    printf("%d\n", isPalindrome);

    return 0;
}