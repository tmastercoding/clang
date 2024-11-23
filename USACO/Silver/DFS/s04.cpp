// 섬의 개수 4963
#include <iostream>
#include <vector>
using namespace std;

int w, h, visit[50][50], map[50][50];
int dx[8] = {0, 0, 1, -1, 1, -1, 1, -1};
int dy[8] = {1, -1, 0, 0, 1, -1, -1, 1};

void dfs(int y, int x){
    visit[y][x] = 1;

    for(int idx = 0; idx < 8; idx++){
        int yy = y + dy[idx];
        int xx = x + dx[idx];

        if(xx < 0 || yy < 0 || xx >= w || yy >= h) continue;
        if(visit[yy][xx] == 0 && map[yy][xx] == 1){
            dfs(yy, xx);
        }
    }
}

int main(){
    while (true){
        cin >> w >> h;
        if(w == 0 && h == 0){
            break;
        }

        for(int y = 0; y < h; y++){
            for(int x = 0; x < w; x++){
                cin >> map[y][x];
                visit[y][x] = 0;
            }
        }

        int cnt = 0;
        for(int y = 0; y < h; y++){
            for(int x = 0; x < w; x++){
                if(map[y][x] == 1 && visit[y][x] == 0){
                    dfs(y, x);
                    cnt++;
                }
            }
        }
        cout << cnt << '\n';
    }
    
    return 0;
}