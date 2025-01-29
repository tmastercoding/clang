#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int m, n;
    long long l, shots[100000] = {};
    pair<long long, long long> birds[100000] = {};
    cin >> m >> n >> l;
    for(int i = 0; i < m; i++){
        cin >> shots[i];
    }
    sort(shots, shots+m);
    for(int i = 0; i < n; i++){
        cin >> birds[i].first >> birds[i].second;
    }

    long long lo = 0, hi = m, mid, pre, post;
    int cnt = 0;
    for(int i = 0; i < n; i++){
        lo = 0, hi = m-1;
        while(lo < hi){
            mid = (lo+hi)/2;
            // cout << mid << '\n';
            if(shots[mid] >= birds[i].first){
                hi = mid;
            } else{
                lo = mid+1;
            }
        }
        pre = lo;
        lo = 0, hi = m-1;
        while(lo < hi){
            mid = (lo+hi+1)/2;
            // cout << mid << '\n';
            if(shots[mid] > birds[i].second){
                lo = mid;
            } else{
                hi = mid-1;
            }
        }
        post = lo;
        bool added = false;
        // cout << pre << ' ' << post << '\n';
        if(pre-1 < m && pre-1 > -1){
            // cout << abs(shots[pre]-birds[i].first)<<"\n";
            if(abs(shots[pre-1]-birds[i].first) + birds[i].second <= l){
                cnt++;
                added = true;
            }
        }
        if(!added && pre < m && pre > -1){
            // cout << abs(shots[pre]-birds[i].first)<<"\n";
            if(abs(shots[pre]-birds[i].first) + birds[i].second <= l){
                cnt++;
                added = true;
            }
        }
        if(!added && post < m && post > -1){
            if(abs(shots[post]-birds[i].first) + birds[i].second <= l){
                cnt++;
            }
        }
        // break;
    }
    cout << cnt << '\n';
    return 0;
}