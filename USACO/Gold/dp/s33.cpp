#include <iostream>
using namespace std;

long long dp[100][100001];
int main(){
    int n, w;
    cin >> n >> w;
    
    long long items[100][2];
    for(int i = 0; i < n; i++){
        cin >> items[i][0] >> items[i][1];
    }

    for(int j = 0; j <= w; j++){
        dp[0][j] = 0;
        if(j >= items[0][0]) dp[0][j] = items[0][1];
    }
    for(int i = 1; i < n; i++){
        for(int j = 0; j <= w; j++){
            dp[i][j] = dp[i-1][j];
            if(j >= items[i][0]){
                if(dp[i-1][j-items[i][0]]+items[i][1] > dp[i][j]){
                    dp[i][j] = dp[i-1][j-items[i][0]]+items[i][1];
                }
            }
            // cout << dp[i][j] << ' ';
        }
        // cout << '\n';
    }

    long long max = 0;
    for(int j = 0; j <= w; j++){
        if(max < dp[n-1][j]) max = dp[n-1][j];
    }

    cout << max << '\n';
    return 0;
}