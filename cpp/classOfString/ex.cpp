#include <iostream>
#include <string>
using namespace std;

int main(){

    // char arr
    char str[] = "12 24 36 48";
    // deliminator
    char del = ' ';

    // string buffer
    string buffer;

    // foreach loop
    for( char ch : str ) {
        cout << ch << endl;
        // if isspace?
        // push to int array
        // else
        // buffer

        // if ch is equal to deliminator
        if( ch == del ) {
            // prints the buffer turned into integer
            cout << stoi(buffer) << endl;
            // clearing the buffer
            buffer.clear();
        } else {
            // push character into buffer
            buffer.push_back( ch );
        }
    }


    return 0;
}