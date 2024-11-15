#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n, t;
    cin >> t;
    for(int cnt = 0; cnt < t; cnt++){
        // height, idx
        vector<pair<long long int, int>> plants;
        pair<long long int, int> temp;
        long long int growth[200000], want[200000];

        cin >> n;
        for(int idx = 0; idx < n; idx++){
            cin >> temp.first;
            temp.second = idx;
            plants.push_back(temp);
        }

        bool growthSame = true;
        long long int prev;
        for(int idx = 0; idx < n; idx++){
            cin >> growth[idx];
            if(idx>0){
                if(growth[idx] != prev){
                    growthSame = false;
                }
            }
            prev = growth[idx];
        }
        for(int idx = 0; idx < n; idx++){
            cin >> want[idx];
        }

        sort(plants.rbegin(), plants.rend());
        // for(int idx = 0; idx < n; idx++){
        //     cout << plants[idx].first << ": " << growth[plants[idx].second] << '\n';
        // }
        bool isMatch = true;
        for(int idx = 0; idx < n; idx++){
            if(idx > 0){
                if(plants[idx].first == plants[idx-1].first){
                    isMatch = false;
                    break;
                }
            }
            // cout << plants[idx].first << ' ' << plants[idx].second << '\n'; 
            if(idx != want[plants[idx].second]){
                isMatch = false;
                break;
            }
        }
        // match at first
        if(isMatch){
            cout << 0 << '\n';
        } else{
            // growth rate same
            if(growthSame){
                cout << -1 << '\n';
            } else{
                for(int i = 0; i <= 10000; i++){
                    for(int jdx = 0; jdx < n; jdx++){
                        plants[jdx].first += growth[plants[jdx].second];
                        // cout << plants[jdx].first << ' ';
                    }
                    // cout << '\n';
                    sort(plants.rbegin(), plants.rend());
                    // for(int jdx = 0; jdx < n; jdx++){
                    //     cout << plants[jdx].first << ": " << want[plants[jdx].second] << '\n';
                    // }
                    // cout << '\n';
                    isMatch = true;
                    for(int jdx = 0; jdx < n; jdx++){
                        if(jdx > 0){
                            if(plants[jdx].first == plants[jdx-1].first){
                                isMatch = false;
                                break;
                            }
                        }
                        if(jdx != want[plants[jdx].second]){
                            isMatch = false;
                            break;
                        }
                    }
                    if(isMatch){
                        cout << i+1 << '\n';
                        break;
                    }
                }
                if(!isMatch){
                    cout << -1 << '\n';
                }
            }
        }
    }
    return 0;
}