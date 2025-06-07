#include <iostream>
#include <string>
#include <queue>
using namespace std;

int n, m;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
char cow[50][50];
int visit[50][50];
queue<pair<int, int>> q;

void dfs(int y, int x){
    cow[y][x] = '1';
    q.push({y, x});
    visit[y][x] = 1;
    for(int i = 0; i < 4; i++){
        int yy = y+dy[i];
        int xx = x+dx[i];
        if(0 > yy || yy >= n || 0 > xx || xx >= m) continue;
        if(!visit[yy][xx] && cow[yy][xx] == 'X'){
            dfs(yy, xx);
        }
    }
}

int main(){
    cin >> n >> m;
    string buffer;
    int onex, oney;
    for(int y = 0; y < n; y++){
        cin >> buffer;
        for(int x = 0; x < m; x++){
            visit[y][x] = 0;
            cow[y][x] = buffer[x];
            if(cow[y][x] == 'X'){
                onex = x;
                oney = y;
            }
        }
    }
    dfs(oney, onex);
    
    while(!q.empty()){
        // cout <<"test\n";
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        
        for(int i = 0; i < 4; i++){
            int yy = y+dy[i];
            int xx = x+dx[i];
            if(0 > yy || yy >= n || 0 > xx || xx >= m) continue;
            if(!visit[yy][xx] && cow[yy][xx] != '1'){
                visit[yy][xx] = visit[y][x]+1;
                q.push({yy, xx});
            }
        }
    }
    
    int min = 25000;
    for(int y = 0; y < n; y++){
        for(int x = 0; x < m; x++){
            // cout << visit[y][x] << " ";
            // if(visit[y][x]/10 < 1) cout << ' ';

            if(cow[y][x] == 'X' && min > visit[y][x]) min = visit[y][x];
        }
        // cout << '\n';
    }
    cout << min-2 << '\n';
    return 0;
}