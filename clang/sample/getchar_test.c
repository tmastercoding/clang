#include <stdio.h>

int input( char* msg, char* source, int size);

int main(){
    // printf("input: ");

    // char book_name[100];
    // char p_book_name = book_name;

    // for(int pos = 0; pos < 100; pos++){
    //     *p_book_name = get_char();
    //     if(*p_book_name = '\n'){
    //         break;
    //     }
    // }

    const int size = 50;
    // char ch;
    // char buffer[size] = {0,};

    // int i = 0;
    // while(i < size-1 & (ch = getchar() ) != '\n'){
    //     buffer[i++]= ch;
    // }    

    // buffer[i] = '\0';

    // printf("output: %s\n", buffer);

    char source[size] = {0,};

    input( "ibook name : ", source, size);
    printf("output: %s\n", source);

    return 0;
}

int input( char* msg, char* source, int size){
    char ch;
    char buffer[size];

    int idx = 0;

    printf( "%s", msg );

    while(idx < size-1 & (ch = getchar()) != '\n'){
        buffer[idx++] = ch;
    }

    buffer[idx] = '\0';

    for(int jdx = 0; jdx < idx+1; jdx++){
        *(source + jdx) = buffer[jdx];
    }

    return 0;
}