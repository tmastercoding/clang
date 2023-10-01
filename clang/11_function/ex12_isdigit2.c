#include <stdio.h>

int isdigit(char c);
// is c a digit

// '\n'
int main(){
    char input;
    // char input_2;

    scanf("%c", &input);
    // fflush( stdin );
    // scanf("%c", &input_2);

    // printf( "%c\n", input );
    // printf( "%c\n", input_2 );

    if( isdigit(input) ){
        printf("%c is a digit\n", input);
    } else{
        printf("%c is not a digit\n", input);
    }


    return 0;
}

// case 1.
// int isdigit(char c) {
//     if(48 <= c && c <= 57){
//         return 1;
//     } else {
//         return 0;
//     }
// }

// case 1.5.
// int isdigit(char c) {
//     if(48 <= c && c <= 57){
//         return 1;
//     }

//     return 0;
// }

// case 2.
// int isdigit(char c) {
//     return (48 <= c && c <= 57);
// }

// case 3.
// int isdigit(char c) {return (48 <= c && c <= 57);}

