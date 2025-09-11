#include <iostream>
#include <string>
using namespace std;

int dp[3001][3001];

int main(){
    string s, t;
    cin >> s >> t;

    
    // for(int y = 1; y < t.size(); y++){
    //     if(y > 0) dp[0][y] = dp[0][y-1];
    //     if(s[0] == t[y]){
    //         dp[0][y] = 1;
    //     }
    // }

    for(int x = 1; x <= s.size(); x++){
        for(int y = 1; y <= t.size(); y++){
            dp[x][y] = dp[x-1][y];
            if(dp[x][y] < dp[x][y-1]) dp[x][y] = dp[x][y-1];
            if(s[x-1] == t[y-1]){
                if(dp[x][y] < dp[x-1][y-1]+1) dp[x][y] = dp[x-1][y-1]+1;
            }
        }
    }
    
    // for(int x = 1; x <= s.size(); x++){
    //     for(int y = 1; y <= t.size(); y++){
    //         cout << dp[x][y] << ' ';
    //     }
    //     cout << '\n';
    // }

    int x = s.size(), y = t.size();
    int cnt = 0;
    int prev2 = 0, prev1 = 0;
    string output = "";
    while(x > 0 && y > 0){
        // cout << x << ' ' << y << '\n';
        if(dp[x-1][y-1] == dp[x][y]-1 && s[x-1] == t[y-1]){
            // cout << "match\n";
            if(prev2 == 1 && prev1 == 2) cnt--;
            prev2 = prev1;
            prev1 = 0;
            output += s[x-1];
            x--;
            y--;
        } else if(dp[x][y-1] == dp[x][y]){
            prev2 = prev1;
            prev1 = 1;
            cnt++;
            // cout << "left\n";
            y--;
        } else if(dp[x-1][y] == dp[x][y]){
            prev2 = prev1;
            prev1 = 2;
            cnt++;
            // cout << "up\n";
            x--;
        } else{
            // cout << "skip\n";
            x--;
            y--;
        }

    }

    // for(int i = output.length()-1; i > -1; i--) cout << output[i];
    // cout << '\n';
    cout << cnt << '\n';
    return 0;
}