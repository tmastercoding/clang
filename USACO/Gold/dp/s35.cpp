#include <iostream>
using namespace std;

long long dp[100][100001];
long long sums[100][100001];
int main(){
    int n, k;
    int child[100];

    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> child[i];
    }

    for(int j = 0; j <= k; j++){
        if(child[0] >= j){
            dp[0][j] = 1;
        } else{
            dp[0][j] = 0;
        }
        if(j > 0){
            sums[0][j] = (sums[0][j-1]+dp[0][j]) % (1000000007);
        } else{
            sums[0][j] = dp[0][j] % (1000000007);
        }
    }

    // 1 1 0 0 0
    // 1 2 2 1 0
    // 1 3 5 6 5 
    for(int i = 1; i < n; i++){
        for(int j = 0; j <= k; j++){
            int start = j-child[i]-1;
            if(start < 0){
                dp[i][j] = sums[i-1][j] % (1000000007);
            } else{
                dp[i][j] = (sums[i-1][j]-sums[i-1][start]+1000000007) % (1000000007);
            }

            if(j > 0){
                sums[i][j] = (sums[i][j-1]+dp[i][j]) % (1000000007);
            } else{
                sums[i][j] = dp[i][j] % (1000000007);
            }
            
        }
    }

    cout << dp[n-1][k]% (1000000007) << '\n';

    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j <= k; j++){
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    return 0;
}