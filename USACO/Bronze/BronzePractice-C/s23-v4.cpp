#include <iostream>
using namespace std;

int main(){
    int size = 0;
    cin >> size;
    int cows[size];
    for(int idx = 0; idx < size; idx++){
        cin >> cows[idx];
    }
    // for(int idx = 0; idx < size; idx++){
    //     cout << cows[idx] << " ";
    // }
    // cout << endl;

    int prev = 1;
    int cnt = 0;
    int prevCnt, curCnt;
    bool hasSwapped = false;

    for(int idx = 0; idx < size; idx++){
        if(cows[idx] != prev){
            if(hasSwapped){
                cnt++;
            }
            prevCnt = 0, curCnt = 0;
            for(int jdx = idx; jdx < size; jdx++){
                if(cows[jdx] == cows[idx]){
                    curCnt++;
                } else{
                    prevCnt++;
                }
            }
            if(prevCnt >= curCnt){
                cnt++;
            } else{
                prev = 2;
                hasSwapped = true;
            }
        }
    }
    cout << cnt << '\n';

    return 0;
}