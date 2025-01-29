#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    // freopen("angry.in", "r", stdin);
    // freopen("angry.out", "w", stdout);
    int n, k;
    long long bales[50000];
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> bales[i];
    }
    sort(bales, bales+n);

    long long lo = 0, mid, hi = 1000000000, cnt, cur, idx;
    while(lo < hi){
        mid = (lo+hi)/2;
        cnt = 1, idx = 0;
        cur = bales[0]+mid*2;
        while(true){
            if(idx >= n){
                break;
            }
            if(cur >= bales[idx]){
                idx++;
            } else{
                cur = bales[idx]+mid*2;
                cnt++;
            }
        } 
        if(cnt <= k){
            hi = mid;
        } else{
            lo = mid+1;
        }
    } 
    cout << lo << '\n';
    return 0;
}