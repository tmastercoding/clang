#include <iostream>
using namespace std;

//  range size, starting point {row, col, cost}
int dp[501][500][3];

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> dp[1][i][0] >> dp[1][i][1];
    }

    for(int i = 0; i <= n-2; i++){
        dp[2][i][0] = dp[1][i][0];
        dp[2][i][1] = dp[1][i+1][1];
        dp[2][i][2] = dp[1][i][0] * dp[1][i][1]*dp[1][i+1][1];
        // cout <<  dp[2][i][0] << ' ' << dp[2][i][1] << ' ' << dp[2][i][2] << '\n';
    }

    for(int i = 3; i <= n; i++){
        for(int j = 0; j <= n-i; j++){
            for(int k = 1; k < i; k++){
                int temp = dp[k][j][0]*dp[k][j][1]*dp[i-k][j+k][1]+dp[k][j][2]+dp[i-k][j+k][2];
                if(!dp[i][j][2] || temp < dp[i][j][2]){
                    dp[i][j][0] = dp[k][j][0];
                    dp[i][j][1] = dp[i-k][j+k][1];
                    dp[i][j][2] = temp;
                }
            }
        }
    }

    cout << dp[n][0][2] << '\n';
    return 0;
}