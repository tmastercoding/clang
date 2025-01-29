#include <iostream>
#include <algorithm>
using namespace std;

long long A[1000000] = {}, B[1000000] = {}, ansHi, ansLo;
int main(){
    int t;
    cin >> t;
    for(int idx = 0; idx < t; idx++){
        int n, m;
        cin >> n >> m;
        for(int i = 0; i < n; i++){
            cin >> A[i];
        }
        for(int i = 0; i < m; i++){
            cin >> B[i];
        }
        sort(B, B+m);
        long long sum = 0;

        for(int i = 0; i < n; i++){
            int lo = 0, hi = m-1, mid;
            while(lo < hi){
                mid = (lo+hi+1)/2;
                // cout << B[lo] << ' ' <<  B[mid] << ' ' << B[hi] << '\n';
                if( B[mid] < A[i]){
                    lo = mid;
                } else{
                    hi = mid-1;
                }
            }
            // cout << B[lo] << ' ' << lo << '\n';
            ansLo = B[lo];
            lo = 0, hi = m-1;
            while(lo < hi){
                mid = (lo+hi)/2;
                // cout << B[lo] << ' ' <<  B[mid] << ' ' << B[hi] << '\n';
                if( B[mid] >= A[i]){
                    hi = mid;
                } else{
                    lo = mid+1;
                }
            }
            // cout << B[lo] << ' '<<lo << '\n';
            ansHi= B[lo];
            if(abs(ansLo-A[i]) <= abs(ansHi-A[i])){
                sum += ansLo;
            } else{
                sum += ansHi;
            }
            // cout << ansLo << ' '<< ansHi << '\n';
        }
        cout << sum<<'\n';
    }

    return 0;
}