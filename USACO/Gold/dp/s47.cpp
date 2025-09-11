#include <iostream>
using namespace std;

long long dp[201][201];
int main(){
    int n, k;
    cin >> n >> k;
   
    for(int i = 0; i <= n; i++){
        dp[0][i] = 1;
    }

    for(int i = 1; i < k; i++){
        dp[i][0] = 1;
        for(int j = 1; j <= n; j++){
            dp[i][j] = (dp[i][j-1]+dp[i-1][j]) % 1000000000;
        }
    }

    cout << dp[k-1][n] % 1000000000 << '\n';
    return 0;
}