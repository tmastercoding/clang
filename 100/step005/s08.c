#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* strip( const char* str, const char sep );

int main(){
    size_t size = 0;
    char* buffer = NULL;
    char* dst = NULL;
    char sep[] = " ";
    int idx = 0;

    getline(&buffer, &size, stdin);
    buffer[strlen(buffer)-1] = '\0';

    // printf("'%s'", buffer);

    // dst = strip(buffer, ' ');


    // fprintf(stdout, "[%s]", dst);
    // free(dst);

    char* p = strtok(buffer, sep);
    if(p!=0){
        printf("%d word: %s\n", idx, p);
        idx++;
    }
    while(p != 0){
        p = strtok(NULL, sep);
        if(p != 0){
            printf("%d word: %s\n", idx, p);
            idx++;
        }
    }

    printf("idx: %d\n", idx);
    return 0;
}


char* strip( const char* str, const char sep ) {
    int pre_flag = 0;
    int post_flag = 0;
    int pre_index = 0;
    int post_index = strlen( str )-1;

    while( (*str != '\0' ) && (strlen(str)-1 > 0) ) {

        // check space character of front 
        if( *(str + pre_index) == sep && !pre_flag ) {
            pre_index++;
        } else{
            pre_flag = 1;
        }

        // check space character of rear 
        if( *(str + post_index) == sep && !post_flag ) {
            post_index--;
        } else {
            post_flag = 1;
        }
        printf("pre_index: [%d]-[%c]\n", pre_index,  *(str + pre_index));
        printf("post_index: [%d]-[%c]\n", post_index,  *(str + post_index));

        // front >= rear -> all space
        if(pre_index >= post_index || (pre_flag & post_flag)){
            break;
        }    
    }
    printf("pre_index: %d, post_index: %d\n", pre_index, post_index);

    char* temp;
    int substr_size = post_index - pre_index + 2;
    int idx = 0;
    if( substr_size > 2){
        temp = (char*)malloc(sizeof(char) * (substr_size));
        while(idx < substr_size ){
            temp[idx] = *(str+pre_index+idx);

            idx++;
        }
        temp[idx-1] = '\0'; 
    }

    return temp;
}

// char* strip(char* s, const char ch){
//     size_t origin_size = strlen(s);
//     // printf("%d\n", origin_size);
//     while(*s!='\0'){
//         // putchar(*s);
//         // putchar(*(s + strlen(s)-1));
//         // printf("%d\n", origin_size);
//         if(*s == ch){
//             s++;
//             origin_size--;
//         }

//         if(*(s + strlen(s)-1) == ch){
//             *(s + strlen(s)-1) = '\0';
//             origin_size--;
//         }

//         if( (*s != ch) & (*(s + strlen(s)-1) != ch) ) {
//             break;
//         }
//     }
   
//     char* new_str = (char* )malloc(origin_size * sizeof(char));
//     strcpy(new_str, s);

//     return new_str;
// }




// void strip( char* str ) {
//     int flag = 0;
//     int pre_index = 0;
//     int post_index = strlen( str );

//     while( *str != '\0' ) {
//         // check space character of front 
//         if( *(str + pre_index) != ' ' && !flag ) {
//             flag = 1;
//         } else {
//             pre_index++;
//         }

//         // check space character of rear 

//         // front >= rear -> all space
        
//     }
// }
// char* strip(char* s, const char ch){
//     if(*s == ch){
//         return strip(++s, ch);
//     } else{
//         if(*(s + strlen(s)-1) == ch){
//             *(s + strlen(s)-1) = '\0';
//             return strip(s, ch);
//         }
//         return s;
//     }
// }