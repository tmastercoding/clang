#include <stdio.h>

/*
    text stream - sequence of chars in lines
                  seperated by \n
    getchar()   - reads next char from
                  text stream
    putchar()   - outputs a char
*/

// copy input to output; 

int main(){
    // used int to compare with EOF, 
    // which is too big to be stored with char
    printf("EOF: %d\n", EOF);
    int c;


    /* ver 1:
    c = getchar();

    while(c != EOF){
        putchar(c);
        c = getchar();
    }
    */

    // ver 2
    // while((c = getchar()) != EOF)
    //     putchar(c);
 
    // != has higher ranking than =, so
    // verify getchar() != EOF is 0/1

    while(c = (getchar() != EOF))
        printf("%d", c);
        
    

    return 0;
}