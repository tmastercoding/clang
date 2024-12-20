#include <iostream>
using namespace std;

int main(){
    // freopen("2.in", "r", stdin);
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int t = 0, n;
    int tot = 0, prev, max = 0;
    bool isEqual, work;
    int curSum = 0, curSize = 0, want, cnt = 0;
    int arr[100000];
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> n;
        for(int idx = 0; idx < n; idx++){
            cin >> arr[idx];
        }

        // init
        tot = 0, max = 0;
        isEqual = true;
        for(int idx = 0; idx < n; idx++){
            if(idx != 0){
                if(arr[idx] != prev){
                    isEqual = false;
                }
            }
            if(arr[idx] > max){
                max = arr[idx];
            }
            tot += arr[idx];
            prev = arr[idx];
        }
        if(isEqual){
            cout << "0\n";
        } else{
            curSum = 0, curSize = 0, cnt = 0;
            for(int idx = 0; idx < n; idx++){
                curSum += arr[idx];
                if(curSum != 0){
                    if(tot % curSum == 0 && curSum >= max){
                        cnt = idx;
                        want = curSum;
                        curSum = 0, curSize = 0;
                        work = true;
                        for(int jdx = idx+1; jdx < n; jdx++){
                            curSum += arr[jdx];
                            curSize++;
                            if(curSum == want){
                                cnt += curSize-1;
                                curSize = 0;
                                curSum = 0;
                            } else if(jdx == n -1){
                                if(arr[jdx] != 0){
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
    }
    
    return 0;
}