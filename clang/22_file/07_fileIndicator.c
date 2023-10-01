#include <stdio.h>

int main(){
    // open a file called a.txt to write
    FILE *fp = fopen("a.txt", "w");

    // put this string into the file
    fputs("TmasterCoding is an excellent C programmer\n", fp);

    // move the cursor back to the front
    fseek(fp, 0, SEEK_SET);

    // now replace the first 16 characters
    // with this string
    fputs("Is TmasterCoding", fp);

    // close the file
    fclose(fp);
    
    return 0;
}