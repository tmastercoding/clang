#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> split(string text, const char sep);

int main(){
    string text = "  a      Hello    world   )_)    ";
    char sep = ' ';
    vector<string> outputVector;
    auto print = [](const string &s){cout << s << endl;};

    outputVector = split(text, sep);
    for_each(outputVector.begin(), outputVector.end(), print);
    cout << outputVector.size() << endl;
    return 0;
}

vector<string> split(string text, const char sep){
    int size = text.size();
    vector<string> outputVector; 
    string buffer;
    bool isSep = true;

    for(char c: text){
        if(c != sep){
            isSep = false;
            buffer.append(1, c);
        } 

        if(c == sep && !isSep){
            isSep = true;
            outputVector.push_back(buffer);
            buffer.clear();
        }
    }

    return outputVector;
}