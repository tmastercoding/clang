#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    string text;
    vector<char> v;
    char buffer[100];
    int idx = 0;
    cin >> text;
    cout << text.length() << endl;

    cin.ignore();
    cin.getline(buffer, 100, '\n');

    string* temp = new string(buffer);
    while(buffer[idx] != '\0'){
        v.push_back(buffer[idx++]);
    }
    cout << v.size() << endl;
    return 0;
}