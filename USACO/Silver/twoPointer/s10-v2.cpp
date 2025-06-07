// Paired Up 14527
#include <iostream>
#include <algorithm>
using namespace std;

int main(){   
    freopen("pairup.in", "r", stdin);
    freopen("pairup.out", "w", stdout);
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    pair<long long, long long> arr[100000] = {};
    long long x, y, m = 0;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x >> y;
        m += x;
        arr[i] = {y, x};
    }
    sort(arr, arr+n);

    long long lo = 0, ldx = 0, hi = m, hdx = n-1, max = 0;
    while(ldx < hdx){
        if(arr[ldx].first+arr[hdx].first > max) max = arr[ldx].first+arr[hdx].first;
        if(arr[ldx].second < arr[hdx].second){
            arr[hdx].second -= arr[ldx].second;
            // lo+= arr[ldx].second, hi-= arr[ldx].second;
            arr[ldx].second = 0;
        } else{
            arr[ldx].second -= arr[hdx].second;
            // lo+= arr[hdx].second, hi-= arr[hdx].second;
            arr[hdx].second = 0;
        }
        // cout << lo << ' ' << hi << '\n';
        if(arr[ldx].second == 0) ldx++;
        if(arr[hdx].second == 0) hdx--;
    }
    
    cout << max << '\n';
    return 0;
}