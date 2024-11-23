// 치즈 2638
#include <iostream>
using namespace std;

int n, m, map[200][200], visit[200][200];
int dy[4] = {0, 0, -1, 1};
int dx[4] = {1, -1, 0, 0};

void out_dfs(int y, int x){
    visit[y][x] = -1;

    int yy, xx;
    for(int i = 0; i < 4; i++){
        yy = y + dy[i];
        xx = x + dx[i];
        if(0 > yy || 0 > xx || yy >= 200 || xx >= 200) continue;
        if(visit[yy][xx] == 0 && map[yy][xx] == 0){
            out_dfs(yy, xx);
        }
    }
}

int main(){
    cin >> n >> m;
    for(int y = 0; y < n; y++){
        for(int x = 0; x < m; x++){
            cin >> map[y+20][x+20];
        }
    }

    int t= 0;
    while(true){
        for(int y = 0; y < 200; y++){
            for(int x = 0; x < 200; x++){
                visit[y][x] = 0;
            }
        }
        
        out_dfs(0, 0);

        bool isGone = true;
        for(int y = 0; y < 200; y++){
            for(int x = 0; x < 200; x++){
                if(map[y][x] == 1 && visit[y][x] == 0){
                    isGone = false;
                    int yy, xx;
                    int zeroCnt = 0;
                    for(int idx = 0; idx < 4; idx++){
                        yy = y+dy[idx];
                        xx = x+dx[idx];
                        if(visit[yy][xx] == -1){
                            zeroCnt++;
                        }
                    }
                    if(zeroCnt >= 2){
                        map[y][x] = 0;
                    }
                }
            }
        }
        if(isGone){
            break;
        }
        t++;
    }
    cout << t << '\n';
    return 0;
}