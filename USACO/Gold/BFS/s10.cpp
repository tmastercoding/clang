#include <iostream>
#include <queue>
#include <string> 
#include <vector>
using namespace std;

int world[1001][1001], visit[1001][1001][2];
int main(){
    int n, m;
    cin >> n >> m;
    for(int y = 1; y <= n; y++){
        string buffer;
        cin >> buffer;
        for(int x = 1; x <= m; x++){
            world[x][y] = buffer[x-1]-'0';
            visit[x][y][0] = 0;
            visit[x][y][1] = 0;
        }
    }
    queue<vector<int>> q;
    visit[1][1][0] = 1;
    q.push({1, 1, 0});
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};
    bool print = false;
    while(!q.empty()){
        int x = q.front()[0];
        int y = q.front()[1];
        int state = q.front()[2];
        q.pop();
        if(x == m && y == n){
            print = true;
            cout << visit[x][y][state] << '\n';
            break;
        }
        for(int i = 0; i < 4; i++){
            int xx = x+dx[i], yy = y+dy[i];
            if(1 > xx || xx > m || 1 > yy || yy > n) continue;
            if(state == 0){
                if(!world[xx][yy] && !visit[xx][yy][0]){
                    visit[xx][yy][0] = visit[x][y][state]+1;
                    q.push({xx, yy, 0});
                }
                if(world[xx][yy] && !visit[xx][yy][1]){
                    visit[xx][yy][1] = visit[x][y][state]+1;
                    q.push({xx, yy, 1});
                }
            } else{
                if(!world[xx][yy] && !visit[xx][yy][state]){
                    visit[xx][yy][state] = visit[x][y][state]+1;
                    q.push({xx, yy, state});
                }
            }
        }
    }
    if(!print){
        cout << -1 << '\n'; 
    }
    return 0;
}