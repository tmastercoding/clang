#include <iostream>
using namespace std;

int dp[300][300]; // range, start = value  

int main(){
    // freopen("248.in", "r", stdin);
    // freopen("248.out", "w", stdout);
    int n;
    cin >> n;
    int max = 1;

    for(int i = 0; i < n; i++){
        cin >> dp[1][i];
        if(max < dp[1][i]) max = dp[1][i];
    }

    for(int i = 0; i < n-1; i++){
        if(dp[1][i] == dp[1][i+1]){
            dp[2][i] = dp[1][i]+1;
            if(max < dp[2][i]) max = dp[2][i];
        }
    }

    for(int i = 3; i <= n; i++){
        for(int j = 0; j <= n-i; j++){
            for(int k = 1; k < i; k++){
                if(dp[k][j] == dp[i-k][j+k] && dp[k][j]!=0){
                    if(!dp[i][j] || dp[k][j]+1 > dp[i][j]){
                        dp[i][j] = dp[k][j]+1;
                        if(max < dp[i][j]) max = dp[i][j];
                    }
                }
            }
        }
    }
    cout << max << '\n';
    return 0;
}