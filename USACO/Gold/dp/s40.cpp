#include <iostream>
#include <cmath>
using namespace std;

long long dp[1001][1001][2];

int main(){
    freopen("checklist.in", "r", stdin);
    freopen("checklist.out", "w", stdout);
    int h, g;
    int hcoords[1001][2], gcoords[1001][2];
    cin >> h >> g;

    for(int i = 1; i <= h; i++){
        cin >> hcoords[i][0] >> hcoords[i][1];
    }
    for(int i = 1; i <= g; i++){
        cin >> gcoords[i][0] >> gcoords[i][1];
    }

    // first col, row init
    dp[1][0][0] = 0;
    dp[1][0][1] = -1;
    dp[1][1][0] = -1;
    dp[1][1][1] = dp[1][0][0]+pow(gcoords[1][0]-hcoords[1][0], 2)+pow(gcoords[1][1]-hcoords[1][1], 2);
    for(int i = 2; i <= g; i++){
        dp[1][i][0] = -1;
        dp[1][i][1] = dp[1][i-1][1]+pow(gcoords[i][0]-gcoords[i-1][0], 2)+pow(gcoords[i][1]-gcoords[i-1][1], 2);
    }

    // for(int i = 0; i <= g; i++){
    //     cout << dp[1][i][0] << ' ' << dp[1][i][1] << '\n';
    // }

    for(int i = 2; i < h; i++){
        dp[i][0][0] = dp[i-1][0][0]+pow(hcoords[i][0]-hcoords[i-1][0], 2)+pow(hcoords[i][1]-hcoords[i-1][1], 2);
        dp[i][0][1] = -1;
    }
    // for(int i = 1; i < h; i++){
    //     cout << dp[i][0][0] << ' ' << dp[i][0][1] << '\n';
    // }

    for(int x = 2; x < h; x++){
        for(int y = 1; y <= g; y++){
            // transfer from top to bottom
            if(dp[x-1][y][0]!= -1 && dp[x-1][y][1] != -1){
                long long a, b;
                a = dp[x-1][y][0]+pow(hcoords[x][0]-hcoords[x-1][0], 2)+pow(hcoords[x][1]-hcoords[x-1][1], 2);
                b = dp[x-1][y][1]+pow(hcoords[x][0]-gcoords[y][0], 2)+pow(hcoords[x][1]-gcoords[y][1], 2);
                if(a < b){
                    dp[x][y][0] = a; 
                } else{
                    dp[x][y][0] = b;
                }
            } else if(dp[x-1][y][0] != -1){
                dp[x][y][0] = dp[x-1][y][0]+pow(hcoords[x][0]-hcoords[x-1][0], 2)+pow(hcoords[x][1]-hcoords[x-1][1], 2);
            } else{
                dp[x][y][0] = dp[x-1][y][1]+pow(hcoords[x][0]-gcoords[y][0], 2)+pow(hcoords[x][1]-gcoords[y][1], 2);
            }

            // transfer from left to right
            if(dp[x][y-1][0]!= -1 && dp[x][y-1][1] != -1){
                long long a, b;
                a = dp[x][y-1][0]+pow(gcoords[y][0]-hcoords[x][0], 2)+pow(gcoords[y][1]-hcoords[x][1], 2);
                b = dp[x][y-1][1]+pow(gcoords[y][0]-gcoords[y-1][0], 2)+pow(gcoords[y][1]-gcoords[y-1][1], 2);
                if(a < b){
                    dp[x][y][1] = a; 
                } else{
                    dp[x][y][1] = b;
                }
            } else if(dp[x][y-1][0] != -1){
                dp[x][y][1] = dp[x][y-1][0]+pow(gcoords[y][0]-hcoords[x][0], 2)+pow(gcoords[y][1]-hcoords[x][1], 2);
            } else{
                dp[x][y][1] = dp[x][y-1][1]+pow(gcoords[y][0]-gcoords[y-1][0], 2)+pow(gcoords[y][1]-gcoords[y-1][1], 2);
            }
        }
    }

    // for(int x = 1; x < h; x++){
    //     for(int y = 0; y <= g; y++){
    //         cout << '(' << dp[x][y][0] << ',' << dp[x][y][1] << ") ";
    //     }
    //     cout << '\n';
    // }

    int x = h, y = g;
    if(dp[x-1][y][0]!= -1 && dp[x-1][y][1] != -1){
        long long a, b;
        a = dp[x-1][y][0]+pow(hcoords[x][0]-hcoords[x-1][0], 2)+pow(hcoords[x][1]-hcoords[x-1][1], 2);
        b = dp[x-1][y][1]+pow(hcoords[x][0]-gcoords[y][0], 2)+pow(hcoords[x][1]-gcoords[y][1], 2);
        if(a < b){
            dp[x][y][0] = a; 
        } else{
            dp[x][y][0] = b;
        }
    } else if(dp[x-1][y][0] != -1){
        dp[x][y][0] = dp[x-1][y][0]+pow(hcoords[x][0]-hcoords[x-1][0], 2)+pow(hcoords[x][1]-hcoords[x-1][1], 2);
    } else{
        dp[x][y][0] = dp[x-1][y][1]+pow(hcoords[x][0]-gcoords[y][0], 2)+pow(hcoords[x][1]-gcoords[y][1], 2);
    }
    cout << dp[x][y][0] << '\n';
    return 0;
}