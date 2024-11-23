// 단지번호붙이기 2667
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int n, map[25][25], visit[25][25] = {0,};
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int cnt = 0;

void dfs(int y, int x){
    visit[y][x] = 1;
    cnt++; 
    for(int idx = 0; idx < 4; idx++){
        int yy = y+dy[idx];
        int xx = x+dx[idx];

        if(yy < 0 || xx < 0 || yy >= n || xx >= n) continue;
        if(visit[yy][xx] == 0 && map[yy][xx] == 1){
            dfs(yy, xx);
        }
    }
}


int main(){
    cin >> n;
    string row;
    for(int y = 0; y < n; y++){
        cin >> row;
        for(int x = 0; x < n; x++){
            map[y][x] = row[x]-'0';
            visit[y][x] = 0;
        }
    }

    vector<int> blocks;
    for(int y = 0; y < n; y++){
        for(int x = 0; x < n; x++){
            // cout << map[y][x] << visit[y][x] << '\n';
            if(map[y][x] == 1 && visit[y][x] == 0){
                dfs(y, x);
                blocks.push_back(cnt);
                cnt = 0;
            }
        }
    }
    cout << blocks.size() << '\n';
    sort(blocks.begin(), blocks.end());
    for(int idx = 0; idx < blocks.size(); idx++){
        cout << blocks[idx] << '\n';
    }

    return 0;
}