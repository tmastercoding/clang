#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;

int main(){
    int n;
    int visit[50][50][2];
    char forest[50][50];

    cin >> n;
    queue<vector<pair<int, int>>> q;
    vector<pair<int, int>> og, cur;
    for(int y = 0; y < n; y++){
        string buffer;
        cin >> buffer;
        for(int x = 0; x < n; x++){
            forest[y][x] = buffer[x];
            visit[y][x][0] = 0;
            visit[y][x][1] = 0;
            if(buffer[x] == 'B'){
                og.push_back({y, x});
            }
        }
    }


    // BBB horizontal
    if(og[0].first == og[2].first){
        visit[og[1].first][og[1].second][0] = 1;
    } else{
        visit[og[1].first][og[1].second][1] = 1;
    }
    q.push(og);
    
    bool print = false;
    while(!q.empty()){
        cur = q.front();
        // cout << cur[0].second << ',' << cur[0].first << ' ' << cur[1].second << ',' << cur[1].first << ' ' << cur[2].second << ',' << cur[2].first << '\n'; 
        q.pop();
        int rot = 0;
        if(cur[0].first == cur[2].first){
            rot = 0;
        } else{
            rot = 1;
        }
        if(forest[cur[0].first][cur[0].second] == 'E' && forest[cur[1].first][cur[1].second] == 'E' && forest[cur[2].first][cur[2].second] == 'E'){
            cout << visit[cur[1].first][cur[1].second][rot]-1 << '\n';
            print = true;
            break;
        } 
        
        // up
        if(cur[0].first-1 >= 0 && forest[cur[0].first-1][cur[0].second] != '1' && forest[cur[1].first-1][cur[1].second] != '1' && forest[cur[2].first-1][cur[2].second] != '1'){
            if(!visit[cur[1].first-1][cur[1].second][rot]){
                visit[cur[1].first-1][cur[1].second][rot] = visit[cur[1].first][cur[1].second][rot]+1;
                q.push({{cur[0].first-1, cur[0].second}, {cur[1].first-1, cur[1].second}, {cur[2].first-1, cur[2].second}});
            }
        }
        // down
        if(cur[2].first+1 < n && forest[cur[2].first+1][cur[2].second] != '1' && forest[cur[1].first+1][cur[1].second] != '1' && forest[cur[0].first+1][cur[0].second] != '1'){
            // cout << forest[cur[0].first+1][cur[0].second] <<  '\n';
            if(!visit[cur[1].first+1][cur[1].second][rot]){ 
                // cout << cur[0].first+1 << '\n';  
                visit[cur[1].first+1][cur[1].second][rot] = visit[cur[1].first][cur[1].second][rot]+1;
                q.push({{cur[0].first+1, cur[0].second}, {cur[1].first+1, cur[1].second}, {cur[2].first+1, cur[2].second}});
            }
        }
        // left
        if(cur[0].second-1 >= 0 && forest[cur[0].first][cur[0].second-1] != '1' && forest[cur[1].first][cur[1].second-1] != '1' && forest[cur[2].first][cur[2].second-1] != '1'){
            // cout << forest[cur[1].first][cur[1].second-1]<< '\n';
            if(!visit[cur[1].first][cur[1].second-1][rot]){
                visit[cur[1].first][cur[1].second-1][rot] = visit[cur[1].first][cur[1].second][rot]+1;
                q.push({{cur[0].first, cur[0].second-1}, {cur[1].first, cur[1].second-1}, {cur[2].first, cur[2].second-1}});
            }
        }
        // right
        if(cur[2].second+1 < n && forest[cur[2].first][cur[2].second+1] != '1' && forest[cur[1].first][cur[1].second+1] != '1' && forest[cur[0].first][cur[0].second+1] != '1'){
            if(!visit[cur[1].first][cur[1].second+1][rot]){
                visit[cur[1].first][cur[1].second+1][rot] = visit[cur[1].first][cur[1].second][rot]+1;
                q.push({{cur[0].first, cur[0].second+1}, {cur[1].first, cur[1].second+1}, {cur[2].first, cur[2].second+1}});
            }
        }
        
        // vertical
        if(rot){
            if(cur[0].second-1 >= 0 && cur[0].second+1 < n){
                bool flag = true;
                for(int y = cur[0].first; y <= cur[2].first; y++){
                    for(int x = cur[0].second-1; x <= cur[0].second+1; x++){
                        if(x == cur[0].second) continue;
                        if(forest[y][x] == '1') flag = false;
                    }
                }
                // cout << flag << '\n';
                if(flag){
                    // cout << cur[1].first << ' ' << cur[2].second+1 << ' ' << visit[cur[1].first][cur[2].second+1] << '\n';
                    if(!visit[cur[1].first][cur[1].second][0]){
                        visit[cur[1].first][cur[1].second][0] = visit[cur[1].first][cur[1].second][rot]+1;
                        q.push({{cur[1].first, cur[0].second-1}, {cur[1].first, cur[1].second}, {cur[1].first, cur[2].second+1}});
                    }
                }
            }
        }
        if(!rot){
            if(cur[0].first-1 >= 0 && cur[0].first+1 < n){
                bool flag = true;
                for(int y = cur[0].first-1; y <= cur[2].first+1; y++){
                    if(y == cur[0].first) continue;
                    for(int x = cur[0].second; x <= cur[2].second; x++){
                        if(forest[y][x] == '1') flag = false;
                    }
                }
                if(flag){
                    // cout << "YES\n"; 
                    if(!visit[cur[1].first][cur[1].second][1]){
                        visit[cur[1].first][cur[1].second][1] = visit[cur[1].first][cur[1].second][rot]+1;
                        q.push({{cur[0].first-1, cur[1].second}, {cur[1].first, cur[1].second}, {cur[2].first+1, cur[1].second}});
                    }
                }
            }
        }

    }
    // int prevx= -1, prevy;
    // for(int y = 0; y < n; y++){
    //     for(int x = 0; x < n; x++){
    //         cout << visit[y][x][0] << ',';
    //         cout << visit[y][x][1] << ' ';
    //         // if(prevx == -1 && forest[y][x] == 'E'){
    //         //     prevx = x;
    //         //     prevy = y;
    //         // } 
    //         // if(prevx != -1 && forest[y][x] == 'E'){
    //         //     // if(prevx == x){ 
    //         //     // } else{
    //         //     // }
    //         //     break;
    //         // }
            
    //     }
    //     cout << '\n';
    // }

    if(!print) cout << 0 << '\n';
    return 0;
}