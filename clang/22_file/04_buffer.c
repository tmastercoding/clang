#include <stdio.h>

int main() {
    // buffer, takes bit by bit of the
    // file instead of the whole thing

    // open the file a.txt to read
    FILE *fp = fopen("a.txt", "r");

    // assign a char variable called c
    char c;

    // EOF = End of File = -1

    // print every character in a.txt
    // until the character reaches EOF
    while((c = fgetc(fp)) != EOF) {
        printf("%c", c);
    }

    // close the file
    fclose(fp);

    return 0;
}