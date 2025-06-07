// SumX 3273
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n, arr[100000], x;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    cin >> x;
    sort(arr, arr+n);

    int lo = 0, hi = n-1, cnt = 0;
    while(lo < hi){
        if(arr[lo]+arr[hi] >= x){
            if(arr[lo]+arr[hi] == x) cnt++;
            hi--;
        } else{
            lo++;
        }
    }
    cout << cnt << '\n';
    return 0;
}