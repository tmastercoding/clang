// 휴게소 세우기 1477
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n, m, l, rests[53];
    cin >> n >> m >> l;
    rests[0] = 0;
    for(int i = 1; i < n+1; i++){
        cin >> rests[i];
    }

    rests[n+1] = l;
    sort(rests, rests+n+2);


    int lo = 0, hi = l-1, mid, start, cnt, temp, idx;
    while(lo+1 < hi){
        mid = (lo+hi)/2;
        start = 0, cnt = 0;

        for(int idx = 1; idx < n+2; idx++){
            cnt += (rests[idx]-rests[idx-1]-1)/mid;
        }        
        

        // cout << mid << ' ' << cnt << ' '<< lo << ' ' << hi <<'\n';

        if(cnt <= m){
            hi = mid;
        } else{
            lo = mid;
        }
    }
    
    cout << hi << '\n';
    return 0;
}