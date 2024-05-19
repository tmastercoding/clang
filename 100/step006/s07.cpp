#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main(){
    int size = 0;
    vector<string> text;
    string line;
    vector<string>::iterator iter;
    char prevChar = '\0';
    int count = 0;
    bool isGroup = true;
    vector<char> hasFound;

    // get input
    // check range
    while (true){
        cin >> size;
        if((0 < size) && (size < 101)){
            break;
        } else{
            cout << "Please input a number between 1 and 100" << endl;
        }
    }
    
    for(int idx = 0; idx < size; idx++){
        cin >> line;
        text.push_back(line);
    }

    // auto print = [](const string &str) {cout << str << endl;};
    // for_each(text.begin(), text.end(), print);

    iter = text.begin();
    // loop each line
    for(; iter != text.end(); iter++){
        prevChar = '\0';
        isGroup = true;
        hasFound.clear();

        // loop each char
        for(char ch: *iter){
            // if char is not prevChar
            if (ch!=prevChar){
            
                // if already found
                if(find(hasFound.begin(), hasFound.end(), ch) != hasFound.end()){
                    isGroup = false;
                    break;
                } else{
                    prevChar = ch;
                    hasFound.push_back(ch);
                }
                
            }
        }
        if(isGroup){
            count++;
        }
    }
    cout << count << endl;

    return 0;
}