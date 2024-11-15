#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    // freopen("3.in", "r", stdin);

    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n, t;
    cin >> t;
    long long int plants[200000], growth[200000], wantArr[200000];
    pair<long long int, int> temp;
    for(int cnt = 0; cnt < t; cnt++){
        // height, idx
        vector<pair<long long int, int>> want, heights;
        
        cin >> n;
        for(int idx = 0; idx < n; idx++){
            cin >> plants[idx];
            temp.first = plants[idx];
            temp.second = idx;
            heights.push_back(temp);
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
            cin >> temp.first;
            temp.second = idx;
            wantArr[idx] = temp.first;
            want.push_back(temp);
        }

        sort(heights.rbegin(), heights.rend());
        bool isMatch = true;
        for(int idx = 0; idx < n; idx++){
            if(idx > 0){
                if(heights[idx].first == heights[idx-1].first){
                    isMatch = false;
                    break;
                }
            }
            // cout << plants[idx].first << ' ' << plants[idx].second << '\n'; 
            if(idx != want[heights[idx].second].first){
                isMatch = false;
                break;
            }
        }

        if(isMatch){
            cout << 0 << '\n';
        } else{

            sort(want.begin(), want.end());
            if(growthSame && n>1){
                cout << -1 << '\n';
            } else{
                long long int hdif[200000], gdif[200000];
                for(int idx = 0; idx < n-1; idx++){
                    hdif[idx] = plants[want[idx].second] - plants[want[idx+1].second];
                    gdif[idx] = growth[want[idx].second] - growth[want[idx+1].second];
                }
                long long int max = -1;
                for(int idx = 0; idx < n-1; idx++){
                    if(gdif[idx] != 0){
                        // cout << hdif[idx]/ -gdif[idx]<< ' ';
                        if(max < hdif[idx]/ -gdif[idx]){
                            max = hdif[idx]/ -gdif[idx];
                        }
                    }
                }
                for(long long int idx = 0; idx < max+1; idx++){
                    for(int jdx = 0; jdx < n; jdx++){
                        heights[jdx].first += growth[heights[jdx].second];
                        // cout << plants[jdx].first << ' ';
                    }
                    // cout << '\n';
                    sort(heights.rbegin(), heights.rend());
                    // for(int jdx = 0; jdx < n; jdx++){
                    //     cout << plants[jdx].first << ": " << want[plants[jdx].second] << '\n';
                    // }
                    // cout << '\n';
                    isMatch = true;
                    for(int jdx = 0; jdx < n; jdx++){
                        if(jdx > 0){
                            if(heights[jdx].first == heights[jdx-1].first){
                                isMatch = false;
                                break;
                            }
                        }
                        if(jdx != wantArr[heights[jdx].second]){
                            isMatch = false;
                            break;
                        }
                    }
                    if(isMatch){
                        cout << idx+1 << '\n';
                        break;
                    }
                }
                if(!isMatch){
                    cout << -1 << '\n';
                }
                // cout << '\n';
                // cout << max+1 << '\n';
            }
        }
    }


    return 0;
}