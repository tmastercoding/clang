#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    long long l, n, m, rocks[50001];
    cin >> l >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> rocks[i];
    }
    rocks[n] = l;

    sort(rocks, rocks+n);
    long long lo = 1, hi = 1000000000, mid, cnt, prev;
    while(lo < hi){
        mid = (lo+hi+1)/2;
        cnt = 0, prev = 0;
        for(int i = 0; i <= n; i++){
            if(rocks[i]-prev < mid){
                cnt++;
            } else{
                prev = rocks[i];
            }
        }
        // cout << cnt << ' ' << lo << ' ' << mid << ' ' << hi << '\n';
        if(cnt <= m){
            lo = mid;
        } else{
            hi = mid-1;
        }
    }
    cout << lo << '\n';
    return 0;
}