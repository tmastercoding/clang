#include <iostream>
#include <string>
// string stream, deals with bytes
#include <sstream>
using namespace std;

int main(){
    // char arr
    char text[] = "123";

    // create a stringstream object called ss
    stringstream ss;

    int num;
    
    // puts char arr converted into string 
    // into string stream
    ss << string( text );

    // string stream inputs to number;
    ss >> num;

    // converted string into int
    cout << num << endl;

    return 0;
}