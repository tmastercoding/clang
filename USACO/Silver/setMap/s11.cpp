#include <iostream>
#include <map>
#include <algorithm>
#include <set>
using namespace std;

// bool comp(pair<int, int> a, pair<int, int> b){
//     if(a.first>b.first) return true; 
// }
int main(){
    map<pair<int, int>, set<int>> customs;
    map<int, set<int>> as, bs;
    int out[200000] = {};
    int n, a, b;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        pair<int, int> temp = {a, b};
        customs[temp].insert(i);
        as[a].insert(i);
        bs[b].insert(i);
    } 

    // sort(customs.begin(), customs.end());
    int cnt = 0;
    while(!customs.empty()){
        // curb
        int curb = customs.begin()->first.second;
        auto it = as.lower_bound(curb);
        if(it != as.end()){
            if(it->first > curb){
                if(!(customs.begin()->second.empty())){
                    int rid = *(customs.begin()->second.begin());
                    customs.begin()->second.erase(rid);
                    
                    
                }
            }
        }
    }
    return 0;
}