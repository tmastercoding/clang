// Social Distancing I 18880
#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int main(){
    freopen("socdist1.in", "r", stdin);
	freopen("socdist1.out", "w", stdout);
    int size;
    cin >> size;
    string temp;
    int stalls[size];

    cin >> temp;
    for(int idx = 0; idx < size; idx++){
        stalls[idx] = temp[idx]-'0';
    }

    int prev = -1;
    int minDist = 100000, totMaxDist = 0;
    for(int cow1 = 0; cow1 < size; cow1++){
        if(stalls[cow1]){
            continue;
        }
        for(int cow2 = cow1; cow2 < size; cow2++){
            if(stalls[cow2]){
                continue;
            }
            if(cow1 == cow2){
                continue;
            } 
            prev = -1;
            minDist = 100000;
            stalls[cow1] = 1;
            stalls[cow2] = 1;
            for(int idx = 0; idx < size; idx++){
                if(stalls[idx]){
                    if(prev == -1){
                        prev = idx;
                    } else{
                        if(idx - prev < minDist){
                            minDist = idx - prev;
                        }
                        prev = idx;
                    }
                }
            }
            stalls[cow1] = 0;
            stalls[cow2] = 0;
            if(minDist > totMaxDist){
                totMaxDist = minDist;
            }
        }
    }

    cout << totMaxDist << '\n';
    return 0;
}