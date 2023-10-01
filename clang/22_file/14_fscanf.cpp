#include <stdio.h>

int main(){
    // open a file to read
    FILE *fp = fopen("some_data.txt", "r");

    // create array called data
    char data[100];

    // check if files exists
    if (fp == NULL) {
        printf("File opening error! \n");
        return 0;
    }

    printf("---- inputted words ----- \n");

    // fscanf, 
    // gets each string seperated by a whitespace
    // get word by word until end of file
    while( fscanf(fp, "%s", data) != EOF){
        // print the word
        printf("%s \n", data);
    }

    // close the file
    fclose(fp);
    
    return 0;
}