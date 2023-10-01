#include <stdio.h>

int main() {

    // r+ = allows you to read+write the file
    // DOES NOT CREATE FILE

    // However w+ creates file

    // open a file to r+
    FILE *fp = fopen("some_data.txt", "r+");

    // create a char buffer
    char c;

    // check if file exists
    if(fp == NULL){
        printf("file opening error! \n");
        return 0;
    }

    // while buffer isn't end of file
    while ((c = fgetc(fp)) != EOF){
        // if c is capital
        if(65 <= c && c <= 90) {
            // go back one to access the char
            fseek(fp, -1, SEEK_CUR);

            // output lowercase c
            fputc(c + 32, fp);
        }
        // if c is lowercase
        else if (97 <= c && c <= 122){
            // go back one to access the char
            fseek(fp, -1, SEEK_CUR);

            // turn into capital
            fputc(c - 32, fp);
        }
    }

    // close the file
    fclose(fp);
    
    return 0;
}