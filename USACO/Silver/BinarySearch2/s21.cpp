// Millionaire Madness 13349
#include <iostream>
#include <vector>
using namespace std;

int n, m, visit[1000][1000];
long long map[1000][1000];
int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
bool finished = false;
void dfs(int x, int y, long long lim){
    if(y == n-1 && x == m-1) finished = true;
    visit[y][x] = 1;
    int yy, xx;
    for(int i = 0; i < 4; i++){
        yy = y+dy[i];
        xx = x+dx[i];
        // cout << yy << ' '<< xx << '\n';
        if(0 > yy || yy >= n || 0 > xx || xx >= m) continue;
        if(!visit[yy][xx] && map[yy][xx]-map[y][x] <= lim) dfs(xx, yy, lim);
    }
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> map[i][j];
        }
    }

    long long lo = 0, hi = 1000000000, mid; 
    while(lo < hi){
        mid = (lo+hi)/2;
        finished = false;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                visit[i][j] = 0;
            }
        }
        dfs(0, 0, mid);
        // cout << finished << '\n';
        if(finished){
            hi = mid;
        } else{
            lo = mid+1;
        }
    }
    cout << lo << '\n';
    return 0;
}