// N 진법에서 M 진법으로 변환하는 프로그램을 만들어보세요. (난이도 : 中)

#include <stdio.h>

int main(){

    char c = '\0';
    char d = 0;

    // printf("%s", "Apple");
    // printf("\n");

    char text[20] = { 'A', 'p', 'p', 'l', 'e', 0,'A', 'p', 'p', 'l', 'e', 0};

    // printf("%s", text);

    char *ptext = text;

    while( *ptext ) {
        printf( "%c", *ptext );
        *(ptext++);
    }

    printf("\n");

    return 0;
}