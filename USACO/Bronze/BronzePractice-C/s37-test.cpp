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

    int cnts[gSize];

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
    }

    int minCnt = 300001, cnt = 0;
    for(int days = 0; days < 3; days++){
        cnt = 0;
        bool finished = true;
        for(int idx = 0; idx < gSize; idx++){
            if(days == 0){
                cnt += cnts[idx];
            } else{
                if(cnts[idx]/days <= 2){
                    finished = false;
                    break;
                }
                if(cnts[idx]>3){
                    // cout << days << '\n';
                    int start, end, sReach, eReach, cur;
                    cur = cnts[idx];
                    while(1){
                        start = days;
                        end = cur - 1 -days;
                        sReach = start+days;
                        eReach = end-days;
                        // cout << start << ' ' << end <<'\n';
                        // cout << sReach << ' ' << eReach << '\n';
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
                        // cout << cur << '\n';
                        // cout << cnt << ' ';

                    }
                    // cout << '\n';
                    // int middle = cnts[idx]-2*(days+1);
                    // cout << "day: " << day << " len: " << cnts[idx] << '\n';
                    // cout << middle << '\n';
                    // cnt += 2+(int)(middle/(2*days+1));
                } else{
                    cnt++;
                }
            }
            // cout << "asdf: " << cnt << '\n';
        }
        if(finished){
            if(cnt < minCnt){
                minCnt = cnt;
            }
        }
    }

    return 0;

}