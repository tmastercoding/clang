#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    // freopen("6.in", "r", stdin);

    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n, t;
    cin >> t;
    for(int i = 0; i < t; i++){
        // pos, height, growth 
        vector<vector<long long int>> plants;
        vector<long long int> temp;
        long long int height;
        cin >> n;
        for(int idx = 0; idx < n; idx++){
            cin >> height;
            temp = {0, height, 0};
            plants.push_back(temp);
        }

        for(int idx = 0; idx < n; idx++){
            cin >> plants[idx][2];
        }
        for(int idx = 0; idx < n; idx++){
            cin >> plants[idx][0];
        }

        sort(plants.begin(), plants.end());
        // for(int idx = 0; idx < n; idx++){
        //     cout << plants[idx][0]<< ' ' << plants[idx][1]<< ' ' << plants[idx][2] << '\n';
        // }

        if(n == 1){
            cout << 0 << '\n';
        } else{
            long long int minval = 0, maxval = 1000000000, curMin, curMax, dif;
            for(int idx = 0; idx < n-1; idx++){
                curMin = 1000000000, curMax =0;
                bool isMin = false;
                // minval
                if(plants[idx][2] > plants[idx+1][2]){
                    // cout << "MIN\n";
                    isMin = true;
                    dif = plants[idx][1]-plants[idx+1][1];
                    if(dif < 0){
                        curMin = dif*-1/(plants[idx][2]-plants[idx+1][2]);
                        // if((double)(dif*-1)/(double)(plants[idx][2]-plants[idx+1][2]) == curMin){
                        //     curMin++;
                        // }
                        curMin++;
                    } else{
                        curMin = 0;
                    }
                } else if (plants[idx][2] < plants[idx+1][2]) {
                    // cout << "MAX\n";
                    dif = plants[idx][1] - plants[idx+1][1];
                    if(dif < 0){
                        curMax = -1;
                        // break;
                    } else{
                        curMax = dif/(plants[idx][2]-plants[idx+1][2])*-1;
                        curMax++;
                        // cout << "curMax: " << curMax << '\n';
                        // cout << "asdf " << (plants[idx][1] + (curMax-1) * plants[idx][2]) << ' ' << (plants[idx+1][1] + (curMax-1) * plants[idx+1][2]) << '\n';
                        if((plants[idx][1] + (curMax-1) * plants[idx][2]) == (plants[idx+1][1] + (curMax-1) * plants[idx+1][2])){
                            curMax--;
                        }
                    }
                } else{
                    // cout << "SAME\n";
                    if(plants[idx][1] <= plants[idx+1][1]){
                        minval = -1;
                        maxval = -1;
                        break;
                    } else{
                        curMax = 1000000000;
                        curMin = 0;
                    }
                }
        
                // cout << curMax << ' ' << curMin << '\n';
                if(!isMin){
                    if(curMax < maxval){
                        maxval = curMax;
                    }
                } else{
                    if(curMin > minval){
                        minval = curMin;
                    }
                }
            }

            // cout << i << ": " << minval << ' ' << maxval << '\n';
            if(minval >= maxval){
                cout << -1 << '\n';
            } else{
                cout << min(minval, maxval) << '\n';
            }
            // if(minval> maxval){
            //     cout << -1 << '\n';
            // } else{
            //     cout << minval << '\n';
            // }
        }
    }
    return 0;
}