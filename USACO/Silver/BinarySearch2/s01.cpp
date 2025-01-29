// 기타 레슨 2343
#include <iostream>
using namespace std;

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n, m, mins[100000];
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> mins[i];
    }
    
    long long lo = 0, hi = 1000000000, mid, cnt, sum;
    while(lo+1 < hi){
        mid = (lo+hi)/2;
        cnt = 1, sum = 0;
        for(int i = 0; i < n; i++){
            sum += mins[i];
            if(sum > mid){
                if(mins[i] > mid){
                    cnt = 1000000000;
                    break;
                }
                sum = mins[i];

                cnt++;
            }
        }
        // cout << mid << ' ' <<cnt << '\n';

        if(cnt <= m){
            hi = mid;
        } else{
            lo = mid;
        }
    }
    cout << hi << '\n';
    return 0;
}