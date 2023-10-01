#include <stdio.h>

int copy_str(char *src, char *dest);
int string_len(char *pre);

int main(){
    char str1[] = "hello";
    char str2[] = "hi";

    printf("before copy: %s \n", str1);

    if(string_len(str1) >= string_len(str2)){
        copy_str(str2, str1);
        printf("after copy: %s \n", str1);  
    } else{
        printf("destination is smaller than the source.\n");
    }
    
    return 0;
}

// int copy_str(char *src, char *dest){
//     while(*src) {
//         *dest = *src;
//         src++;
//         dest++;
//     }
//     *dest = '\0';
    
//     return 1;
// }

// before must be compare to dest'length and src'length
int copy_str(char *src, char *dest){
    while(  ( *(dest++) = *(src++) ) != '\0'  );
    
    return 1;
}

int string_len(char *pre){
    int len = 0;
    // while(*(pre++) != '\0'){
    //     len++;
    // }
    while(*(pre + (len++) ) != '\0');

    return len;
}
