// 과자 나눠주기 16401
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int m, n;
    long long lengths[1000000];
    cin >> m >> n;
    for(int i = 0; i < n; i++){
        cin >> lengths[i];
    }
    sort(lengths, lengths+n);

    long long lo = 0, hi = 1000000000, mid, sum;
    while(lo < hi){
        mid = (lo + hi + 1)/2;
        sum = 0;
        for(int i = 0; i < n; i++){
            sum += lengths[i]/mid;
        }
        if(sum < m){
            hi = mid-1;
        } else{
            lo = mid;
        }
    }
    cout << lo << '\n';
    return 0;
}