// Predictable Queue 16510
#include <iostream>
using namespace std;

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n, m;
    long long arr[200001], t;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        if(i > 0) arr[i] += arr[i-1];
    }    

    for(int i = 0; i < m; i++){
        cin >> t;
        long long lo = 0, hi = n-1, mid;
        while(lo < hi){
            mid = (lo+hi+1)/2;
            if(arr[mid] <= t){
                lo = mid;
            } else{
                hi = mid-1;
            }
        }
        if(t < arr[lo]) {
            cout << lo << '\n';
        } else{
            cout << lo+1 << '\n';
        }
    }
    return 0;
}