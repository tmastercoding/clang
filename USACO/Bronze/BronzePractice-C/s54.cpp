#include <iostream>
#include <vector>
using namespace std;

int main(){
    // freopen("2.in", "r", stdin);
    int t = 0;
    cin >> t;
    for(int i = 0; i < t; i++){
        int n;
        cin >> n;
        vector<int> v, nv;
        int temp;
        for(int idx = 0; idx < n; idx++){
            cin >> temp;
            v.push_back(temp);
        }

        // init
        int max = 0;
        bool isEqual = true;
        for(int idx = 0; idx < n; idx++){
            if(idx != 0){
                if(v[idx] != max){
                    isEqual = false;
                }
            }
            if(v[idx] > max){
                max = v[idx];
            }
        }
        // loop
        int cnt = 0;
        if(isEqual){
            cout << cnt << '\n';
        } else{
            
            while(true){
                int curSum = 0, curSize = 0;
                int nMax = 0;
                isEqual = true;
                nv.clear();
                for(int idx = 0; idx < v.size(); idx++){
                    if(max != v[idx]){
                        isEqual = false;
                    }

                    curSum += v[idx];
                    curSize++;
                    if(curSum >= max){
                        nv.push_back(curSum);
                        if(curSum > nMax){
                            nMax = curSum;
                        }
                        // cout << "normal" << cnt << '\n';
                        cnt += curSize - 1;
                        curSum = 0;
                        curSize = 0;
                    } else if(idx == v.size()-1 && idx != 0){
                        if(!isEqual){
                            nv[nv.size()-1] += curSum;
                            // cout << cnt << '\n';
                            cnt+= curSize;
                            // cout << cnt << '\n';
                        }
                    }
                    // if(v[idx] < max && idx < v.size()-1){
                    //     nv.push_back(v[idx] + v[idx+1]);
                    //     if(v[idx]+v[idx+1] > nMax){
                    //         nMax = v[idx]+v[idx+1];
                    //     }
                    //     cnt++;
                    //     idx++;
                    //     continue;
                    // } 
                }


                // for(int idx = 0; idx < nv.size(); idx++){
                //     cout << nv[idx] << ' ';
                // }
                // cout << '\n';

                v = nv;
                max = nMax;
                if(isEqual){
                    break;
                }
            }
            cout << cnt << '\n';
        }

    }
    return 0;
}