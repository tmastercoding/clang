// Aggressive cows 2110]
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n, c;
    long long barns[200000];
    cin >> n >> c;
    for(int i = 0; i < n; i++){
        cin >> barns[i];
    }

    sort(barns, barns+n);
    long long lo = 1, hi = 1000000000, mid, cnt, start;
    while(lo < hi){
        mid = (lo+hi+1)/2;
        start = barns[0], cnt = 1;
        for(int i = 1; i < n; i++){

            if(barns[i]-start >= mid){
                cnt++;
                start = barns[i];
            }
        }   
        // cout << mid << ' ' << cnt << ' '<< lo << ' ' << hi <<'\n';
        if(cnt < c){
            hi = mid-1;
        } else{
            lo = mid;
        }
    }
    cout << lo << '\n';
    return 0;
}