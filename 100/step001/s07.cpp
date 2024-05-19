#include <stdio.h>
#include <stdlib.h>

// get_input()
// str_len()
// str_copy()
// create dynamic array
// add_surprise()

// function for input
void get_input( char* buffer ){
    // pointer  to buffer
    char* p_buffer;
    p_buffer = buffer;

    char ch;

    // input using getchar()
    while( ( ch = getchar() ) != '\n' ){
        *p_buffer++ = ch;
    }
}

// returns length of str
int str_len(char* str){
    int count = 0;
    // loops str till null
    while( (*str) != '\0' ){
        count++;
        str++;
    }

    return count;
}

// copies src to dst
void str_cpy(char *src, char *dst){
    // loops src
    for(int idx = 0; idx < str_len(src); idx++){
        dst[idx] = src[idx];
    }
}

// adding ??!
int main(){
    // original
    char buffer[50] = {'\0',};
    // concat to original
    char surprise[] = {'?', '?', '!', '!'};
    // length of surprise
    int surprise_len = str_len(surprise);

    // get input
    get_input(buffer);
    printf("%s\n", buffer);

    // get length
    int size = str_len(buffer);
    printf("%d\n", size);

    // create a dst for buffer
    char *str;
    // malloc for exact length
    str = (char *)malloc(sizeof(char) * (size + surprise_len));

    // copy 
    str_cpy(buffer, str);
    // copy surprise into str
    str_cpy( surprise, &( str[size] ) );
    printf("%s\n", str);

    // free memory
    free(str);

    return 0;
}