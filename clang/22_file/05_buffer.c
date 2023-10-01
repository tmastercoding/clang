#include <stdio.h>

int main() {
    // open the file a.txt to read
    FILE *fp = fopen("a.txt", "r");

    // create a int variable called size
    int size = 0;

    // while the buffer isn't EOF
    while(fgetc(fp) != EOF){
        // add 1 to the size
        size++;
    }

    // print the result
    printf("file's size: %d bytes \n", size);
    
    // close the file
    fclose(fp);

    return 0;
}