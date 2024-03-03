#include <iostream>
#include <string>
using namespace std;

int main(){
    string text;
    int idx = 0;

    cin >> text >> idx;
    
    cout << text[idx-1] << endl;
    return 0;
}