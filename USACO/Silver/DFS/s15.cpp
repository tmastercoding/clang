// 빙산 2573
#include <iostream>
using namespace std;

int n, m, map[300][300], visit[300][300], subs[300][300];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1, 0,0};

void dfs(int y, int x){
    visit[y][x] = 1;
    for(int r = 0; r < 4; r++){
        int yy, xx;
        yy = y+dy[r];    
        xx = x+dx[r];
        if(0 > yy || 0 > xx|| yy >= n || xx>=m) continue;
        if(visit[yy][xx] == 0 && map[yy][xx] > 0){
            dfs(yy, xx);
        }
    }
}
int main(){
    cin >> n >> m;
    for(int y = 0; y < n; y++){
        for(int x = 0; x < m; x++){
            cin >> map[y][x];
        }
    }
    int year = 1;
    while(true){
        for(int y = 0; y < n; y++){
            for(int x = 0; x < m; x++){
                visit[y][x] = 0;
                int subtract = 0;
                subs[y][x] = 0;
                if(map[y][x]!=0){
                    for(int r = 0; r < 4; r++){
                        int yy, xx;
                        yy = y+dy[r];    
                        xx = x+dx[r];
                        if(0 > yy || 0 > xx|| yy >= n || xx>=m) continue;
                        if(map[yy][xx] == 0){
                            subtract++;
                        }
                    }
                }
                subs[y][x] = subtract;
            }
        }

        for(int y = 0; y < n; y++){
            for(int x = 0; x < m; x++){
                map[y][x] -= subs[y][x];
                if(map[y][x] < 0){
                    map[y][x] = 0;
                }
                // cout << map[y][x] << ' ';
            }
            // cout << '\n';
        }

        int cnt = 0;
        for(int y = 0; y < n; y++){
            for(int x = 0; x < m; x++){
                if(map[y][x] > 0 && visit[y][x] == 0){
                    dfs(y, x);
                    cnt++;
                }
            }
        }
        
        if(cnt == 0){
            cout << 0 << '\n';
            break;
        } else if(cnt > 1){
            cout << year << '\n';
            break;
        }
        year++;
    }

    return 0;
}
