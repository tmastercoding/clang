#include <stdio.h>

int main(int argc, char **argv){
    // input
    // argc = number of parameters
    // argv = inputted things

    // a ptr will point to the first input
    // DISCLAIMER argv[1] is actually
    // the second input, since the 
    // directory counts as the first input
    char *name = argv[1];

    // create with the name as the name
    // to write
    FILE *fp = fopen(name, "w");

    // put a inside the file
    putc('a', fp);

    // close the file
    fclose(fp);

    return 0;
}