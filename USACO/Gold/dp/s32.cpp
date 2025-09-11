#include <iostream>
using namespace std;

int dp[100000][21][3];
int play[100000];
int main(){
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    char ch;
    for(int i = 0; i < n; i++){
        cin >> ch;
        switch(ch){
            case 'H':
                play[i] = 0;
                break;
            case 'P':
                play[i] = 1;
                break;
            case 'S':
                play[i] = 2;
                break;
        } 
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j <= k; j++){
            for(int m = 0; m < 3; m++){
                dp[i][j][m] = 0;
            }
        }
    }

    
    dp[0][0][play[0]] = 1;
    for(int i = 1; i < n; i++){
        for(int j = 0; j <= k; j++){
            if(j > i) break;
            for(int m = 0; m < 3; m++){
                if(j == 0){
                    dp[i][j][m] = dp[i-1][j][m];
                    if(m == play[i]) dp[i][j][m]++;
                } else{
                    dp[i][j][m] = max(max(max(dp[i-1][j-1][0], dp[i-1][j-1][1]), dp[i-1][j-1][2]), dp[i-1][j][m]);
                    if(m == play[i]) dp[i][j][m]++;
                }
            }
        }
    }
    
    int greatest = 0;
    for(int j = 0; j <= k; j++){
        if(j > n-1) break;
        for(int m = 0; m < 3; m++){
            if(greatest < dp[n-1][j][m]){
                greatest = dp[n-1][j][m];
            }
        }
    }

    cout << greatest << '\n';
    return 0;
}