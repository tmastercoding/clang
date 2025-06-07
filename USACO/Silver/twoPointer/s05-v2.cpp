// 회전 초밥 15961
#include <iostream>
using namespace std;

int n, d, k, c, plates[3003002] = {}, cnts[3002] = {};
int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> d >> k >> c;
    for(int i = 0; i < n; i++){
        cin >> plates[i];
    }
    for(int i = 0; i < k; i++){
        plates[n+i] = plates[i];
    }
    // for(int i = 0; i < n+k; i++){
    //     // cout << plates[i] << ' ';
    // }
    // cout << '\n';
    cnts[c] = 1;
    int lo = 0, hi = -1, types = 1, max = 0;
    // bool hasUsed = false;
    while(true){
        hi++;
        if(hi > n+k-1) break;
        if(cnts[plates[hi]] == 0) types++;
        cnts[plates[hi]]++;

        if(hi-lo == k){
            if(cnts[plates[lo]] == 1) types--;
            cnts[plates[lo]]--;
            lo++;
            if(types > max) max = types;
        }
    }
    cout << max << '\n';
    return 0;
}