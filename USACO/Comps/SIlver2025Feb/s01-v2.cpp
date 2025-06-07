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
        
        int moveVal = -1, to = -1, ffrom = -1, sfrom = -1, from = -1;
        int firstMax = -1, secondMax = -1, fdx = -1, sdx = -1, collect = 0;
        set<int, greater<int>>::iterator it = comp.begin(), jt;
        for(int i = 0; i < n; i++){
            jt = it;
            jt++;
            if(jt== comp.end()) break; 
            
            if(!collect && (cnts[*it]-2 == curCnt[*it] ||( (cnts[*it] == 1 )&& (!curCnt[*it])))){
                firstMax =-1, secondMax = -1;
                fdx = i;
                collect = 1;
            }
            if(collect == 1 && cnts[*it]-1 == curCnt[*it]){
                ffrom = i;
                sdx = i;
                collect = 2;
            }
            curCnt[arr[i]]++;
            if(collect == 1){
                if(arr[i] > firstMax&& arr[i]!=*it) firstMax = arr[i];
            }
            if(collect == 2){
                if(arr[i] > secondMax && arr[i]!=*it) secondMax = arr[i];
            }
            // cout << *it << ' ' << curCnt[*it] << ' ' <<collect << ' ' << firstMax << ' ' << fdx << ' ' << secondMax << ' ' << sdx << '\n';
            
            if(cnts[*it]== curCnt[*it]){
                sfrom = i;
                jt = it;
                jt++;
                if(secondMax == *jt){
                    moveVal = *it;
                    to = sdx;
                    from = sfrom;
                    break;
                } else if(firstMax == *jt){
                    moveVal = *it;
                    to = fdx;
                    from = ffrom;
                    break;
                } else{
                    it++;
                    collect = 0;
                }
            }
            
        }
        // cout << to << ' ' << moveVal << ' ' << from << '\n';
    
        sort(v.rbegin(), v.rend());
        for(int i = 0; i < n; i++){
            // cout << *comp.begin() << '\n';
            if(comp.empty()) break;
            if(i == from){
                continue;
            }
            
            if(i == to){
                if(moveVal == *comp.begin()){
                    out.push_back(moveVal);
                }
                cnts[moveVal]--;
                if(cnts[*comp.begin()] == 0){
                    comp.erase(comp.begin());
                }
                // cout << *comp.begin() << '\n';
            }
            if(arr[i] == *comp.begin()){
                out.push_back(arr[i]);
            }
            cnts[arr[i]]--;
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