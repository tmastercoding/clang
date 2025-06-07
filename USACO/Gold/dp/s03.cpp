#include <iostream>
using namespace std;

int main(){
    int n, x;
    long long dp[1000001] = {};
    long long coins[100];
    dp[0] = 1;
    cin >> n >> x;
    for(int i = 0; i < n; i++){
        cin >> coins[i];
    }

    for(int i = 1; i <= x; i++){
        for(int j = 0; j < n; j++){
            if(i-coins[j] > -1){
                dp[i] += dp[i-coins[j]];
            }
        }
        dp[i] %= 1000000007;
    }
    // for(int i = 1; i <= x; i++){
    //     cout << dp[i] << ' ';
    // }
    // cout << '\n';
    cout << dp[x] % (long long)(1e9+7) << '\n';
    return 0;
}