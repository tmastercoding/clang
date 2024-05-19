#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    vector<int> v {1};

    cout << (bool)(find(v.begin(), v.end(), 1) != v.end()) << endl;

    return 0;
}