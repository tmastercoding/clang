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
        vector<vector<int>> combs;
        vector<pair<int, vector<int>>> og, temp;
        
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> arr[i];
            cnts[arr[i]]++;
            comp.insert(arr[i]);
            vout.push_back(arr[i]);
        }
    
        set<int, greater<int>>::iterator it = comp.begin(), next, jt = comp.end();
        
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
        combs.push_back(vout);
        vout.clear();
        for(int i = 0; i <= n; i++){
            cnts[i] = 0;
        }
        for(int i = 0; i < n; i++){
            cnts[arr[i]]++;
            vout.push_back(arr[i]);
        }
        
        int moveVal = -1, to = -1, from = -1, start = 0;
        for(int from = 0; from < n; from++){
            moveVal = arr[from];
            for(int to = 0; to < from; to++){
                vout.erase(vout.begin()+from);
                vout.insert(vout.begin()+to, moveVal);
                for(int i = 0; i < n; i++){
                    if(comp.empty()) break;
                    if(vout[i] == *comp.begin()){
                        out.push_back(vout[i]);
                    }
                    cnts[vout[i]]--;
                    if(cnts[*comp.begin()] == 0){
                        comp.erase(comp.begin());
                    }
                }
                combs.push_back(vout);
                vout.clear();
                for(int i = 0; i <= n; i++){
                    cnts[i] = 0;
                }
                for(int i = 0; i < n; i++){
                    cnts[arr[i]]++;
                    vout.push_back(arr[i]);
                }
            }
        }
        // cout << moveVal << ' ' << to << ' ' << from << '\n';

        for(int j = 0; j < combs.size(); j++){
            og.push_back({combs[j][0], combs[j]});
        }
        sort(og.begin(), og.end());

        for(int i = 1; i < n; i++){
            temp.clear();
            for(int j = 0; j < og.size(); j++){
                temp.push_back({og[j].second[i], og[j].second});
            }
            sort(temp.begin(), temp.end());
            og = temp;
        }
        // for(int j = 0; j < combs.size(); j++){
        //     for(int i = 0; i < n; i++){
        //         cout << combs[j][i] << ' ';
        //     }
        //     cout << '\n';

        // }
        
        for(int i = 0; i < og[0].second.size(); i++){
            cout <<  og[0].second[i];
            if(i <  og[0].second.size()-1){
                cout << ' ';
            }
        }
        cout << '\n';
    }

    // cout << moveVal << ' ' << to << '\n';
    return 0;
}