// 회전 초밥 15961
#include <iostream>
using namespace std;

int n, d, k, c, plates[3003001] = {}, cnts[3001] = {};
int main(){
    cin >> n >> d >> k >> c;
    for(int i = 0; i < n; i++){
        cin >> plates[i];
    }
    for(int i = 0; i < k; i++){
        plates[n+i] = plates[i];
    }
    for(int i = 0; i < n+k; i++){
        cout << plates[i] << ' ';
    }
    cout << '\n';

    int lo = 0, hi = -1, types = 0, max = 0;
    bool hasUsed = false;
    while(true){
        hi++;
        if(lo >= n) break;
        cout << lo << ' ' << hi << ' ';
        if(!cnts[plates[hi]]) types++;
        if(plates[hi] == c) hasUsed = true;
        cnts[plates[hi]]++;
        if(hi-lo > k-1){
            if(cnts[plates[lo]] == 1) types--;
            cnts[plates[lo]]--;
            if(plates[lo] == c) hasUsed = false;
            cout << types << ' ' << hasUsed << '\n';
            if(max <= types){
                if(!hasUsed){
                    max = types+1;
                    cout << types << ' ' << '\n';
                    cout << "HERE\n";
                } else{
                    max = types;
                }
            }
            lo++;
        }
    }
    cout << max << '\n';
    return 0;
}