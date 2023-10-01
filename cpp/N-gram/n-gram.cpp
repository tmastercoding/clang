#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
using namespace std;

void c_ver(int n_gram){
    char text[30] = "Hello";
    int length;

    length = strlen(text);

    for(int idx = 0; idx < length-n_gram+1; idx++){
        for(int jdx = 0; jdx < n_gram; jdx++){
            printf("%c", text[idx+jdx]);
        }
        printf("\n");
    }
}

void cpp_ver(int n_gram){
    string text = "Hello";
    int length;
    length = text.length();

    for(int idx = 0; idx < length - n_gram + 1; idx++){
        for(int jdx = 0; jdx < n_gram; jdx++){
            cout << text[idx+jdx];
        }
        cout << endl;
    }
}

int main(){
    c_ver(4);    
    cpp_ver(4);
    return 0;
}