#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int dp[31][2];
    for(int i = 0; i <= n; i++){
        dp[i][0] = 0, dp[i][1] = 0;
    }
    dp[n][0] = 1;

    for(int i = n; i > 0; i--){
        dp[i-1][1] += dp[i][0]*2;
        dp[i-1][0] += dp[i][1];
        if(i > 1){
            dp[i-2][0] += dp[i][0];
            dp[i-2][1] += dp[i][1];
        } 
    }


    cout << dp[0][0] << '\n';
    return 0;
}