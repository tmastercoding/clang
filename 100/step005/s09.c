#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int reverse_int(char* buffer);

int main(){
    char buffer[100] = {'\0',};
    char c;
    int idx = 0;
    int pre, post = 0;

    while((c = getchar()) != '\n'){
        if(c == ' '){
            // printf("char: '%c'\n", c);
            pre = reverse_int(buffer);

            for(int jdx = 0; jdx < idx; jdx++)
                buffer[jdx] = '\0';

            idx = 0;
        }
        if(c != ' ')
            buffer[idx++] = c;
    }
    // printf("%s\n", buffer);
    post = reverse_int(buffer);
    
    // printf("%d %d\n", pre, post);
    printf("%d\n", (pre>post)? pre : post);
    return 0;
}

int reverse_int(char* buffer){
    int num = 0;
    int temp = 0;
    int size = strlen(buffer);

    for(int idx = size-1; idx >= 0; idx--){
        temp = buffer[idx]-'0';
        num = num*10 + temp;
    }

    return num;
}