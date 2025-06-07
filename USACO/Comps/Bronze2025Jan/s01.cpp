#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[1000000] = {};
    vector<pair<int, long long>> v;
    // vector<int, long long>::iterator it;
    map<int, pair<int, int>> m;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        if(m.find(arr[i]) == m.end()){
            m.insert({arr[i], {i, -1}});
        }
    }


    int idx = 0;
    for(int i = 0; i < n; i++){
        if(m[arr[i]].first == i){
            v.push_back({arr[i], 1});
            m[arr[i]].second = idx++;
        } else if(m[arr[i]].first < i){
            // cout << m[arr[i]].second << '\n';
            v[m[arr[i]].second].second += 1;
        }
    }

    // for(int i = 0; i < v.size(); i++){
    //     cout << v[i].first << ' ' << v[i].second << '\n';
    // }

    long long cnt = 0;
    int size = v.size();
    for( int i = 2; i < size; i++){
        if(v[i].second >= 2){
            cnt+=i;
        }
    }
    cout << cnt << '\n';
    

    return 0;
}