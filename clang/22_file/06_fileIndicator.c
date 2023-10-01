#include <stdio.h>

int main(){
    // open the file a.txt to read
    FILE *fp = fopen("a.txt", "r");

    // cursor is pointing to H
    fgetc(fp);

    // cursor is pointing to e
    fgetc(fp);

    // cursor is pointing to l
    fgetc(fp);

    // cursor is pointing to l
    fgetc(fp);

    // cursor is now pointing to o, 
    // but only inputted until Hell

    // make the cursor point to the first char,
    // or 0
    fseek(fp, 0, SEEK_SET);

    // print the character 
    // the cursor pointing to
    printf("If you start from the top: %c \n", fgetc(fp));
    
    // close the file
    fclose(fp);

    return 0;
}