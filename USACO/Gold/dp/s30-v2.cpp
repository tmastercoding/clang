#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    long long dp[1000001][2];
    for(int i = 0; i <= n; i++){
        dp[i][0] = 0;
        dp[i][1] = 0;
    }

    dp[n][0] = 1;
    for(int i = n; i > 0; i--){
        dp[i][0] %= 1000000007;
        dp[i][1] %= 1000000007;
        if(i > 1){
            dp[i-2][0] += dp[i][0];
            dp[i-1][1] += dp[i][0];
        }
        dp[i-1][0] += dp[i][0];
        dp[i][1] += dp[i][0];
        dp[i-1][1] += dp[i][1];
        dp[i-1][0] += dp[i][1];
        dp[i][0] %= 1000000007;
        dp[i][1] %= 1000000007;
        // cout << dp[i][0] << ' ' << dp[i][1] << '\n';
    }

    cout << dp[0][0]%1000000007 << '\n';
    return 0;
}