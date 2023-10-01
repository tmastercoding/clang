#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
using namespace std;

void c_ver(int n_gram){
    char text[100] = "this is c language";
    char *tokens[30] = {NULL, };
    int count=0;

    // returns one word at a time, split by whitespace
    char *ptr = strtok(text, " ");
    
    while (ptr != NULL){
        tokens[count] =  ptr;
        count++;

        ptr = strtok(NULL, " ");
    }

    // for(int idx = 0; idx < count; idx++){
    //     printf("%s\n", tokens[idx]);
    // }

    for (int idx = 0; idx < count - n_gram+1; idx++){
        for(int jdx = 0; jdx < n_gram; jdx++){
            printf("%s ", tokens[idx+jdx]);
        }
        printf("\n");
    }
}

void cpp_ver(int n_gram){
    string text = "this is c language";
    char *tokens[30] = {NULL, };
    int count = 0;

    char buf[100] = {'\0',};
    strcpy(buf, text.data());

    char *ptr = strtok( buf, " ");
    
    while (ptr != NULL){
        tokens[count] = ptr;
        count++;

        ptr = strtok(NULL, " ");
    }

    for(int idx = 0; idx < count - n_gram+1; idx++){
        for(int jdx = 0; jdx < count; jdx++){
            printf("%s ", tokens[idx+jdx]);
        }
        printf("\n");
    }
}

int main(){
    int n_gram = 3;
    c_ver(n_gram);
    cpp_ver(n_gram);
    return 0;
}