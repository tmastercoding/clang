#include <iostream>
#include <queue>
using namespace std;

int dp[500][500], map[500][500], m, n;
int dx[4] = {0, 0, -1, 1}, dy[4] = {-1, 1, 0, 0};

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> m >> n;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> map[i][j];
        }
    }   
    
    dp[0][0] = 1;

    queue<pair<int, int>> q;
    q.push({0,0});

    while(!q.empty()){
        int x = q.front().first, y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int xx = x+dx[i], yy = y+dy[i];
            if(0 <= xx && xx < m && 0 <= yy && yy < n){
                if(map[xx][yy] < map[x][y]){
                    if(!dp[xx][yy]){
                        dp[xx][yy] += dp[x][y];
                        q.push({xx, yy});
                    } else{
                        dp[xx][yy] += dp[x][y];
                    }
                    
                }    
            }
        }
    }

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cout << dp[i][j] << ' ';
        }
        cout << '\n';
    }   

    cout << dp[m-1][n-1] << '\n';
    return 0;
}