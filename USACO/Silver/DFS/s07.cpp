// 침투 13565
#include <iostream>
#include <string>
using namespace std;

int m, n, map[1000][1000], visit[1000][1000];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
bool reach = false;

void dfs(int y, int x){
    // cout << y << x << '\n';
    if(y == m-1){
        reach = true;
    }
    visit[y][x] = 1;
    for(int idx = 0; idx < 4; idx++){
        int yy = y+dy[idx];
        int xx = x+dx[idx];
        
        if(xx < 0 || yy < 0 || yy >= m || xx >= n) continue;
        if(map[yy][xx] == 0 && visit[yy][xx] == 0){
            dfs(yy, xx);
        }
    }
}

int main(){
    cin >> m >> n;
    string row;

    for(int y = 0; y < m; y++){
        cin >> row;    
        for(int x = 0; x < n; x++){
            map[y][x] = row[x]-'0';
            visit[y][x] = 0;
        }
    }

    for(int x = 0; x < n; x++){
        if(map[0][x] == 0){
            dfs(0, x);
        }
        if(reach){
            cout << "YES\n";
            break;
        }
    }

    if(!reach){
        cout << "NO\n";
    }

    
    return 0;
}