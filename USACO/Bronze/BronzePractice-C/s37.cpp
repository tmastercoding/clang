// Cowntact Tracing 2 31064
#include <iostream>
#include <string>
using namespace std;

int main(){
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
        if(cnt & 1 || cnt == size){
            cout << 1 << '\n';
        } else{
            cout << 2 << '\n';
        }
    } else{
        int cnts[gSize];
        // int minCnt = 300001;
        int maxDay = 1;
        int day;
        for(int idx = 0; idx < gSize; idx++){
            cnts[idx] = groups[idx][1]-groups[idx][0] + 1;
            if(cnts[idx] & 1){
                day = (cnts[idx]-1)/2;
                if(day > maxDay){
                    maxDay = day;
                }
            } else{
                day = cnts[idx]/2;
                if(day > maxDay){
                    maxDay = day;
                }
            }
            // if(cnts[idx] < minCnt){
            //     minCnt = cnts[idx];
            // }
        }
        // for(int idx = 0; idx < gSize; idx++){
        //     cout << cnts[idx] << '\n';
        // }
        // cout << maxDay << '\n';
        int minCnt = 300001, cnt = 0;
        for(int days = 0; days <= maxDay; days++){
            cnt = 0;
            bool finished = true;
            for(int idx = 0; idx < gSize; idx++){
                if(days == 0){
                    cnt += cnts[idx];
                } else{
                    // cout << days << ' ' << cnts[idx] << '\n';   
                    if(groups[idx][0] == 0 && days == cnts[idx]-1){
                        // cout << "adsf" << '\n';n
                        cnt++;
                    } else if(groups[idx][1] == size-1 && days == cnts[idx]-1){
                        cnt++;
                    } else{
                        if((double)cnts[idx]/days <= 2){
                            finished = false;
                            break;
                        }
                        if(cnts[idx]>3){
                            // cout << days << '\n';
                            int start, end, sReach, eReach, cur;
                            cur = cnts[idx];
                            bool flag = false;
                            if(groups[idx][0] == 0){
                                cur = days*2+1;
                                start = end-cur+1;
                                if(start + days > 0){
                                    cnt++;
                                    flag = true;
                                }  
                            } else if(groups[idx][1] == size-1){
                                cur = days*2+1;
                                end = start+cur+1;
                                if(end - days < size){
                                    cnt++;
                                    flag = true;
                                }  
                            }
                            if (!flag){
                                while(1){
                                    start = days;
                                    end = cur - 1 -days;
                                    sReach = start+days;
                                    eReach = end-days;

                                    if(start == end){
                                        cnt++;
                                        break;
                                    } else if(sReach+2 > eReach){
                                        cnt += 2;
                                        break;
                                    } else{
                                        cnt+=2;
                                    }
                                    cur = end-start-1;
                                }
                            }
    
                        } else{
                            cnt++;
                        }
                    }
                }
            }
            // cout << finished << '\n';
            // cout << days << ": " << cnt << '\n';
            if(finished){
                if(cnt < minCnt){
                    minCnt = cnt;
                }
            }
        }

        cout << minCnt  << '\n';
    }
    return 0;
}