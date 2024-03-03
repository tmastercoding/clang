#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    vector<int> v;
    const int size = 100;
    char buffer[size];
    char sep[] = " ";

    cin.getline(buffer, size, '\n');
    char* p = strtok(buffer, sep);

    while(p != NULL){
        v.push_back(stoi(p));
        strtok(NULL, sep);
    }

    return 0;
}