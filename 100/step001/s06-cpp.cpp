#include <iostream>
// string class
#include <string>
using namespace std;

int main(){
    // declare int
    int pre;
    // declare string
    string post;

    // input
    cin >> pre; 
    cin >> post;

    // cout << stoi(post) << endl;
    // stoi() is used to convert string to int
    cout << pre + stoi(post) << endl;
    cout << pre - stoi(post) << endl;
    cout << pre * stoi(post) << endl;
    cout << pre / stoi(post) << endl;
    cout << pre % stoi(post) << endl;

    return 0;
}