#include <stdio.h>
#include <string.h>

#define true 1
#define false 0

/**
 * @date ??.??.??
 * @author Tay Oh
 * @details code showing various
 *          ways to str to int
*/

int strToInt(const char *s);
int isInt(const char *s);
int isIntRecursive(const char *s);
int isNegative(const char *s);
int atoi_custom( const char *s );
int str2dec( const char *s );

int main() {

    char str[]="-1234";
    int value = 0;

    // printf("%d\n", str2dec(str));

    // if( strlen( str ) ) {
    //     printf("%s\n", isIntRecursive( str)? "true": "false" );
    // } else {
    //     printf("str[] is empty\n" );
    // }

    printf("%d\n", atoi_custom(str));
    
    // value = strToInt( str );

    // printf("value is: %d\n", value );

    return 0;
}

int isInt(const char *s){
    for(int idx = 0; idx < strlen(s); idx++){
        if( (s[idx] < '0') || (s[idx] > '9')){
            return 0;
        }
    }

    return 1;
}

int isNegative(const char *s){
    if(*s == '-' && ((*(s+1) >= '0') || ((*s+1) <= '9'))){
        return true;
    }

    return false;
}

int isIntRecursive(const char *s) {
    if( !strlen( s )) return false;

    if( *(s+1) == '\0' ){
        return true;
    } else {
        
        if( (*s < '0') || (*s > '9')){
            return false;
        }

        return isIntRecursive( ++s);
    }
}

int atoi_custom( const char *s ) {

    int sign_value = 1;
    if( *s == '-' ) {
        sign_value *= -1;
        ++s;
    } else if ( *s == '+' ) {
        ++s;
    }

    if( isIntRecursive( s ) ) {
        return sign_value * strToInt(s);
    } else{
        return __INT_MAX__;
    }
}

/*
int isIntRecursive( const char *s ) {

    if( *s >= '0' && *s <= '9' ) {
        return isIntRecursive( ++s );
    } else if( !*s ) {
        return 1;
    } else {
        return 0;
    }

}
*/

int strToInt(const char *s){
    int num = 0;
    int power = 1;
    for(int idx = strlen(s)-1; idx >= 0; idx--){
        num += (s[idx]-'0') * power;
        power*=10;
    }

    return num;
}


int str2dec( const char *s ) {
    int result = 0;
    while( *s != '\0' ) {
        result*= (result)? 10:0; 

        result += (*(s++)-'0');
    }
    return result;
}