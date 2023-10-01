#include <stdio.h>

int main() {
    // File is a struct
    // fp is a pointer pointing to the file
    FILE *fp;

    // open file called a.txt and allow
    // to write
    // This locks the file for other programs
    fp = fopen("a.txt", "w");

    // if the fp is null, show an error
    if(fp == NULL) {
        printf("Write Error!!\n");
        return 0;
    }
    
    // replace all text with hello world 
    fputs("Hello World!!! \n", fp);

    // unlocks the file for other programs
    fclose(fp);

    return 0;
}