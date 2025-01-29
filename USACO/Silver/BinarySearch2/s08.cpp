#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    freopen("socdist.in", "r", stdin);
    freopen("socdist.out", "w", stdout);
    int n, m;
    pair<long long, long long> grass[100000];
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> grass[i].first >> grass[i].second;
    }

    sort(grass, grass+m);
    long long lo = 0, mid, hi = 100000000000000000, cnt, cur, add;
    while(lo < hi){
        mid = (lo+hi+1)/2;
        cnt = 0;
        for(int i = 0; i < m; i++){
            if(i > 0){
                if(grass[i].first-cur > mid){
                    cur = grass[i].first;
                    cnt++;
                } else{
                    if(cur+mid <= grass[i].second){
                        cur = cur+mid;
                        cnt++;
                    } else{
                        continue;
                    }
                }
            } else{
                cur = grass[i].first;
                cnt++;
            }
            // cout << grass[i].first  << '\n';
            add = (grass[i].second - cur)/mid;
            cur += add*mid;
            cnt += add;
            // cout << grass[i].first << ' '  << grass[i].second << ' '  << cur << ' ' << cnt << '\n';
        }
        // cout << cnt << '\n';
        // cout << lo << ' ' << hi << '\n';
        if(cnt >= n){
            lo = mid;
        } else{
            hi = mid-1;
        }
    }
    cout << lo << '\n';
    return 0;
}