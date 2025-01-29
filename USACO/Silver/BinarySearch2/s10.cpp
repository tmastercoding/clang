#include <iostream>
using namespace std;

int main(){
    int n, m, arr[5000];
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int lo = 0, hi = 9999, mid, min, max, cnt;
    while(lo < hi){
        mid = (lo+hi)/2;
        min = 10000, max = 1, cnt = 0;
        for(int i = 0; i < n; i++){
            if(min > arr[i]){
                min = arr[i];
            }
            if(max < arr[i]){
                max = arr[i];
            }
            if(max - min > mid){
                cnt++;
                min = arr[i];
                max = arr[i];
            }
        }
        // cout << cnt << ' ' << lo  << ' ' << mid << ' ' << hi << '\n';
        if(cnt < m){
            hi = mid;
        } else{
            lo = mid+1;
        }
    }
    cout << lo << '\n';
    return 0;
}