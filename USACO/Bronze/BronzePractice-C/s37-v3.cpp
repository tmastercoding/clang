// Cowntact Tracing 2 31064
#include <iostream>
#include <string>
using namespace std;

int main(){
    // freopen("9.in", "r", stdin);

    int size;
    cin >> size;
    string cows;
    cin >> cows;

    int groups[300000][2];
    int gSize = 0;
    bool hasFound = false, hasStart= false;

    for(int idx = 0; idx < size; idx++){
        if(!hasFound){
            if(cows[idx] == '1'){
                groups[gSize][0] = idx;
                groups[gSize][1] = idx;
                hasFound = true;
                hasStart = true;
            }
        } else{
            if(cows[idx] == '1'){
                if(hasStart){
                    groups[gSize][1] = idx;
                } else{
                    groups[gSize][0] = idx;
                    groups[gSize][1] = idx;
                    hasStart = true;
                }
            } else{
                if(hasStart){
                    hasStart = false;
                    gSize++;
                }
            }
        }
    }
    if(hasFound && hasStart){
        gSize++;
    }

    // none infected
    if(gSize == 0){
        cout << 0 << '\n';
    } else if(gSize == 1){
        int cnt = groups[0][1] - groups[0][0] + 1;
        // odd
        if(cnt & 1 || cnt == size || groups[0][0] == 0 || groups[0][1] == size-1){
            cout << 1 << '\n';
        } else{
            cout << 2 << '\n';
        }
    } else{
        int cnts[gSize];
        // int minCnt = 300001;
        int minDay = 300001;
        int day;
        for(int idx = 0; idx < gSize; idx++){
            cnts[idx] = groups[idx][1]-groups[idx][0] + 1;
            // if(cnts[idx] & 1){
            if(groups[idx][0] == 0 || groups[idx][1] == size-1){
                day = cnts[idx]-1;
            }else{
                day = (cnts[idx]-1)/2;

            }
            if(minDay > day){
                minDay = day;
            }

        }

        // cout << minDay << '\n';
        int minCnt = 300001, cnt = 0 ,temp;
        cnt = 0;
        for(int idx = 0; idx < gSize; idx++){
            if(minDay == 0){
                cnt += cnts[idx];
            } else{
                // cout << days << ' ' << cnts[idx] << '\n'; 
                temp = (int)(cnts[idx]/(minDay*2+1));
                // cout << temp << '\n';
                if(temp != (double)cnts[idx]/(minDay*2+1)){
                    temp++;
                }
                cnt+=temp;
                // if(groups[idx][0] == 0){
                //     // cout << "adsf" << '\n';n
                //     cout << temp << '\n';
                // } else if(groups[idx][1] == size-1){
                //     temp = (int)(cnts[idx]/(minDay*2+1));
                //     cout << temp << '\n';
                //     if(temp != (double)cnts[idx]/(minDay*2+1)){
                //         temp++;
                //     }
                //     cout << temp << '\n';
                //     cnt+=temp;
                // } else{
                //     if(cnts[idx]>3){
                //         int start, end, sReach, eReach, cur;
                //         cur = cnts[idx];
                        
                //         while(1){
                //             start = minDay;
                //             end = cur - 1 -minDay;
                //             sReach = start+minDay;
                //             eReach = end-minDay;

                //             if(start == end){
                //                 cnt++;
                //                 break;
                //             } else if(sReach+2 > eReach){
                //                 cnt += 2;
                //                 break;
                //             } else{
                //                 cnt+=2;
                //             }
                //             cur = end-start-1;
                //         }

                //     } else{
                //         cnt++;
                //     }
                // }
            }
        }

        cout << cnt  << '\n';
    }
    return 0;
}