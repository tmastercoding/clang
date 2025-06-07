#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;

int n, arr[1000000] = {};
int main(){
    int t = 0;
    cin >> t;
    for(int c = 0; c < t; c++){
        pair<int, int> ds[1000000] = {};
        map<int, int> cnts, curCnt;
        set<int, greater<int>> comp;
        vector<int> v, out;
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> arr[i];
            cnts[arr[i]]++;
            comp.insert(arr[i]);
            v.push_back(arr[i]);
        }
        
        int max = 0, maxI = n;
        for(int i = n-1; i > -1; i--){
            ds[i] = {max, maxI};
            if(max < arr[i]){
                max = arr[i];
                maxI = i;
            }
        }

        int moveVal = -1, to = -1, from = -1;
        int firstMax = -1, secondMax = -1, fdx = -1, sdx = -1, collect = 0;
        set<int, greater<int>>::iterator it = comp.begin(), jt;
        for(int i = 0; i < n; i++){
            jt = it;
            jt++;
            if(jt== comp.end()) break; 
            
            if(!collect && (cnts[*it]-1 == curCnt[*it] ||( (cnts[*it] == 1 )&& (!curCnt[*it])))){
                firstMax =-1;
                fdx = i;
                collect = 1;
            }

            curCnt[arr[i]]++;
            if(collect == 1){
                if(arr[i] > firstMax&& arr[i]!=*it) firstMax = arr[i];
            }

            // cout << *it << ' ' << curCnt[*it] << ' ' <<collect << ' ' << firstMax << ' ' << fdx << ' ' << secondMax << ' ' << sdx << '\n';
            
            if(cnts[*it]== curCnt[*it]){
                secondMax = ds[i].first;
                sdx = ds[i].second;
                jt = it;
                jt++;
                if(firstMax > secondMax){
                    moveVal = *it;
                    to = fdx;
                    from = i;
                    break;
                } else{
                    it++;
                    collect = 0;
                }
            }
            
        }
        // cout << to << ' ' << moveVal << ' ' << from << '\n';
        if(to >-1 && moveVal > -1 && from > -1){
            v.erase(v.begin()+from);
            v.insert(v.begin()+to, moveVal);
        }
        // sort(v.rbegin(), v.rend());
        for(int i = 0; i < n; i++){
            if(v[i] == *comp.begin()){
                out.push_back(v[i]);
            }
            cnts[v[i]]--;
            if(cnts[*comp.begin()] == 0){
                comp.erase(comp.begin());
            }
        
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