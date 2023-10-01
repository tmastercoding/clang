#include <stdio.h>
#include <string.h>

// create a program that searches for
// a string from a file

// search function with src and keyword
int search(char *src, char *keyword);

// get input that'll be keyword
int main(int argc, char **argv){

    // assign keyword
    char *keyword = argv[1];

    // open the file lr.txt to read
    FILE *fp = fopen("lr.txt", "r");
    
    // get the size of the file
    int size = 0;
    
    while(getc(fp) != EOF){
        size++;
    }

    // put the cursor back at the front
    fseek(fp, 0, SEEK_SET);

    // make the file as a string

    // declare buffer variable
    char c;

    // declare a string as long as the file's size
    char str[size];

    // create a pointer pointing to str
    char *ptr = str;

    // while the buffer isn't EOF
    while((c = getc(fp)) != EOF){
        // assign c to string
        // increase pointer
        *(ptr++) = c;
    }

    // close the file
    fclose(fp);
    
    int result = search(str, keyword);

    // prints result
    printf("is there %s in the file?\n", keyword);
    if(result){
        printf("Yes!\n");
    } else{
        printf("No.\n");
    }

    return 0;
}

// search function with src and keyword
int search(char *src, char *keyword){
    // src length
    int src_len = strlen(src);

    // keyword length
    int key_len = strlen(keyword);

    // compare all possible strings from src to keyword
    // run while size is smaller than
    // length of src subtracted by the len of keyword
    // increase size
    for(int size = 0; size < (src_len - key_len)+1; size++){
        // get a keyword sized string from the src
        // declare a string as long as keyword
        char str[key_len];

        // create a pointing to str
        char *ptr = str;

        // while idx is smaller than the length of keyword
        for(int idx = 0; idx < key_len; idx++){
            // assign the (size+idx)th char of src to the str 
            *(ptr++) = src[size+idx];
        }
        // compare this string and keyword
        // if strcmp is true return 1
        if(!(strcmp(keyword, str))){
            return 1;
        }
    }

    // if not return 0
    return 0;
}