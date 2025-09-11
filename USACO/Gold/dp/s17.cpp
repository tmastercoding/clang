#include <iostream>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    int h[100000];
    long long dp[100000];
    for(int i = 0; i < n; i++){
        cin >> h[i];
        dp[i] = 100000000000;
    }

    dp[0] = 0;
    for(int i = 1; i < n; i++){
        int start = 0;
        if(i-k > 0) start = i-k;
        for(int j = start; j < i; j++){
            if(dp[i] > abs(h[i]-h[j])+dp[j]){
                dp[i] = abs(h[i]-h[j])+dp[j];
            }
        }
    }
    cout << dp[n-1] << '\n';
    return 0;
}