#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* getBinary(int num);

int main(){
    char* buffer = NULL;
    size_t size = 0;
    int isPalindrome = 1;

    getline(&buffer, &size, stdin);
    size = strlen(buffer)-1;

    for(int idx = 0; idx<size/2; idx++){
        // debug code:
        // printf("%c %d\n", buffer[idx], ~buffer[size-idx-1]);
        // printf("%s %s\n", getBinary(buffer[idx]), getBinary(~buffer[size-idx-1]));
        if(buffer[idx] & ~buffer[size-idx-1]){
            isPalindrome = 0;
            break;
        }
    }    
    printf("%d\n", isPalindrome);
    return 0;
}

char* getBinary(int num){
    // 5 = 101
    // 5 = 010
    // 7 = 111
    // 111 & 1
    // 0111 & 1111 = 0111 

    int temp = num;
    int count = 0;
    char buffer[100] = {'\0',};
    while(temp > 0){
        buffer[count++] = (temp & 1) + '0';
        temp >>= 1;
    }

    char* binary = (char* )malloc(sizeof(char) * count);
    for(int idx = 0; idx < count; idx++){
        binary[idx] = buffer[count-idx-1];
    }

    return binary;
}

