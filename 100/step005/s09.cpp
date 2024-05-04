#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

int reverse(string buffer);

int main(){
    string line;
    string buffer;
    char sep = ' ';
    vector<int> v;

    getline(cin, line);
    
    istringstream iss(line);
    
    while(getline(iss, buffer, sep)){
        if(!buffer.empty()){
            v.push_back(reverse(buffer));
        }
    }

    cout << (v[0]>v[1] ? v[0]: v[1] )<< endl;

    return 0;
}

int reverse(string buffer){
    int size = buffer.length();
    string temp;

    for(int idx = size-1; idx > -1; idx-- ){
        temp.append(1, buffer[idx]);
    }

    return stoi(temp);
}