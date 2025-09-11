#include <iostream>
#include <string>
using namespace std;

int dp[21][101][2];

int main(){
    string magic, demon, angel;
    cin >> magic >> demon >> angel;

    for(int y = 1; y <= demon.size(); y++){
        dp[1][y][0] = dp[1][y-1][0];
        dp[1][y][1] = dp[1][y-1][1];
        if(demon[y-1] == magic[0]){
            dp[1][y][0] += 1;
        }
        if(angel[y-1] == magic[0]){
            dp[1][y][1] += 1;
        }
    }

    for(int x = 2; x <= magic.size(); x++){
        for(int y = 1; y <= demon.size(); y++){
            dp[x][y][0] = dp[x][y-1][0];
            dp[x][y][1] = dp[x][y-1][1];
            if(demon[y-1] == magic[x-1]){
                dp[x][y][0] += dp[x-1][y-1][1];
            }
            if(angel[y-1] == magic[x-1]){
                dp[x][y][1] += dp[x-1][y-1][0];
            }
        }
    }
    
    // for(int x = 1; x <= magic.size(); x++){
    //     for(int y = 1; y <= demon.size(); y++){
    //         cout << '(' << dp[x][y][0] << ',' << dp[x][y][1] << ") ";
    //     }
    //     cout << '\n';
    // }


    cout << dp[magic.size()][demon.size()][0] + dp[magic.size()][demon.size()][1] << '\n';

    return 0;
}