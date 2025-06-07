// 겹치는 건 싫어 20922
#include <iostream>
using namespace std;

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n, k;
    int arr[200001], cnts[100001] = {};
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int lo = 0, hi = -1, cnt = 0, max = 0;
    while(true){
        hi++;
        if(hi >= n) break;
        cnts[arr[hi]]++;
        cnt++;
        if(cnts[arr[hi]] > k){
            while(true){
                cnts[arr[lo]]--;
                lo++;
                cnt--;
                if(cnts[arr[hi]] == k) break;
            }
        }
        if(cnt > max) max = cnt;
    }
    cout << max << '\n';
    return 0;
}