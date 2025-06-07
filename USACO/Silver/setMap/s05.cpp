// 베스트셀러 1302
#include <iostream>
#include <string>
#include <map>
using namespace std;

int main(){
    int n;
    string name;
    map<string, int> m;

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> name;
        m[name]++;
    }

    int maxVal = 0;
    string maxName;
    for(auto i: m){
        if(i.second > maxVal){
            maxVal = i.second;
            maxName = i.first;
        }
    }

    cout << maxName << '\n';
    return 0;
}