#include <iostream>
using namespace std;

int main(){
    long long n, dp[91][2]; 
    cin >> n;

    dp[1][0] = 0;
    dp[1][1] = 1;

    for(int i = 2; i <= n; i++){
        dp[i][0] = dp[i-1][0]+dp[i-1][1];
        dp[i][1] = dp[i-1][0];
    }

    cout << dp[n][0]+dp[n][1] << '\n';
    return 0;
}