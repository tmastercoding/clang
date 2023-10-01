#include <stdio.h>

int main(){
    // open file to read
    FILE *fp = fopen("some_data.txt", "r");

    // declare char buffer
    char c;

    // if file doesn't exist
    if (fp == NULL) {
        // error
        printf("file open error ! \n");

        // close program and file
        fclose(fp);
        return 0;
    }
    
    // if file exists
    // while buffer isn't reach the end of file
    while ((c = fgetc(fp)) != EOF) {
        // print character
        printf("%c", c);
    }  

    // close the file
    fclose(fp);
    return 0;
}