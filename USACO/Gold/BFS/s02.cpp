#include <iostream>
#include <queue>
#include <string>
using namespace std;

int n, m;
int maze[101][101], visit[101][101];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main(){
    cin >> n >> m;
    for(int y = 1; y <= n; y++){
        string buffer;
        cin >> buffer;
        for(int x = 1; x <= m; x++){
            maze[y][x] = buffer[x-1]-'0';
            visit[y][x] = 0;
        }
    }

    queue<pair<int, int>> q;
    q.push({1, 1});
    visit[1][1] = 1;

    while(!q.empty()){
        int x = q.front().second;
        int y = q.front().first;
        // if(x == n && y == m) break;
        q.pop();

        for(int i = 0; i < 4; i++){
            int xx = x+dx[i];
            int yy = y+dy[i];
            if(1 > yy || yy > n || 1 > xx || xx > m) continue;
            if(!visit[yy][xx] && maze[yy][xx]){
                // cout << yy << ' ' << xx << '\n';
                visit[yy][xx] = visit[y][x]+1;
                pair<int, int> coords = {yy, xx};
                q.push(coords);
                // cout << q.front().first << '\n';
            }
        }
    }
    cout << visit[n][m] << '\n';
    return 0;
}