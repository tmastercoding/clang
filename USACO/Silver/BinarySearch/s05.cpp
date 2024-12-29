// 나무 자르기 2805
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    long long n, m;
    cin >> n >> m;
    long long trees[1000000],sum;
    for(int i = 0; i < n; i++){
        cin >> trees[i];
    }

    sort(trees, trees+n);
    

    long long lo = 0, hi = trees[n-1], mid;
    while(lo < hi){
        mid = (lo + hi+1)/2;
        sum = 0;
        for(int i = 0; i < n; i++){
            if(mid < trees[i]){
                sum += trees[i] - mid;
            }
        }
        // cout << mid << ' ' << sum << '\n';
        if(sum < m){
            hi = mid-1;
        } else{
            lo = mid;
        }
    }
    cout << lo<< '\n';

    return 0;
}