// Perimeter 5850
#include <iostream>
using namespace std;

int map[200][200], visit[200][200], cnt = 0;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void dfs(int y, int x){
    visit[y][x] = 1;

    for(int idx = 0; idx < 4; idx++){
        int yy = y+dy[idx];
        int xx = x+dx[idx];
        if(xx < 0 || yy < 0 || yy >= 200 || xx >= 200) continue;
        if(visit[yy][xx] == 0){
            if(map[yy][xx] == 0){
                dfs(yy, xx);
            } else{
                cnt++;
            }
        }
    }
}

int main(){
    // freopen("perimeter.in", "r", stdin);
    // freopen("perimeter.out", "w", stdout);
    int n;
    cin >> n;
    int y, x;
    for(int idx = 0; idx < n; idx++){
        cin >> x >> y;
        map[y+20][x+20] = 1;
    }

    dfs(0, 0);
    cout << cnt << '\n';
    return 0;
}