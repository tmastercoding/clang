#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

void c_ver(){
    char word[30];
    int length;
    bool isPalindrome = true;

    printf("Input word: ");
    gets(word);

    length = strlen(word);

    // loop half of word
    for(int idx = 0; idx < length / 2; idx++){
        if (word[idx] != word[length - 1 - idx]){
            isPalindrome = false;
            break;

        }
    }

    printf("%d\n", isPalindrome);
}

void cpp_ver(){
    string word;
    int length;
    bool isPalindrome = true;
    char buffer[100] = {0,};
    char* p_buffer = buffer;

    char ch;

    while( ( ch = getchar() ) != '\n' ) {
        if(ch != ' '){
            *(p_buffer++) = ch;
        }
    }

    string text( buffer );

    // cout << text << endl;

    length = text.length();
    // cout << length << endl;

    for(int idx = 0; idx < length / 2; idx++){
        if( text[idx] != text[length - 1 - idx]){
            isPalindrome = false;
            break;
        }
    }

    cout << isPalindrome << endl;
}

int main(){
    // c_ver();
    cpp_ver();    
    return 0;
}