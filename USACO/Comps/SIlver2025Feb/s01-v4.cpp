#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;

int main(){
    int t= 0;
    cin >> t;
    for(int c =0; c < t; c++){
        int n, arr[200000] = {};
        
        set<int, greater<int>> comp;
        // idx, infront max
        map<int, int> cnts;
        vector<pair<int, int>> v;
        vector<int> out, vout;
        
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> arr[i];
            cnts[arr[i]]++;
            comp.insert(arr[i]);
            vout.push_back(arr[i]);
        }
    
        set<int, greater<int>>::iterator it = comp.begin(), next, jt = comp.end();
        jt--;
        int moveVal = -1, to = -1, from = -1, start = 0;
        for(; it != jt; it++){
            int max = 0;
            for(int i = start; i < n; i++){
                if(arr[i] == *it){
                    v.push_back({i, max});
                    max = 0;
                    continue;
                }
                if(max < arr[i]){
                    max = arr[i];
                }
            }
            next = it;
            next++;
            int temp = v.size()-3;
            if(temp < -1){
                temp = -1;
            }
            bool found = false;
            for(int i = v.size()-1; i > temp; i--){
    
                if(*next == v[i].second){
                    moveVal = *it;
                    to = 0;
                    if(i > 0){
                        to = v[i-1].first+1;
                    }
                    from = v[i].first;
                    found = true;
                    break;
                }
            }
            if(found) break;
            start = v[v.size()-1].first;
        }
        // cout << moveVal << ' ' << to << ' ' << from << '\n';
        if(to >-1 && moveVal > -1 && from > -1){
            vout.erase(vout.begin()+from);
            vout.insert(vout.begin()+to, moveVal);
        }
        // for(int i = 0; i < n; i++){
        //     cout << vout[i] << ' ';
        // }
        // cout << '\n';
        for(int i = 0; i < n; i++){
            if(comp.empty()) break;
            if(vout[i] == *comp.begin()){
                out.push_back(vout[i]);
            }
            cnts[vout[i]]--;
            if(cnts[*comp.begin()] == 0){
                comp.erase(comp.begin());
            }
            // j++;
        
        }
        for(int i = 0; i < out.size(); i++){
            cout << out[i];
            if(i < out.size()-1){
                cout << ' ';
            }
        }
        cout << '\n';
    }

    // cout << moveVal << ' ' << to << '\n';
    return 0;
}