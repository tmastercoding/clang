#include <iostream>
#include <string>
using namespace std;

int main(){
    int n;
    char grid[1000][1000];
    long long dp[1000][1000];
    cin >> n;
    for(int y = 0; y < n; y++){
        string buffer;
        cin >> buffer;
        for(int x = 0; x < n; x++){
            dp[x][y] = 0;
            grid[x][y] = buffer[x];
        }
    }
    if(grid[0][0] == '.') dp[0][0] = 1;
    for(int x = 0; x < n; x++){
        for(int y = 0; y < n; y++){
            if(grid[x][y] == '.'){
                if(x-1 > -1){
                    dp[x][y] += dp[x-1][y];
                }
                if(y-1 > -1){
                    dp[x][y] += dp[x][y-1];
                }
            }
            dp[x][y] %= (long long)(1e9+7);
        }
    }
    cout << dp[n-1][n-1]%(long long)(1e9+7) << '\n';
    return 0;
}