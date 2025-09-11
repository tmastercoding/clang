#include <iostream>
using namespace std;

long long dp[501][62626];
int main(){
    int sum = 0, n;
    cin >> n;

    for(int i = 1; i <= n; i++){
        sum += i;
    }

    if (sum&1){
        cout << 0 << '\n';
    } else{
        sum/=2;
        dp[1][1] = 1;
        for(int i = 2; i <= n; i++){
            for(int j = 0; j <= sum; j++){
                dp[i][j] = dp[i-1][j];
                if(j-i >= 0){
                    dp[i][j] += dp[i-1][j-i];
                }
                dp[i][j] %= (1000000007);
            }
        }
        // for(int i = 1; i <= n; i++){
        //     for(int j = 0; j <= sum; j++){
        //         cout << dp[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }
        cout << dp[n][sum] << '\n';
    }


    return 0;
}


// 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0
// 0 1 0 1 
// 0 1 0 1 1 0 1
// 0 1 0 1 1 2 1 1 1 0 1
// 0 1 0 1 1 2 2 1 2 1 3 1 1 1 0
// 0 1 0 1 1 2 2 2 2 2 4 3 3 2 2
// 0 1 0 1 1 2 2 2 3 2 5 4 5 5 4

