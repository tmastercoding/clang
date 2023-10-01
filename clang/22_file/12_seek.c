#include <stdio.h>

int main(){
    // open a file
    FILE *fp = fopen("some_data.txt", "r");
    // create an array to store data
    char data[10];

    // create char buffer
    char c;

    // check if file exists
    if( fp == NULL) {
        printf("file open error! \n");
        return 0;
    }

    // get 5 characters from file, 
    // put it into data
    fgets(data, 5, fp);

    // print data
    printf("inputted data: %s\n", data);

    // get the next character
    c = fgetc(fp);
    // print the character
    printf("the next character inputted: %c \n", c);

    // make the cursor go back by 1
    // SEEK_CUR = cursor
    fseek(fp, -1, SEEK_CUR);
    
    // get the character
    c = fgetc(fp);

    // print the character
    printf("what is the char? : %c \n", c);

    // prints same character because 
    // the cursor moved when fgetc()

    // make cursor go 1 before the end of file
    // last char
    fseek(fp, -1, SEEK_END);

    // get the character
    c = fgetc(fp);

    // print last char
    printf("last char: %c \n", c);

    // close the file
    fclose(fp);

    return 0;
}