#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    // freopen("convention.in", "r", stdin);
    // freopen("convention.out", "w", stdout);

    int n, m, c;
    long long cows[100000];
    cin >> n >> m >> c;
    for(int i = 0; i < n; i++){
        cin >> cows[i];
    } 
    sort(cows, cows+n);

    long long lo = 0, mid, hi = 1000000000, busCnt, cnt, start;

    while(lo < hi){
        mid = (lo+hi)/2;
        start = cows[0], cnt = 1, busCnt = 0;
        bool lastChanged = false;
        for(int i = 1; i < n; i++){
            if(cows[i] - start > mid || cnt >= c){

                busCnt++;
                cnt = 0;
                start = cows[i];
                // cout << i << ' ' << start << "\n";
            }
            cnt++;
        }
        if(!lastChanged){
            busCnt++;

        }

        // cout << busCnt << ' ' << lo << ' ' << hi<< '\n';
        if( busCnt <= m){
            hi = mid;
        } else{
            lo = mid+1;
        }
    } 
    cout << lo << '\n';
    return 0;
}