// Martian DNA 15862
#include <iostream>
using namespace std;

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int n, k, r;
    int arr[200000], cnts[200000] = {}, reqs[200000] = {};
    cin >> n >> k >> r;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int b, q;
    for(int i = 0; i < r; i++){
        cin >> b >> q;
        reqs[b] = q;
    }
    
    int lo = 0, hi = -1, cnt = 0, min = 200001, idx = 0;
    // init
    while(true){
        hi++;
        if(hi >= n) break;
        cnt++;
        cnts[arr[hi]]++;
        while(idx < k){
            if(reqs[idx] <= cnts[idx]){
                idx++;
            } else{
                break;
            }
        }
        if(idx == k){
            min = cnt;
            break;
        }
    }
    if(min != 200001){
        while(true){
            if(idx == k){
                if(cnt < min) min = cnt;
                cnts[arr[lo]]--;
                lo++;
                cnt--;
                idx = 0;
            }
            while(idx < k){
                if(reqs[idx] <= cnts[idx]){
                    idx++;
                } else{
                    break;
                }
            }
            if(idx == k){
                continue;
            } 
            hi++;
            if(hi >= n) break;
            cnt++;
            cnts[arr[hi]]++;
        }
        cout << min << '\n';
    } else{
        cout << "impossible\n";
    }
    
    return 0;
}