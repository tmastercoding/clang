#include <iostream>
#include <string>
#include <map>
using namespace std;

int main(){
    string buffer;
    int size = 0;
    map<char, int> results;
    int maxVal = 0;
    char maxKey;
    int count = 1;

    getline(cin, buffer);
    size = buffer.length();

    for(char ch: buffer){
        ch = tolower(ch);
        results.insert(pair<char, int>(ch, 0));
        results[ch] +=1;
    }

    
    for(map<char, int>::iterator it = results.begin(); it != results.end(); it++){
        if(it -> second > maxVal){
            count = 1;
            maxVal = it-> second;
            maxKey = it ->first;
        } else if (it -> second == maxVal){
            count+=1;
        }
    }
 
    cout << (
        (count > 1)? '?'
                   : (char)toupper(maxKey) 
            ) << endl;

    return 0;
}