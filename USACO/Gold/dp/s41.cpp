#include <iostream>
#include <cmath>
using namespace std;

long long dp[1001][1001];

int main(){

    freopen("radio.in", "r", stdin);
    freopen("radio.out", "w", stdout);
    int n, m;
    cin >> n >> m;

    int fs[1001][2], bs[1001][2];
    cin >> fs[0][0] >> fs[0][1];
    cin >> bs[0][0] >> bs[0][1];

    string fdir, bdir;
    cin >> fdir >> bdir;
    for(int i = 0; i < n; i++){
        switch(fdir[i]){
            case 'N':
                fs[i+1][0] = fs[i][0];
                fs[i+1][1] = fs[i][1]+1;
                break;
            case 'S':
                fs[i+1][0] = fs[i][0];
                fs[i+1][1] = fs[i][1]-1;
                break;
            case 'W':
                fs[i+1][0] = fs[i][0]-1;
                fs[i+1][1] = fs[i][1];
                break;
            case 'E':
                fs[i+1][0] = fs[i][0]+1;
                fs[i+1][1] = fs[i][1];
                break;
        }
    }

    for(int i = 0; i < m; i++){
        switch(bdir[i]){
            case 'N':
                bs[i+1][0] = bs[i][0];
                bs[i+1][1] = bs[i][1]+1;
                break;
            case 'S':
                bs[i+1][0] = bs[i][0];
                bs[i+1][1] = bs[i][1]-1;
                break;
            case 'W':
                bs[i+1][0] = bs[i][0]-1;
                bs[i+1][1] = bs[i][1];
                break;
            case 'E':
                bs[i+1][0] = bs[i][0]+1;
                bs[i+1][1] = bs[i][1];
                break;
        }
    }

    // for(int i = 0; i <= n; i++) cout << fs[i][0] << ' ' << fs[i][1] << '\n';
    // cout << "++++++++\n";
    // for(int i = 0; i <= m; i++) cout << bs[i][0] << ' ' << bs[i][1] << '\n';
    
    for(int i = 1; i <= n; i++){
        dp[0][i] = dp[0][i-1] + pow(fs[i][0]-bs[0][0],2)+ pow(fs[i][1]-bs[0][1],2);
    }
    
    for(int i = 1; i <= m; i++){
        dp[i][0] = dp[i-1][0] + pow(bs[i][0]-fs[0][0],2)+ pow(bs[i][1]-fs[0][1],2);
    }
    // for(int i = 0; i <= n; i++) cout << dp[0][i] << '\n';
    // cout << "++++++++\n";
    // for(int i = 0; i <= m; i++) cout << dp[i][0] << '\n';

    for(int x = 1; x <= m; x++){
        for(int y = 1; y <= n; y++){
            long long add;
            add = pow(bs[x][0]-fs[y][0],2)+ pow(bs[x][1]-fs[y][1],2);
            if(dp[x-1][y] < dp[x][y-1]){
                dp[x][y] = dp[x-1][y] + add;
            } else{
                dp[x][y] = dp[x][y-1] + add;
            }

            if(dp[x][y] > dp[x-1][y-1]+add) dp[x][y] = dp[x-1][y-1]+add;
        }
    }

    // for(int x = 0; x <= m; x++){
    //     for(int y = 0; y <= n; y++){
    //         cout << dp[x][y] << ' ';
    //     }
    //     cout << '\n';
    // }
    cout << dp[m][n] << '\n';
    return 0;
}