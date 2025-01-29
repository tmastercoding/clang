// 보석 상자 2792
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    long long n, m, colours[300000];
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> colours[i];
    }
    sort(colours, colours+m);
    long long lo = 1, hi = 1000000000, mid, cnt, temp;
    while(lo < hi){
        mid = (lo+hi)/2;
        cnt = 0;
        // maxEL = 0;
        for(int i = 0; i < m; i++){
            if(mid <= colours[i]){
                temp = colours[i]/mid;
                cnt+=temp;
                if((double)temp != (double)colours[i]/(double)mid ){
                    cnt++;
                }
            } else{
                cnt++;
            }
        
        }
        // cout << lo << ' ' <<mid << ' ' << hi<< '\n';
        if(cnt > n){
            lo = mid+1;
        } else{
            hi = mid;
        }
    }

    cout << lo << '\n';
    return 0;
}