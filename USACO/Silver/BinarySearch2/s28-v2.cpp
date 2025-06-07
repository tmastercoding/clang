// 로봇 프로젝트 3649
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;
    long long x, arr[1000000];
    pair<long long, pair<long long, long long>> out[1000000];
    int odx = 0;
    cin >> x;
    x*= 10000000;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];

    sort(arr, arr+n);
    
    for(int i = 0; i < n; i++){
        int idx = lower_bound(arr, arr+n, x-arr[i])-arr;
        // cout << arr[i] << ' ' << idx << '\n';
        if(idx < n && idx != i && arr[idx]+arr[i] == x){
            if(arr[idx] < arr[i]){
                out[odx++] = {arr[i]-arr[idx], {arr[idx], arr[i]}};
            } else{
                out[odx++] = {arr[idx]-arr[i], {arr[i], arr[idx]}};
            }
            break;
        }
    }
    sort(out, out+odx);
    if(out){
        cout << "yes " << out[odx-1].second.first << ' ' << out[odx-1].second.second << '\n';
    } else{
        cout << "danger\n";
    }
    return 0;
}