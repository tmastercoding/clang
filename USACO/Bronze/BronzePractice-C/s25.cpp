#include <iostream>
using namespace std;

int main(){
    char movements[1000000][2]; // b move, lmove
    int eSize, bSize;
    cin >> bSize >> eSize;

    int time;
    char dir;
    int totTime = 0;
    int timeIdx = 0;

    for(int idx = 0; idx < bSize; idx++){
        cin >> time >> dir;
        for(int jdx = 0; jdx < time; jdx++ ){
            movements[timeIdx][0] = dir;
            timeIdx++;
        }
    }
    totTime = timeIdx;

    timeIdx = 0;
    for(int idx = 0; idx < eSize; idx++){
        cin >> time >> dir;
        for(int jdx = 0; jdx < time; jdx++ ){
            movements[timeIdx][1] = dir;
            timeIdx++;
        }
    }
    if(timeIdx > totTime){
        totTime = timeIdx;
    } 
    
    // for(int idx = 0; idx < totTime; idx++){
    //     if(!movements[idx][0]){
    //         movements[idx][0] = 'S';
    //     } 
    //     if(!movements[idx][1]){
    //         movements[idx][1] = 'S';
    //     }
    //     // cout << movements[idx][0] << " " << movements[idx][1] << '\n';
    // }
    long long bPos = 0, ePos = 0;
    int cnt = 0;
    bool prevMeet = false;
    for(int idx = 0; idx < totTime; idx++){
        if(bPos == ePos){
            if(!prevMeet){
                cnt++;
                prevMeet = true;
                // cout << bPos << " " << ePos << '\n';
            }
        } else{
            prevMeet = false;
        }

        if(movements[idx][0] == 'R'){
            bPos++;
        }
        if(movements[idx][0] == 'L'){
            bPos--;
        }
        if(movements[idx][1] == 'R'){
            ePos++;
        }
        if(movements[idx][1] == 'L'){
            ePos--;
        }
        // cout << bPos << " " << ePos << '\n';
    }
    cout << cnt-1 << '\n';
    return 0;
}