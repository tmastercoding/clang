// Cities and States 14171
#include <iostream>
#include <string>
#include <map>
using namespace std;

int main(){
    int n;
    map<string, int> m;
    string city, state, temp;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> city >> state;
        temp = city[0];
        temp += city[1];
        temp += state;
        // cout << temp << '\n';
        m[temp]++;
    }
    long long cnt = 0;
    for(auto &i: m){
        // cout << i.first << '\n';
        temp = i.first[2];
        temp += i.first[3];
        temp += i.first[0];
        temp += i.first[1];
        auto it = m.find(temp);
        if(it != m.end()){
            // cout << it->first << ' ' <<  it->second << '\n';
            if(temp != i.first){
                cnt += (it->second)*i.second;
            }
            i.second = 0;
        }
    }
    cout << cnt << '\n';
    return 0;
}