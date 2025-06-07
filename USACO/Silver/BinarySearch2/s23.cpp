// 배열에서 이동 1981
#include <iostream>
using namespace std;

int n;
int map[100][100], visit[100][100];
int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
bool reached = false;

void dfs(int x, int y, int min, int max){
    // cout << x << ' ' << y << '\n';
    if(map[y][x] > max) return;
    if(map[y][x] < min) return;
    if(y == n-1 && x == n-1) reached = true;
    visit[y][x] = 1;

    for(int i = 0; i < 4; i++){
        int yy = y+dy[i], xx = x+dx[i];
        if(0 > yy || yy >= n || 0 > xx || xx >= n) continue;
        if(!visit[yy][xx]){
            if(map[yy][xx] > max) continue;
            if(map[yy][xx] < min) continue;
            dfs(xx, yy, min, max);
        }
    }
}

int main(){
    cin >> n;
    int maxNum = 0;
    for(int y = 0; y < n; y++){
        for(int x = 0; x < n; x++){
            cin >> map[y][x];
            if(maxNum < map[y][x]) maxNum  = map[y][x];
        }
    }
    
    int minDif = 200;
    for(int min = 0; min <= maxNum; min++){
        int lo = min, hi = maxNum, mid;
        while(lo < hi){
            mid = (lo+hi)/2;
            for(int y = 0; y < n; y++){
                for(int x = 0; x < n; x++){
                    visit[y][x] = 0;
                }
            }
            reached = false;
            dfs(0, 0, min, mid);
            // cout << "MID: " << mid << ' ' << reached << '\n';
            if(reached){
                hi = mid;
            } else{
                lo = mid+1;
            }    
        }
        for(int y = 0; y < n; y++){
            for(int x = 0; x < n; x++){
                visit[y][x] = 0;
            }
        }
        reached = false;
        dfs(0, 0, min, lo);
        // cout << min << ' ' << lo << ' ' << reached << '\n';
        if(lo-min < minDif && reached) minDif = lo-min;
    }
    cout << minDif << '\n';
    return 0;
}