// 수 고르기 2230
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;
    long long arr[100000], m, min = 2000000000, dif;
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr+n);

    int lo = 0, hi = 0;
    while(lo <= hi){
        if(hi >= n) break;
        dif = abs(arr[hi]-arr[lo]);
        if(dif >= m){
            if(dif < min) min = dif;
            lo++;
        } else{
            hi++;
        }
    }
    cout << min << '\n';
    return 0;
}