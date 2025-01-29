// 랜선 자르기 1654
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    long long k, n, wires[10000];
    cin >> k >> n;
    for(int i = 0; i < k; i++){
        cin >> wires[i];
    }
    sort(wires, wires+k);

    long long lo = 0, hi = 2147483647, mid;
    while(lo < hi){
        mid = (lo+hi+1)/2;
        long long cnt = 0;
        for(int i = 0; i < k; i++){
            // if(mid <= wires[i]){
            cnt += wires[i]/mid;
            // }
        }
        if(cnt < n){
            hi = mid-1;
        } else{
            lo = mid;
        }
    }
    cout << hi << '\n';
    return 0;
}