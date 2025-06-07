// The Lazy Cow 10025
#include <iostream>
using namespace std;

int main(){
    // freopen("lazy.in", "r", stdin);å
    // freopen("lazy.out", "w", stdout);
    int n, k, g, pos;
    long long arr[1000010] = {}, prev = 0;
    cin >> n >> k;
    for(int idx = 0; idx < n; idx++){
        cin >> g >> pos;
        arr[pos] = g;
    }

    for(int idx = 0; idx < 1000010; idx++){
        arr[idx] += prev;
        prev = arr[idx];
    }

    int lo = 0, hi = 0;
    long long maxVal = 0;
    while(true){
        hi++;
        if(hi > 1000009) break;
        if(lo+k*2 < hi){
            lo++;
        }
        if(lo > 0){
            if(maxVal < arr[hi]-arr[lo-1]) maxVal = arr[hi]-arr[lo-1];
        } else{
            if(maxVal < arr[hi]) maxVal = arr[hi];
        }
    }
    cout << maxVal << '\n';
    return 0;
}