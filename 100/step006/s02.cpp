#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

int main(){
    vector<int> correct {1, 1, 2, 2, 2, 8};
    string buffer;
    string number;
    char sep = ' ';
    vector<int>:: iterator iter = correct.begin();

    if(getline(cin, buffer)){
        istringstream iss(buffer);
        while(getline(iss, number,sep)){
            if( iter == correct.end()) break;
            cout << *(iter++) - stoi(number) << " ";            
        }

        cout << endl;
    }

    return 0;
}