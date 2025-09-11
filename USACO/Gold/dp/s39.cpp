#include <iostream>
using namespace std;

int dp[1005][1005];
int main(){
    int n, w;
    int cases[1005][2];
    cin >> n >> w;
    
    cases[0][0] = 1;
    cases[0][1] = 1;

    for(int i = 1; i <= w; i++){
        cin >> cases[i][0] >> cases[i][1];
    }

    for(int i = 1; i <= w; i++){
        dp[i][0] = abs(cases[i][0]-cases[i-1][0]) + abs(cases[i][1]-cases[i-1][1]) +dp[i-1][0];
        // cout << dp[i][0] << '\n';
    }
    
    cases[0][0] = n;
    cases[0][1] = n;
    for(int i = 1; i <= w; i++){
        dp[0][i] = abs(cases[i][0]-cases[i-1][0]) + abs(cases[i][1]-cases[i-1][1]) +dp[0][i-1];
        // cout << dp[0][i] << '\n';
    }

    for(int i = 1; i <= w; i++){
        for(int j = 1; j <= w; j++){
            if(i-1 == j){
                dp[i][j] = 1000000000;
                for(int k = 0; k < i; k++){
                    if(dp[k][j] == -1) continue;
                    int tx = cases[k][0], ty = cases[k][1];
                    if(k == 0) tx = 1, ty= 1;

                    int temp = dp[k][j]+abs(tx-cases[i][0]) + abs(ty-cases[i][1]);
                    if(temp < dp[i][j]) dp[i][j] = temp;
                }
            } else if(i == j-1){
                dp[i][j] = 1000000000;
                // cout<<"HERE\n";
                for(int k = 0; k < j; k++){
                    // cout << "AYE\n";
                    if(dp[i][k] == -1) continue;
                    int temp = dp[i][k]+abs(cases[k][0]-cases[j][0]) + abs(cases[k][1]-cases[j][1]);
                    // cout << temp << '\n';
                    if(temp < dp[i][j]) dp[i][j] = temp;
                }
            } else if(i > j){
                int tx = cases[i-1][0], ty = cases[i-1][1];
                if(i-1 == 0) tx = 1, ty= 1;
                dp[i][j] = dp[i-1][j]+abs(cases[i][0]-tx) + abs(cases[i][1]-ty);
            } else if(i < j){
                dp[i][j] = dp[i][j-1]+abs(cases[j][0]-cases[j-1][0]) + abs(cases[j][1]-cases[j-1][1]);
            } else{
                dp[i][j] = -1;
            }
        }
    }

    // for(int i = 0; i <= w; i++){
    //     for(int j = 0; j <= w; j++){
    //         cout << dp[i][j] << ' ';
    //     }    
    //     cout << '\n';
    // }

    int min = 1000000000, minx, miny;
    for(int i = 1; i <= w; i++){
        if(dp[i][w] > -1){
            if(dp[i][w] < min){
                min = dp[i][w];
                minx = i, miny = w;
            }
        }
    }

    for(int i = 1; i <= w; i++){
        if(dp[w][i] > -1){
            if(dp[w][i] < min){
                min = dp[w][i];
                minx = w, miny = i;
            }
        }
    }

    int x = minx, y = miny;
    int output[1000], idx = 0;

    while((x > -1 && y > -1) && !(x == 0 && y == 0)){
        // cout << x << ' ' << y << '\n';
        if(x-1 == y){
            int mink;
            output[idx++] = 1;
            for(int k = 0; k < x; k++){
                if(dp[k][y] == -1) continue;
                int tx = cases[k][0], ty = cases[k][1];
                if(k == 0) tx = 1, ty= 1;
                int temp = dp[k][y]+abs(tx-cases[x][0]) + abs(ty-cases[x][1]);
                // cout << temp << '\n';
                if(temp == dp[x][y]){
                    mink = k;
                    break;
                } 
            }
            x = mink;
        } else if(x == y-1){
            int mink;
            output[idx++] = 2;
            // cout<<"HERE\n";
            for(int k = 0; k < y; k++){
                // cout << "AYE\n";
                if(dp[x][k] == -1) continue;
                int temp = dp[x][k]+abs(cases[k][0]-cases[y][0]) + abs(cases[k][1]-cases[y][1]);
                // cout << temp << '\n';
                if(temp == dp[x][y]){
                    mink = k;
                } 
            }
            y = mink;
        } else if(x > y){
            output[idx++] = 1;
            x--;
        } else if(x < y){
            output[idx++] = 2;
            y--;
        } 
    }

    cout << min << '\n';
    for(int i = idx-1; i > -1; i--){
        cout << output[i] << '\n';
    }
    return 0;
}