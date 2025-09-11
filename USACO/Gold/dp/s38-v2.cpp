#include <iostream>
#include <string>
using namespace std;

int dp[5001][5001];

int main(){
    string n, m;
    cin >> n >> m;
    
    for(int i = 1; i <= n.size(); i++){
        dp[i][0] = i;
    }
    for(int i = 1; i <= m.size(); i++){
        dp[0][i] = i;
    }

    for(int i = 1; i <= n.size(); i++){
        for(int j = 1;  j <= m.size(); j++){
            dp[i][j] = dp[i-1][j]+1;
            if(dp[i][j] > dp[i][j-1]+1) dp[i][j] = dp[i][j-1]+1;
            if(dp[i-1][j-1]+1 < dp[i][j]) dp[i][j] = dp[i-1][j-1]+1;
            if(n[i-1] == m[j-1] && dp[i-1][j-1] < dp[i][j]) dp[i][j] = dp[i-1][j-1];
        }
    }

    // for(int i = 1; i <= n.size(); i++){
    //     for(int j = 1; j <= m.size(); j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << '\n';
    // }

    cout << dp[n.size()][m.size()] << '\n';
    return 0;
}