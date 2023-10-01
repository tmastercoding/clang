#include <stdio.h>

int main(){
    // open the file called a.txt
    // to read
    FILE *fp = fopen("./a.txt", "r");
    
    // assign an array called
    // buffer with 20 characters available
    char buf[20];

    // if file is null show error
    if(fp == NULL){
        printf("READ ERROR !!\n");
        return 0;
    }

    // access 20 characters from the file
    // and put it into buf
    fgets(buf, 20, fp);

    // print the information inputted
    printf("inputting information: %s \n", buf);
    
    // close the file
    fclose(fp);
    
    return 0;
}