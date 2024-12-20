#include <iostream>
#include <vector>
using namespace std;

int main(){
    // freopen("2.in", "r", stdin);
    int t = 0, n, temp;
    int tot = 0, prev, max = 0;
    bool isEqual, work;
    int curSum = 0, curSize = 0, want, cnt = 0;
    vector<int> v;
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> n;
        v.clear();
        for(int idx = 0; idx < n; idx++){
            cin >> temp;
            v.push_back(temp);
        }

        // init
        tot = 0, max = 0;
        isEqual = true;
        for(int idx = 0; idx < n; idx++){
            if(idx != 0){
                if(v[idx] != prev){
                    isEqual = false;
                }
            }
            if(v[idx] > max){
                max = v[idx];
            }
            tot += v[idx];
            prev = v[idx];
        }
        if(isEqual){
            cout << "0\n";
        } else{
            curSum = 0, curSize = 0, cnt = 0;
            for(int idx = 0; idx < n; idx++){
                curSum += v[idx];
                if(tot % curSum == 0 && curSum >= max){
                    cnt = idx;
                    want = curSum;
                    curSum = 0, curSize = 0;
                    work = true;
                    for(int jdx = idx+1; jdx < n; jdx++){
                        curSum += v[jdx];
                        curSize++;
                        if(curSum == want){
                            cnt += curSize-1;
                            curSize = 0;
                            curSum = 0;
                        } else if(jdx == n -1){
                            if(v[jdx] != 0){
                                work = false;
                            } else{
                                cnt++;
                            }
                        }
                    }
                    if(work){
                        cout << cnt << '\n';
                        break;
                    }
                    curSum = want;
                }
            }
        }
    }

    return 0;
}