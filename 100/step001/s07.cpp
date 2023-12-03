#include <stdio.h>
#include <stdlib.h>

// get_input()
// str_len()
// str_copy()
// create dynamic array
// add_surprise()
 
void get_input( char* buffer ){
    char* p_buffer;
    p_buffer = buffer;

    char ch;

    while( ( ch = getchar() ) != '\n' ){
        *p_buffer++ = ch;
    }
}

int str_len(char* str){
    int count = 0;
    while( (*str) != '\0' ){
        count++;
        str++;
    }

    return count;
}

void str_cpy(char *src, char *dst){
    for(int idx = 0; idx < str_len(src); idx++){
        dst[idx] = src[idx];
    }
}

int main(){
    char buffer[50] = {'\0',};
    char surprise[] = {'?', '?', '!', '!'};
    int surprise_len = str_len(surprise);

    get_input(buffer);
    printf("%s\n", buffer);

    int size = str_len(buffer);
    printf("%d\n", size);

    char *str;
    str = (char *)malloc(sizeof(char) * (size + surprise_len));

    str_cpy(buffer, str);
    str_cpy( surprise, &( str[size] ) );
    printf("%s\n", str);

    free(str);

    return 0;
}