#include <stdio.h>

// convert_case
int convert_case(char *str);
int is_upper(char ch);
int is_lower(char ch);

int main(){
    char str[]="aBcDe";
    // printf("%d", size);

    convert_case(str);

    printf("%s\n", str);

    return 0;
}

int convert_case(char *str){
    // for(int idx =0; idx < size; idx++){
    //     if(*str > 96){
    //         *str-=32;
    //     } else{
    //         *str+=32;
    //     }
    //     str++;
    // }
    // return 1;

    while( *str != '\0') {
        if( is_upper( *str ) ) {
            *str +=32;
        } else if(is_lower( *str ) ){
            *str -=32;
        }
        str++;
    }

    return 1;


}

int is_upper(char ch){
    return ('A' <= ch && ch <= 'Z');
}

int is_lower(char ch){
    // if((ch<=97) && (ch>= 122)){
    //     return 1;
    // }

    // return 0;

    return ('a' <= ch && ch <= 'z');
}
