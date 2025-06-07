#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    int l, arr[100000], mins[100000] = {}, maxs[100000] = {};
    cin >> n;
    long long cnt = 0;
    int adx = 0;
    for(int i = 0; i < n; i++){
        cin >> l;
        int min = 1000000, max = 0;
        bool ascent = false;
        for(int j = 0; j < l; j++){
            cin >> arr[j];
            // cout << min << ' ' << arr[j] << '\n';
            if(min < arr[j]){
                ascent = true;
            }
            if(min > arr[j]){
                min = arr[j];
            }
            if(max < arr[j]){
                max = arr[j];
            }
        }
        // cout << ascent << '\n';
        if(ascent){
            cnt += n;
        } else{
            mins[adx] = min;
            maxs[adx] = max;
            adx++;
        }
    }
    int idx;
    sort(maxs, maxs+adx);
    // cout << cnt << '\n';
    for(int i = 0; i < adx; i++){
        idx = upper_bound(maxs, maxs+adx, mins[i])-maxs;
        // cout << mins[i] << ' ' << idx << '\n';
        cnt += n-idx;
    }
    cout << cnt << '\n';
    return 0;
}