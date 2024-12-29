#include <iostream>
#include <vector>
using namespace std;

int visit[8][8];
int ax, ay;
int cnt = 0, minCnt =10, k;
int dx[8] = {1,-1,-1,1,2,-2,-2,2};
int dy[8] = {2,2,-2,-2,-1,-1,1,1};

void dfs(int x, int y){
    if(x == ax && y == ay){
        if(cnt < minCnt){
            minCnt = cnt;
        }
        return;
    }
    if(cnt == k){
        return;
    }
    visit[x][y] = 1;
    for(int d = 0; d < 8; d++){
        int xx, yy;
        xx = x + dx[d];
        yy = y + dy[d];
        if(visit[xx][yy] == 0){
            cnt++;
            dfs(xx, yy);
            visit[xx][yy] = 0;
            cnt--;
        }
    }
}

int main(){
    int a, b;
    cin >> a >> b >> k >> ax >> ay;
    a--;
    b--;
    ax--;
    ay--;
    dfs(a, b);
    if(minCnt > k){
        cout << -1 << '\n';
    } else{
        cout << minCnt << '\n';
    }
    return 0;
}