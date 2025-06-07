#include <iostream>
#include <queue>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    int box[1000][1000], visit[1000][1000];
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    queue<pair<int, int>> q;

    for(int y = 0; y < m; y++){
        for(int x = 0; x < n; x++){
            cin >> box[y][x];
            visit[y][x] = 0;
            if(box[y][x] == 1){
                q.push({y, x});
                visit[y][x] = 1;
            }
        }
    }


    while(!q.empty()){
        int x = q.front().second;
        int y = q.front().first;
        q.pop();
        for(int i = 0; i < 4; i++){
            int xx = x+dx[i];
            int yy = y+dy[i];
            if(xx < 0 || xx >= n || yy < 0 || yy >= m) continue;
            if(visit[yy][xx] == 0 && box[yy][xx] == 0){
                visit[yy][xx] = visit[y][x]+1;
                q.push({yy, xx});
            }
        }
    }

    int max = 0;
    for(int y = 0; y < m; y++){
        if(max == -1) break;
        for(int x = 0; x < n; x++){
            // cout << visit[y][x] << ' ';
            if(visit[y][x] == 0 && box[y][x] != -1){
                max = -1;
                break;
            } else{
                if(max < visit[y][x]){
                    max = visit[y][x];
                }
            }
        }
        // cout << '\n';
    }
    if(max != -1) max--;
    cout << max << '\n';

    return 0;
}