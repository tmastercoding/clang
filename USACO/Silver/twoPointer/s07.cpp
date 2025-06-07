//  두 개의 탑 2118
#include <iostream>
using namespace std;

int main(){
    int n;
    long long arr[200000] = {}, og[200000], prev = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> og[i];
        arr[i] = og[i]+prev;
        prev = arr[i];
    }
    // for(int i = 0; i < n; i++){
    //     arr[n+i] = og[i]+prev;
    //     prev = arr[n+i];
    // }
    // for(int i = 0; i < n; i++){
    //     arr[n+n+i] = og[i]+prev;
    //     prev = arr[n+n+i];
    // }
    // for(int i = 0; i < n*2; i++) cout << arr[i] << ' ';
    // cout << '\n';

    long long lo = 0, hi = -1, max = 0, dist = 0;
    while(true){
        hi++;
        if(hi > n*2-1) break;
        if(n & 1){
            if(hi > n/2+lo+1) lo++;
        } else{
            if(hi >= n/2+lo) lo++;
        }
        // cout << lo << " " << hi << '\n';
        // cout << "arr: " << arr[hi] - arr[lo] << ' ' << arr[lo+n]-arr[hi]<< '\n';
        if(arr[hi]-arr[lo] < arr[lo+n]-arr[hi]){
            dist = arr[hi]-arr[lo];
            // cout << dist << '\n';
        } else{
            dist = arr[lo+n]-arr[hi];
        }
        // cout << dist << '\n';
        if(dist > max) max = dist;

    }
    cout << max << '\n';
    return 0;
}