#include <iostream>
#include <map>
#include <vector>
using namespace std;

void reverse(int start, int end, vector<int>& baskets){
    // assign variables
    int idx = 0;
    start -= 1;
    int length = end-start;

    // loop for pairs
    while(idx != length/2){
        // cout << baskets.at(start+idx) << ' ' << baskets.at(end-idx-1) << endl;
        // swap
        swap(baskets.at(start+idx), baskets.at(end-idx-1));

        idx++;
    }
}   

int main(){
    // assign variables
    int basketSize, commands = 0;
    int start, end = 0;
    int idx = 0;

    // input for sizes
    cin >> basketSize >> commands;

    // set up vector
    vector<int> baskets;

    while(baskets.size() != basketSize){
        baskets.push_back(++idx);
    }

    idx = 0;

    // loop for commands
    while(idx < commands){
        // input for parameters
        cin >> start >> end;

        // call func
        reverse(start, end, baskets);
        
        idx++;
    }

    // output
    for(int num: baskets){
        cout << num << ' ';
    }
    cout << endl;

    return 0;
}
