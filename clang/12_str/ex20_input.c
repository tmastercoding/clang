#include <stdio.h>

int main(){
    char words[5];
    char* p = words;

    printf("input a string within 30 characters! : ");
    scanf("%s", words);

    // printf("string: %s \n", words);

    words[4] = '\0';

    while( *p != '\0'){
        printf("%c", *p);
        p++;
    }

    return 0;
}