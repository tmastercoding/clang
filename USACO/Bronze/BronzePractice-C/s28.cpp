// Where am I? 18269
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

int main(){
    freopen("whereami.in", "r", stdin);
	freopen("whereami.out", "w", stdout);
    int size;
    string street;
    cin >> size;
    cin >> street;

    vector<string> foundStr;
    string temp;
    bool isValid;
    for(int k = 1; k <= size; k++){
        // cout << k << '\n';
        foundStr.clear();
        isValid = true;
        for(int idx = 0; idx <= size-k; idx++){
            temp.clear();
            for(int jdx = 0; jdx < k; jdx++){
                temp += street[idx+jdx];
            }
            if(find(foundStr.begin(), foundStr.end(), temp) == foundStr.end()){
                foundStr.push_back(temp);
            } else{
                isValid = false;
                break;
            }
        }
        if(isValid){
            cout << k << '\n';
            break;
        }
        // cout << '\n';
    }
    return 0;
}