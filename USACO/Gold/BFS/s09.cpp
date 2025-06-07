#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;

int main(){
    int n;
    int visit[50][50];
    char forest[50][50];

    cin >> n;
    queue<vector<pair<int, int>>> q;
    vector<pair<int, int>> og, finish, cur;
    for(int y = 0; y < n; y++){
        string buffer;
        cin >> buffer;
        for(int x = 0; x < n; x++){
            forest[y][x] = buffer[x];
            visit[y][x] = 0;
            if(buffer[x] == 'B'){
                visit[y][x] = 1;
                og.push_back({y, x});
            }
            if(buffer[x] == 'E'){
                finish.push_back({y, x});
            }
        }
    }
    q.push(og);

    while(!q.empty()){
        cur = q.front();
        cout << cur[0].second << ',' << cur[0].first << ' ' << cur[1].second << ',' << cur[1].first << ' ' << cur[2].second << ',' << cur[2].first << '\n'; 
        q.pop();
        bool done = true;
        for(int i = 0; i < 3; i++){
            bool flag = false;
            for(int j = 0; j < 3; j++){
                if(finish[i].first == cur[j].first && finish[i].second == cur[j].second) flag = true;
            }
            if(!flag){
                done = false;
                break; 
            }
        }
        if(done){
            break;
        } 
        
        // up
        if(cur[0].first-1 >= 0 && forest[cur[0].first-1][cur[0].second] != '1' && forest[cur[1].first-1][cur[1].second] != '1' && forest[cur[2].first-1][cur[2].second] != '1'){
            if(!visit[cur[0].first-1][cur[0].second] && !visit[cur[1].first-1][cur[1].second] && !visit[cur[2].first-1][cur[2].second]){
                visit[cur[0].first-1][cur[0].second] = visit[cur[0].first][cur[0].second]+1;
                visit[cur[1].first-1][cur[1].second] = visit[cur[1].first][cur[1].second]+1;
                visit[cur[2].first-1][cur[2].second] = visit[cur[2].first][cur[2].second]+1;
                q.push({{cur[0].first-1, cur[0].second}, {cur[1].first-1, cur[1].second}, {cur[2].first-1, cur[2].second}});
            }
        }
        // down
        if(cur[2].first+1 < n && forest[cur[2].first+1][cur[2].second] != '1' && forest[cur[1].first+1][cur[1].second] != '1' && forest[cur[0].first+1][cur[0].second] != '1'){
            if(!visit[cur[0].first+1][cur[0].second] && !visit[cur[1].first+1][cur[1].second] && !visit[cur[2].first+1][cur[2].second]){
                visit[cur[0].first+1][cur[0].second] = visit[cur[0].first][cur[0].second]+1;
                visit[cur[1].first+1][cur[1].second] = visit[cur[1].first][cur[1].second]+1;
                visit[cur[2].first+1][cur[2].second] = visit[cur[2].first][cur[2].second]+1;
                q.push({{cur[0].first+1, cur[0].second}, {cur[1].first+1, cur[1].second}, {cur[2].first+1, cur[2].second}});
            }
        }
        // left
        if(cur[0].second-1 >= 0 && forest[cur[0].first][cur[0].second-1] != '1' && forest[cur[1].first][cur[1].second-1] != '1' && forest[cur[2].first][cur[2].second-1] != '1'){
            if(!visit[cur[0].first][cur[0].second-1] && !visit[cur[1].first][cur[1].second-1] && !visit[cur[2].first][cur[2].second-1]){
                visit[cur[0].first][cur[0].second-1] = visit[cur[0].first][cur[0].second]+1;
                visit[cur[1].first][cur[1].second-1] = visit[cur[1].first][cur[1].second]+1;
                visit[cur[2].first][cur[2].second-1] = visit[cur[2].first][cur[2].second]+1;
                q.push({{cur[0].first, cur[0].second-1}, {cur[1].first, cur[1].second-1}, {cur[2].first, cur[2].second-1}});
            }
        }
        // right
        if(cur[2].second+1 < n && forest[cur[2].first][cur[2].second+1] != '1' && forest[cur[1].first][cur[1].second+1] != '1' && forest[cur[0].first][cur[0].second+1] != '1'){
            if(!visit[cur[0].first][cur[0].second+1] && !visit[cur[1].first][cur[1].second+1] && !visit[cur[2].first][cur[2].second+1]){
                visit[cur[0].first][cur[0].second+1] = visit[cur[0].first][cur[0].second]+1;
                visit[cur[1].first][cur[1].second+1] = visit[cur[1].first][cur[1].second]+1;
                visit[cur[2].first][cur[2].second+1] = visit[cur[2].first][cur[2].second]+1;
                q.push({{cur[0].first, cur[0].second+1}, {cur[1].first, cur[1].second+1}, {cur[2].first, cur[2].second+1}});
            }
        }
        
        if(cur[0].second == cur[2].second){
            // cout << "adsf" << '\n';xwZ
            if(cur[0].second-1 >= 0 && cur[0].second+1 < n){
                bool flag = true;
                for(int y = cur[0].first; y <= cur[2].first; y++){
                    for(int x = cur[0].second-1; x <= cur[0].second+1; x++){
                        if(x == cur[0].second) continue;
                        if(forest[x][y] == '1') flag = false;
                    }
                }
                cout << flag << '\n';
                if(flag){
                    cout << cur[1].first << ' ' << cur[2].second+1 << ' ' << visit[cur[1].first][cur[2].second+1] << '\n';
                    if(!visit[cur[1].first][cur[0].second-1] || !visit[cur[1].first][cur[2].second+1]){
                        visit[cur[1].first][cur[0].second-1] = visit[cur[0].first][cur[0].second]+1;
                        visit[cur[1].first][cur[1].second] = visit[cur[1].first][cur[1].second]+1;
                        visit[cur[1].first][cur[2].second+1] = visit[cur[2].first][cur[2].second]+1;
                        q.push({{cur[1].first, cur[0].second-1}, {cur[1].first, cur[1].second}, {cur[1].first, cur[2].second+1}});
                    }
                }
            }
        }
        if(cur[0].first == cur[2].first){
            if(cur[0].first-1 >= 0 && cur[0].first+1 < n){
                bool flag = true;
                for(int y = cur[0].first-1; y <= cur[2].first+1; y++){
                    if(y == cur[0].first) continue;
                    for(int x = cur[0].second; x <= cur[2].second; x++){
                        if(forest[x][y] == '1') flag = false;
                    }
                }
                if(flag){
                    if(!visit[cur[0].first-1][cur[1].second] || !visit[cur[2].first+1][cur[1].second]){
                        visit[cur[0].first-1][cur[1].second] = visit[cur[0].first][cur[0].second]+1;
                        visit[cur[1].first][cur[1].second] = visit[cur[1].first][cur[1].second]+1;
                        visit[cur[2].first+1][cur[1].second] = visit[cur[2].first][cur[2].second]+1;
                        q.push({{cur[0].first-1, cur[1].second}, {cur[1].first, cur[1].second}, {cur[2].first+1, cur[1].second}});
                    }
                }
            }
        }

    }
    cout << visit[finish[1].first][finish[1].second]-1 << '\n';
    return 0;
}