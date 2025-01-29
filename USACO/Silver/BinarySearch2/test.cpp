// 휴게소 세우기 1477
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n, m, l, rests[50];
    cin >> n >> m >> l;
    for(int i = 0; i < n; i++){
        cin >> rests[i];
    }
    sort(rests, rests+n);

    int lo = 0, hi = 1000, mid =70, start, cnt, temp, idx;
    start = 0, cnt = 0, idx = 1;
    bool skipped = false;
    temp = rests[0];
    while(true){
        temp += mid;
        if(temp > l){
            break;
        }
        cnt++;
        skipped = false;
        while(idx < n){
            if(temp >= rests[idx]){                
                skipped = true;
                idx++;
            } else{
                if(skipped){
                    temp = rests[idx];
                }
                cout << temp << ' ';
                break;
            }
        }
        // if(skipped) cnt--;
    }
    cout << '\n';
    cout << cnt << '\n';
    temp = rests[0];
    while(true){
        temp -= mid;
        if(temp < 1) break;
        cnt++;
    }
    cout << mid << ' ' << cnt << ' '<< lo << ' ' << hi <<'\n';

    
    return 0;
}