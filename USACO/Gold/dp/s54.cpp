#include <iostream>
using namespace std;

int dp[501][500][2];

int main(){
    int t;
    cin >> t;
    for(int idx = 0; idx < t; idx++){

        int n;
        int arr[500];
        cin >> n;
        for(int i = 1; i <= n; i++){
            for(int j = 0; j <= n-i; j++){
                dp[i][j][0] = 0, dp[i][j][1] = 0;
            }
        }
        for(int i = 0; i < n; i++){
            cin >> arr[i];
            dp[1][i][0] = arr[i];
        }    
        
        for(int j = 0; j <= n-2; j++){
            // sum
            dp[2][j][0] = arr[j]+arr[j+1];
            // total cost
            dp[2][j][1] = arr[j]+arr[j+1];
        }
    
        for(int i = 3; i <= n; i++){
            for(int j = 0; j <= n-i; j++){
                for(int k = 1; k < i ; k++){
                    int a = dp[k][j][0]+ dp[k][j][1]+dp[i-k][j+k][0]+dp[i-k][j+k][1];
                    // cout << i << ' ' << j << ' ' << k << ": " << a << '\n';
                    if(!a) continue;
                    if(a < dp[i][j][1] || !dp[i][j][1]){
                        // cout << "asdf\n";
                        dp[i][j][0] = dp[k][j][0]+dp[i-k][j+k][0];
                        dp[i][j][1] = a;
                    } 
                }
            }
        }
    
        // for(int i = 2; i <= n; i++){
        //     for(int j = 0; j <= n-i; j++){
        //         cout << dp[i][j][0] << ',' << dp[i][j][1] << ' ';
        //     }
        //     cout << '\n';
        // }
        cout << dp[n][0][1] << '\n';
    }
    
    return 0;
}