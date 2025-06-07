#include <iostream>
using namespace std;

int main(){
    int n, tri[500][500];
    long long dp[500][500];
    cin >> n;
    for(int y = 0; y < n; y++){
        for(int x = 0; x <= y; x++){
            cin >> tri[x][y];
            dp[x][y] = 0;
        }
    }

    dp[0][0] = tri[0][0];
    for(int y = 1; y < n; y++){
        for(int x = 0; x <= y; x++){
            if(x < y){
                if(dp[x][y] < dp[x][y-1]+tri[x][y]){
                    dp[x][y] = dp[x][y-1]+tri[x][y];
                }
            }
            if(x > 0){
                if(dp[x][y] < dp[x-1][y-1]+tri[x][y]){
                    dp[x][y] = dp[x-1][y-1]+tri[x][y];
                }
            }
        }
    }

    // for(int y = 0; y < n; y++){
    //     for(int x = 0; x <= y; x++){
    //         cout << dp[x][y] << ' ';
    //     }
    //     cout << '\n';
    // }

    int max = 0;
    for(int x = 0; x < n; x++){
       if(dp[x][n-1] > max) max = dp[x][n-1]; 
    }  
    cout << max << '\n';
    return 0;
}