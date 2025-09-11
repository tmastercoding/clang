#include <iostream>
using namespace std;

int dp[100][100][100];

int main(){
    // freopen("taming.in", "r", stdin);
    // freopen("taming.out", "w", stdout);
    int n;
    int arr[100];
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];

    for(int j = 0; j < n; j++){
        if(j != 0){
            for(int k = 0; k < n; k++){
                dp[0][j][k] = -1;
            }
            continue;
        }
        for(int k = 0; k < n; k++){
            dp[0][j][k] = n;
            if(k > 0){
                dp[0][j][k] = dp[0][j][k-1];
            }
            if(k == arr[k]){
                dp[0][j][k]--;
            }
            // cout << dp[0][j][k] << '\n';
        }
    }

    for(int i = 1; i < n; i++){
        for(int j = 0; j < n; j++){
            if(j < i){
                for(int k = 0; k < n; k++){
                    dp[i][j][k] = -1;
                }
                continue;
            }
            int min = 1000;
            for(int k = 0; k < j; k++){
                if(dp[i-1][k][j-1] == -1) continue;
                if(dp[i-1][k][j-1] < min) min = dp[i-1][k][j-1];
            }

            int cur = 0;
            for(int k = j; k < n; k++){
                if(cur++ == arr[k]) min--;
                dp[i][j][k] = min;
            }
        }
    }

    for(int i = 0; i < n; i++){
        int min = 1000;
        for(int j = 0; j < n; j++){
            if(dp[i][j][n-1] == -1) continue;
            if(min > dp[i][j][n-1]) min = dp[i][j][n-1];
        }
        cout << min << '\n';
    }
    return 0;
}