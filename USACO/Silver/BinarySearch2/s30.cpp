// Cow Dance Show 14452
#include <iostream>
using namespace std;

int arr[20000] = {}, cur[10000];
int main(){
    int n, tmax;
    cin >> n >> tmax;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int lo = 1, hi = n, mid;
    while(lo < hi){
        mid = (lo+hi)/2;
        long long t = 0;
        int min = 100000, i = 0;
        for(; i < mid; i++){
            cur[i] = arr[i];
            if(min > arr[i]) min = arr[i];
        }
        // cout << min << '\n';
        while(true){
            // cout << min << ":\n";
            t += min;
            int newMin = 100000;
            for(int j = 0; j < mid; j++){
                cur[j] -= min;
                if(cur[j] <= 0 && i < n) cur[j] += arr[i++];
                if(cur[j] < newMin && cur[j] > 0) newMin = cur[j];
            }
            min = newMin;
            bool flag = true;
            for(int j=  0; j < mid; j++){
                // cout << cur[j] << ' ';
                if(cur[j] > 0) flag = false;
            }
            // cout << '\n';
            if(flag) break;
        }
        // cout << '\n';
        // cout << mid << ' ' << t << '\n';
        if(t > tmax){
            lo = mid+1;
        } else{
            hi = mid;
        }
    }
    cout << lo << '\n';
    
    return 0;
}