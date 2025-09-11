#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int n;
    cin >> n;
    if(n & 1){
        cout << "0\n";
    } else if(n == 0){
        cout << "1\n";
    } else{
        int dp[15][9];
        n /= 2;
        for(int i = 0; i < n; i++){
            if(i == 0){
                dp[i][0] = 1;
                dp[i][1] = 1;
                dp[i][2] = 1;
                dp[i][4] = 0;
                dp[i][6] = 0;
                dp[i][7] = 0;
                dp[i][8] = 0;
                if(n > 1){
                    dp[i][3] = 1;
                    dp[i][5] = 1;
                }
            } else{
                dp[i][0] = dp[i-1][0]+dp[i-1][1]+dp[i-1][2]+dp[i-1][4]+dp[i-1][6];
                dp[i][1] = dp[i-1][0]+dp[i-1][1]+dp[i-1][2]+dp[i-1][4]+dp[i-1][6];
                dp[i][2] = dp[i-1][0]+dp[i-1][1]+dp[i-1][2]+dp[i-1][4]+dp[i-1][6];
                if(i < n-1){
                    dp[i][3] = dp[i-1][0]+dp[i-1][1]+dp[i-1][2]+dp[i-1][4]+dp[i-1][6];
                    dp[i][5] = dp[i-1][0]+dp[i-1][1]+dp[i-1][2]+dp[i-1][4]+dp[i-1][6];
                    dp[i][7] = dp[i-1][3];
                    dp[i][8] = dp[i-1][5];

                } else{
                    dp[i][3] = 0;
                    dp[i][5] = 0;
                    dp[i][7] = 0;
                    dp[i][8] = 0;
                }
                dp[i][4] = dp[i-1][3]+dp[i-1][7];
                dp[i][6] = dp[i-1][5]+dp[i-1][8];
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < 7; j++){
                cout << dp[i][j] << ' ';
            }
            cout << '\n';
        }
        cout << dp[n-1][0]+dp[n-1][1]+dp[n-1][2]+dp[n-1][3]+dp[n-1][4]+dp[n-1][5]+dp[n-1][6] << '\n';
    }

    return 0;
}