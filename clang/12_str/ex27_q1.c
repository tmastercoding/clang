#include <stdio.h>
// 길이가 최대 100 인 문자열을
// 하나 입력 받아서 문자열을 역순으로 출력하는 함수를 만들어보세요.
// (난이도 : 下)예를 들어서 "abcde" 입력 –> "edcba" 출력

/*
abc
cba

abcd

1st and 4th swap

dbca

2nd  and 3rd swap

dcba

*/
int len(char *pre);
int reverse(char *str);
int swap(char *pre, char *post);

int main(){
    char str[] = {"abcde"};
    reverse(str);
    printf("%s", str);

    return 0;
}

int len(char *pre){
    int len = 0;
    while(*pre != '\0'){
        len++;
        pre++;
    }
    return len+1;
}

// int reverse(char *str){
//     int size = len(str);
//     if (size>100){
//         printf("input larger than limit\n");
//         return 0;
//     }
//     for(int idx = size; idx >= 0; idx--){
//         printf("%c, %c\n",str[idx], str[size-idx]);
//     }

//     return 1;

// }

int test(char*str){
    int length = len(str);

    while( length > -1 ) {
        printf( "%c", *(str + length--) );
    }
    

    return 1;

}
int reverse(char*str){
    int length = len(str);
    // char temp;

    for(int idx = 0; idx < (length)/2; idx++){
        // debug code value by index
        printf( "index : [%d], value : [%c]\n", idx, *(str+idx) );
        // debug code: index to index
        printf( "pre-index : [%d], pre-index : [%d]\n", idx, length -2  -idx );

        // temp = *(str+idx);
        // *(str+idx) = *(str + length-2 - idx);
        // *(str + length -2 - idx) = temp;

        swap( (str+idx), (str + length-2 - idx) );


        // swap(&(str[idx]), &(str[length-3-idx]));
    }    

    return 1;

}

int swap(char *pre, char *post){
    char temp = *pre;
    *pre = *post;
    *post = temp;

    return 1;
}