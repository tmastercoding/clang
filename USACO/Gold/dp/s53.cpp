#include <iostream>
#include <vector>
using namespace std;

int n, map[500][500], visit[500][500], dp[500][500];
int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0}; 

int dfs(int x, int y, int cur){
    visit[x][y] = 1;

    for(int i = 0; i < 4; i++){
        int xx = x+dx[i], yy = y+dy[i];
        if(0 <= xx && xx < n && 0 <= y && y < n){
            if(map[xx][yy] > map[x][y]){
                adj[x][y]
            }
        }
    }


}

int main(){
    cin >> n;
    for(int x = 0; x < n; x++){
        for(int y = 0; y < n; y++){
            cin >> map[x][y];
        }
    }
    return 0;
}