#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int reverseFind(int findNum, vector<int> src, int size){
    for (int idx = size-1; idx > -1; idx--){
        if (src.at(idx) == findNum){
            return idx;
        }
    }
    return -1;
}

int main(){
    int size = 0;
    string text;
    string buffer;
    vector<int> arr;
    vector<int> realRange;
    vector<int> pos;
    int result;
    int sum = 0;

    getline(cin, buffer);
    size = stoi(buffer);
    getline(cin, text);
    istringstream iss(text);

    while(iss >> buffer){
        arr.push_back(stoi(buffer));
    }

    for(int idx = 1; idx < size+1; idx++){
        realRange.push_back(idx);
        pos.push_back(idx);
    }


    // cout << reverseFind(0, arr, size) << endl;
    auto print = []( const int &n ) { cout << n << ' '; };

    for(int idx = 0; idx < size; idx++){
        // cout << arr.at(idx) << endl;
        result = reverseFind(arr.at(idx), realRange, size);
        // cout << result << endl;
        if (result != -1){
            realRange.at(result) = 0;
            pos.at(result) = 0;
        }
        for_each(pos.begin(), pos.end(), print);
        cout << endl;
        for_each(realRange.begin(), realRange.end(), print);
        cout << endl;
    }


    for (int idx = 0; idx < size; idx++){
        sum += pos.at(idx);
    }

    cout << sum << endl;
    return 0;
}


