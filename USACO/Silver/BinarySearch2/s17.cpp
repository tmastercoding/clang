#include <iostream>
using namespace std;

int main(){
    int n, q;
    long long sums[50000] = {}, length;

    cin >> n >> q;
    
    for(int i = 0; i < n; i++){
        cin >> length;
        if(i > 0){
            sums[i] = sums[i-1] + length;
        } else{
            sums[i] = length;
        }
    }

    long long find, lo = 0, hi = n, mid, ans1, ans2;
    cin >> find;
    while(lo < hi){
        mid = (lo+hi)/2;
        cout << mid << '\n';
        if(sums[mid] < find){
            hi = mid;
        } else{
            lo = mid+1;
        }
    }
    ans1 = lo;
    // lo = 0, hi = n;
    // while(lo < hi){
    //     mid = (lo+hi+1)/2;
    //     cout << mid << '\n';
    //     if(sums[mid] > find){
    //         hi = mid-1;
    //     } else{
    //         lo = mid;
    //     }
    // }
    cout << ans1 << ' ' << lo << '\n';
    return 0;
}