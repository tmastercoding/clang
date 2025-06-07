// K보다 큰 구간 14246
#include <iostream>
using namespace std;

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n, arr[100000] = {};
    long long k, sum = 0, cnt = 0;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    cin >> k;

    int lo = 0, hi = -1;
    while(true){
        hi++;
        if(hi >= n) break;
        sum += arr[hi];
        if(sum > k){
            while(sum > k){
                cnt += n-hi;
                sum -= arr[lo];
                lo++;
            }
        }
    }
    cout << cnt << '\n';
    return 0;
}