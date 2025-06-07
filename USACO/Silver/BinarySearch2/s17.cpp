// Music Notes 6010
#include <iostream>
using namespace std;

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

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

    for(int i = 0; i < q; i++){
        long long find, lo = 0, hi = n, mid;
        cin >> find;
        while(lo < hi){
            mid = (lo+hi)/2;
            if(sums[mid] > find){
                hi = mid;
            } else{
                lo = mid+1;
            }
        }
        cout << lo+1 << '\n';

    }
    return 0;
}