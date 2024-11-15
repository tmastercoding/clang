#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;

// void swap(vector<int> *basket, int one, int other);

int main(){
    // declare variables
    int one, other = 0;
    int sizeBasket = 0;
    int noOfSwitch = 0;
    string buffer;
    string temp;

    // input variables
    getline(cin, buffer);
    istringstream iss(buffer);
    iss >> temp;
    sizeBasket = stoi(temp);
    iss >> temp;
    noOfSwitch = stoi(temp);

    // set up vector
    vector<int> baskets;
    for(int idx = 0; idx < sizeBasket; idx++){
        baskets.push_back(idx+1);
    }

    int idx = 0;
    // loop for noOfSwitch
    while(idx < noOfSwitch){
        // input one, other1
        cin >> one >> other;
        // swap
        if(other!=one){
            swap(baskets[one-1], baskets[other-1]);
        }
        idx++;
    }

    // output
    auto print = [](const int &n) {cout << n << ' ';};
    for_each(baskets.begin(), baskets.end(), print);
    cout << endl;

    return 0;
}

// void swap(vector<int> *basket, int one, int other){
//     int temp = (*basket).at(one);
//     (*basket).at(one) = (*basket).at(other);
//     (*basket).at(other) = temp;
// }