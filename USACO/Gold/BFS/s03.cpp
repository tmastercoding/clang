#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main(){
    int n, m;
    char map[50][50];
    int visit[50][50];
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {1, -1, 0, 0};
    cin >> n >> m;
    for(int y = 0; y < n; y++){
        string buffer;
        cin >> buffer;
        for(int x = 0; x < m; x++){
            map[y][x] = buffer[x];
        }
    }

    int max = 1;
    for(int y = 0; y < n; y++){
        for(int x = 0; x < m; x++){
            if(map[y][x] == 'W') continue;
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++) visit[i][j] = 0;
            }

            queue<pair<int, int>> q;
            q.push({y, x});
            visit[y][x] = 1;

            while(!q.empty()){
                int curx = q.front().second;
                int cury = q.front().first;
                q.pop();
                for(int idx = 0; idx < 4; idx++){
                    int xx = curx+dx[idx];
                    int yy = cury+dy[idx];
                    if(0 > yy || yy > n || 0 > xx || xx > m) continue;
                    if(!visit[yy][xx] && map[yy][xx] == 'L'){
                        visit[yy][xx] = visit[cury][curx]+1;
                        if(max < visit[yy][xx]) max = visit[yy][xx];
                        q.push({yy, xx});
                    }
                }
            }
        }
    }
    cout << max-1 << '\n';

    return 0;
}