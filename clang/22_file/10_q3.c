// get input from pre.txt and 
// ouput to post.txt reverse

#include <stdio.h>
#include <string.h>

int main(){
    // open pre.txt to read and call it src
    FILE *src = fopen("pre.txt", "r");
    
    // declare a int var called size
    int size = 0;

    // get the size of file src
    while(fgetc(src) != EOF){
        size++;
    }

    // declare a char var called c
    char c;
    
    // declare a string that is long as the size of the arr
    char str[size];

    // create a pointer pointing to str
    char *ptr = str;

    // put the cursor back to the front
    fseek(src, 0, SEEK_SET);

    // while the buffer isn't EOF
    while((c = fgetc(src)) != EOF){
        // assign c to the pointer
        // so that it's added to the str
        // then ptr is increased
        *(ptr++) = c;
    }

    // close the source file
    fclose(src);

    // open the file post.txt to write
    // as dest
    FILE *dest = fopen("post.txt", "w");

    // do size-1, to get rid of the garbage val
    size -= 1;

    // while size is greater than 0
    while(size >= 0){
        // put each char to dest
        fputc(str[size], dest);

        // descrease size
        size--;
    }
    
    // close the file
    fclose(dest);

    return 0;
}