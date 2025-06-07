#include <iostream>
using namespace std;

int main(){
    long long t;
    cin >> t;
    for(long long idx = 0; idx < t; idx++){
        long long n, arr[10000] = {}, num, max = -90000000;
        cin >> n;
        arr[0] = 0;
        for(long long i = 0; i < n; i++){
            cin >> num;
            arr[i+1] = arr[i]+num;
        }
        for(long long i = 1; i <= n; i++){
            for(long long j = i; j <= n; j++){
                if(arr[j]-arr[i-1] > max) max = arr[j]-arr[i-1];
            }
        }
        cout << max << '\n';

    }
    return 0;
}