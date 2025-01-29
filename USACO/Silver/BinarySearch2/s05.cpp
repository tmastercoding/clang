#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    long long l, pos[10001];
    int k, c;
    cin >> l >> k >> c;

    for(int idx = 0; idx < k; idx++){
        cin >> pos[idx];
    }
    sort(pos, pos+k);
    pos[k] = l;

    long long lo = 1, mid, hi = l, cnt, prev, start;
    while(lo < hi){
        mid = (lo+hi)/2;
        cnt = 0, prev =0, start = -1;
        // cout << "start: ";
        for(int idx = 0; idx < k; idx++){

            if(pos[idx]-prev <= mid && pos[idx+1]-prev > mid){
                if(start == -1){
                    start = pos[idx];
                }
                // cout << pos[idx] << ' ';
                if(pos[idx+1] - pos[idx] > mid){
                    // cout << "BREAK";
                    cnt = 20000;
                    break;
                }
                cnt++;
                prev = pos[idx];
                // idx--;
            }
        }
        // cout << l-prev;
        if(l-prev > mid){
            cnt = 20000;
        }
        // cout << '\n';

        // cout << mid << ' ' << cnt << '\n'i;
        // cout << cnt << ' ' << lo << ' ' << mid << ' ' << hi << '\n';
        if(cnt <= c){
            hi = mid;
        } else{
            lo = mid+1;
        }
    }

    prev = l;
    start = 0;
    cnt = 0;
    for(int idx = k-1; idx > 0; idx--){
        if(prev-pos[idx] <= lo && prev-pos[idx-1] > lo){
            start = pos[idx];
            cnt++;
            // cout << start << '\n';
            // cout << pos[idx] << ' ';
            // if(pos[idx] - pos[idx-1] > lo){
            //     // cout << "BREAK";
            //     cnt = 20000;
            //     break;
            // }
            // cnt++;
            prev = pos[idx];
            // idx--;
        }
    }
    if((prev-pos[0] <= lo && prev > lo )|| cnt < c){
        start = pos[0];
    }
    cout << lo << ' ' << start << '\n';

    
    return 0;
}
