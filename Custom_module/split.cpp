#include <iostream>
#include <string>
#include <vector>
using namespace std;

/**
 * @date ??.??.??
 * @author Tay Oh
 * @details Splits text according to sep
*/

vector<string> split(string text, const char sep);

int main(){
    string text = "  a      Hello    world   )_)    ";
    char sep = ' ';
    // creates vector
    vector<string> outputVector;

    // auto func for output
    auto print = [](const string &s){cout << s << endl;};

    // splits
    outputVector = split(text, sep);
    // output
    for_each(outputVector.begin(), outputVector.end(), print);
    cout << outputVector.size() << endl;
    return 0;
}

vector<string> split(string text, const char sep){
    int size = text.size();
    vector<string> outputVector; 
    string buffer;
    bool isSep = true;

    // loop text
    for(char c: text){
        // if not sep
        if(c != sep){
            isSep = false;
            // append to buffer
            buffer.append(1, c);
        } 

        // if sep
        if(c == sep && !isSep){
            isSep = true;
            // add buffer to vector
            outputVector.push_back(buffer);
            buffer.clear();
        }
    }

    return outputVector;
}