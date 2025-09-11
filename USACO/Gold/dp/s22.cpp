#include <iostream>
using namespace std;

long dp[100000][101];
int num[100000];
int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> num[i];
    }

    for(int i = 0; i < n; i++){
        for(int j = 1; j <= m; j++){
            dp[i][j] = 0;
        }
    }

    if(num[0] == 0){
        for(int i = 1; i <= m; i++){
            dp[0][i] = 1;
        }
    } else{
        dp[0][num[0]] = 1;
    }

    for(int i = 1; i < n; i++){
        if(num[i] == 0){
            for(int j = 1; j <= m; j++){
                dp[i][j] += dp[i-1][j];
                if(j > 1) dp[i][j] += dp[i-1][j-1];
                if(j < m) dp[i][j] += dp[i-1][j+1];
                dp[i][j] %= 1000000007;
            }
        } else{
            dp[i][num[i]] += dp[i-1][num[i]];
            if(num[i] > 1) dp[i][num[i]] += dp[i-1][num[i]-1];
            if(num[i] < m) dp[i][num[i]] += dp[i-1][num[i]+1];
            dp[i][num[i]] %= 1000000007;
        }
    }

    // for(int i = 0; i < n; i++){
    //     for(int j = 1; j <= m; j++){
    //         cout << dp[i][j] << " ";
    //         if(dp[i][j]/10 < 1) cout << " ";
    //         if(dp[i][j]/100 < 1) cout << " ";
    //     }
    //     cout << '\n';
    // }
    long long sum = 0;
    for(int i = 1; i <= m; i++){
        sum += dp[n-1][i];
    }
    sum %= 1000000007;
    cout << sum << '\n';
    return 0;
}