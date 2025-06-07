#include <iostream>
using namespace std;

int x, y, k, m;
int best = 1000;
int visit[103][103];
void dfs(int curx, int cury, int cnt){
    visit[curx][cury] = cnt;

    if(abs(m-curx-cury) < best){
        best = abs(m-curx-cury);
    }
    if(cnt < k){
        if(cury+curx < x){
            if(visit[cury+curx][0] > cnt){
                dfs(cury+curx, 0, cnt+1);
            }
        } else{
            if(visit[x][cury-x+curx] > cnt){
                dfs(x, cury-x+curx, cnt+1);
            }
        }
        if(visit[0][cury] > cnt){
            dfs(0, cury, cnt+1);
        }
        if(visit[curx][0] > cnt){
            dfs(curx, 0, cnt+1);
        }
        if(visit[x][cury]  > cnt){
            dfs(x, cury, cnt+1);
        }
        if(visit[curx][y] > cnt){
            dfs(curx, y, cnt+1);
        }
        if(curx+cury < y){
            if(visit[0][cury+curx] > cnt){
                dfs(0, cury+curx, cnt+1);
            }
        } else{
            if(visit[curx-y+cury][y] > cnt){
                dfs(curx-y+cury, y, cnt+1);
            }
        }
        
    }
}

int main(){
    // freopen("pails.in", "r", stdin);
    // freopen("pails.out", "w", stdout);
    cin >> x >> y >> k >> m;
    for(int i = 0; i <= 102; i++){
        for(int j = 0; j <= 102; j++){
            visit[i][j] = 9999;
        }
    }
    dfs(0, 0, 0);
    cout << best << '\n';
    return 0;
}