#include <iostream>
using namespace std;

// i, j and k,j
int range[400][400], dp[401][400];

int main(){
    // freopen("snakes.in", "r", stdin);
    // freopen("snakes.out", "w", stdout);
    int n, k, arr[400];
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        dp[i][i] = 0;
    }

    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            int max = 0;
            for(int pos = i; pos <= j; pos++){
                if(arr[pos] > max){
                    max = arr[pos];
                }
            }
            int sum = 0;
            for(int pos = i; pos <= j; pos++){
                sum += max-arr[pos];
            }
            range[i][j] = sum;
        }
    }

    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < n; j++){
    //         cout << range[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    for(int kdx = 0; kdx <= k; kdx++){
        for(int j = 0; j < n; j++){
            dp[kdx][j] = -1;
        }
    }
    for(int j = 0; j < n; j++){
        dp[0][j] = range[0][j];
    }
    // how many changes?
    for(int kdx = 1; kdx <= k; kdx++){
        // to where
        for(int j = 0; j < n; j++){
            // taking what
            for(int i = 0; i < j; i++){
                // cout << kdx << ' ' << j << ' ' << i << ' ' <<  dp[kdx-1][i]+range[i][j] << '\n';
                if(dp[kdx][j] == -1 || dp[kdx][j] > dp[kdx-1][i]+range[i+1][j]){
                    dp[kdx][j] = dp[kdx-1][i]+range[i+1][j];
                }
            }
        }
    }
    
    int min = dp[0][n-1];
    for(int kdx = 1; kdx <= k; kdx++){
        if(min > dp[kdx][n-1]){
            min = dp[kdx][n-1];
            // cout << min << '\n';
        }
    }
    cout << min << '\n';

    return 0;
}