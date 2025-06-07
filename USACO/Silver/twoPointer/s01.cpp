// 수들의 합 2 2003
#include <iostream>
using namespace std;

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    long long m;
    int arr[10001], n;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int lo = 0, hi = -1, cnt = 0;
    long long sum = 0;
    while(true){
        if(sum < m){
            hi++;
            if(hi == n) break;
            sum+= arr[hi];
        } else{
            if(sum == m) cnt++;
            sum -= arr[lo];
            lo++;
        }
    }
    cout << cnt << '\n';
    return 0;
}