#include <iostream>
using namespace std;

int dp[500][500], visit[500][500], map[500][500], m, n;
int dx[4] = {0, 0, -1, 1}, dy[4] = {-1, 1, 0, 0};

void f(int x, int y){
    visit[x][y] = 1;
    // if(x == m-1 && y == n-1) return;
 
    for(int i = 0; i < 4; i++){
        int xx = x+dx[i], yy = y+dy[i];
        if(0 <= xx && xx < m && 0 <= yy && yy < n){
            if(map[xx][yy] < map[x][y]){
                if(!visit[xx][yy]){    
                    f(xx, yy);
                    // cout << xx << ' ' << yy << '\n';
                    // cout << dp[xx][yy] << '\n';
                    dp[x][y] += dp[xx][yy];
                } else{
                    dp[x][y] += dp[xx][yy];
                }
            }    
        }
    }

}

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> m >> n;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> map[i][j];
        }
    }   
    
    dp[m-1][n-1] = 1;


    f(0, 0);
    // for(int i = 0; i < m; i++){
    //     for(int j = 0; j < n; j++){
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }   

    cout << dp[0][0] << '\n';
    return 0;
}