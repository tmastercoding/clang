#include <stdio.h>

// int temp( int size, char **text );

// Q. program 이 실행 될때, 
// parameter ( 인자 ) 로 first_name 과 last_name 을 입력 받아
// "Your name is first_name last_name" 이 
// 화면에 출력되도록 하세요

char *secret_key = "123ok";

int main( int argc, char **argv ){
    printf("argurments recieved: %d \n", argc);
    // printf("program's pathway : %s \n", argv[0]);
    printf("Your name is %s %s.\n", argv[1], argv[2]);
    return 0;
}