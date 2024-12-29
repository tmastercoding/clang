// 이상한 술집 13702
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n, k, pots[10000];
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> pots[i];
    }

    sort(pots, pots+n);
    long long lo = 0, hi = 2147483647, mid;
    while(lo < hi){
        mid = (lo+hi+1)/2;
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += pots[i]/mid;
        }
        // cout << hi << '\n';
        // cout << mid << ' ' << sum << '\n';
        if(sum < k){
            hi = mid-1;
        } else{
            lo = mid;
        }
    }
    cout << lo << '\n';

    return 0;
}