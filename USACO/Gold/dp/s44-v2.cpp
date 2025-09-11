#include <iostream>
using namespace std;

int dp[2001][2001];

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int left[2001] = {}, right[2001] = {};
    for(int i = 0; i < n; i++) cin >> left[i];
    for(int i = 0; i < n; i++) cin >> right[i];

    for(int i = 1; i <= n; i++){
        if(dp[0][i-1] != -1 && left[0] > right[i-1]){
            dp[0][i] = dp[0][i-1] + right[i-1];
        } else{
            dp[0][i] = -1;
        }
    }

    for(int x = 1; x <= n; x++){
        for(int y = 1; y <= n; y++){
            dp[x][y] = dp[x-1][y-1];
            if(dp[x][y] < dp[x-1][y]) dp[x][y] = dp[x-1][y];
            if(dp[x][y-1] != -1 && left[x] > right[y-1]){
                if(dp[x][y] < dp[x][y-1] + right[y-1]) dp[x][y] = dp[x][y-1] + right[y-1];
            }
        }
    }
    int max = 0;
    for(int i = 0; i <= n; i++){
        if(max < dp[n][i]) max = dp[n][i];
    }
    for(int i = 0; i <= n; i++){
        if(max < dp[i][n]) max = dp[i][n];
    }
    // for(int x = 0; x <= n; x++){
    //     for(int y = 0; y <= n; y++){
    //         cout << dp[x][y] << ' ';
    //     }
    //     cout << '\n';
    // }

    cout << max << '\n';
    return 0;
}