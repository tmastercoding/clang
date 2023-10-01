#include <stdio.h>

int string_length( char *arr);

int main(){
    char word[] = {"long"};

    char *pword = word;

    int length = 0;

    // while(*pword){
    //     length++;
    //     pword++;
    // }

    printf("%d\n", length+1);

    printf("%d\n", string_length(pword));

    return 0;
}

// int string_length(int *arr){
//     int length = 0;
//     while(*arr){
//         length++;
//         arr++;
//     }

//     length++;

//     return length;
// }

int string_length( char *arr){
    int size = 0;

    while( *( arr + size++ ) );

    return size;
}