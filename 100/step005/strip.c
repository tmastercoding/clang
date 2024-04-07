#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void strip( const char* str );

int main() {

    char str[] = "   Hello  ";

    strip( str );
    
}


void strip( const char* str ) {
    int pre_flag = 0;
    int post_flag = 0;
    int pre_index = 0;
    int post_index = strlen( str )-1;

    while( (*str != '\0' ) && (strlen(str)-1 > 0) ) {

        // check space character of front 
        if( *(str + pre_index) == ' ' && !pre_flag ) {
            pre_index++;
        } else{
            pre_flag = 1;
        }

        // check space character of rear 
        if( *(str + post_index) == ' ' && !post_flag ) {
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

    }

    printf("temp value: %s\n", temp);
}