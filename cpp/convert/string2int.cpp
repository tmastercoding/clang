#include <iostream>
#include <string>
using namespace std;

int main(){
    // char arr
    char text[] = "12";

    // getting the length of text
    // new string object of text
    int len = (new string( text ))->length();
    int mult = 1;
    int num = 0;

    // int end = sizeof(text)-1;
    // while(text[end] == '\0'){
    //     end--;
    // }

    
    // loops string from the last character
    for(int idx = len-1; idx > -1; idx--){
        // cout << text[idx]-'0' << endl;
        
        // gets the individual digit
        num+= (text[idx]-'0') * mult;
        // multiplies the mult with 10 
        mult*=10;
    }

    cout << num << endl;

    return 0;
}
