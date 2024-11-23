#include <iostream>
using namespace std;

int n, map[101][101], visit[101][101];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void dfs(int y, int x){
    visit[y][x] = 1;
    int yy, xx;
    for(int idx = 0; idx < 4; idx++){
        yy = y+dy[idx];
        xx = x+dx[idx];
        if(0 > yy || 0 > xx || yy >= n || xx >= n) continue;
        if(visit[yy][xx] == 0){
            dfs(yy, xx);
        }
    }
}

int main(){
    cin >> n;
    for(int y = 0; y < n; y++){
        for(int x = 0; x < n; x++){
            cin >> map[y][x];
        }
    }
    int cnt, maxCnt = 0;
    for(int height = 0; height <= 1000; height++){
        for(int sy = 0; sy < n; sy++){
            for(int sx = 0; sx < n; sx++){
                visit[sx][sy] = 0;
                if(map[sx][sy] <= height){
                    visit[sx][sy] = -1;
                }

            }
        }
        cnt = 0;
        for(int y = 0; y < n; y++){
            for(int x = 0; x < n; x++){
                if(visit[y][x] == 0){
                    dfs(y, x);
                    cnt++;
                }
            }
        }
        if(cnt > maxCnt){
            maxCnt = cnt;
        }
    }
    cout << maxCnt << '\n';
    return 0;
}