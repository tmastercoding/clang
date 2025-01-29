#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;
    pair<long long, long long> threads[100000];
    long long x, l;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x >> l;
        threads[i] = {x, x+l};
    }
    sort(threads, threads+n);

    long long lo =1, mid, hi = 2000000000, cnt, prev;
    while(lo < hi){
        mid = (lo+hi+1)/2;
        cnt = 1, prev = threads[0].first;
        bool flag = true;
        for(int i = 1; i < n; i++){
            if(threads[i].first > prev+mid){
                prev = threads[i].first;
                cnt++;
            } else if(threads[i].second >= prev+mid){
                prev += mid;
            } else{
                flag = false;
                break;
            }
        }
        // cout << cnt << ' ' << lo << ' ' << hi << '\n';
        if(flag){
            lo = mid;
        } else{
            hi = mid-1;
        }

    }
    cout << lo << '\n';
    return 0;
}