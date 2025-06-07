#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main(){
    int r, c;
    cin >> r >> c;
    char world[50][50];
    int visit[50][50];
    string buffer;
    queue<pair<int, int>> q;
    int damx, damy;
    for(int y = 0; y < r; y++){
        cin >> buffer;
        for(int x = 0; x < c; x++){
            visit[y][x] = 0;
            world[y][x] = buffer[x];
            if(world[y][x] == 'D'){
                damy = y, damx = x;
            } else if(world[y][x] == '*'){
                q.push({y, x});
                visit[y][x] = -1;
            }
        }
    }
    
    for(int y = 0; y < r; y++){
        for(int x = 0; x < c; x++){
            if(world[y][x] == 'S'){
                q.push({y, x});
                visit[y][x] = 1;
            } 
        }
    }

    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {1, -1, 0, 0};
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int yy = y + dy[i];
            int xx = x + dx[i];
            if(0 > yy || yy >= r || 0 > xx || xx >= c) continue;
            // if painter
            if(visit[y][x] > 0){
                if(!visit[yy][xx] && world[yy][xx] != '*' && world[yy][xx] != 'X'){
                    visit[yy][xx] = visit[y][x]+1;
                    q.push({yy, xx});
                }
            } else if(visit[y][x] == -1){
                if(!visit[yy][xx] && world[yy][xx] == '.'){
                    visit[yy][xx] = -1;
                    q.push({yy, xx});
                }
            }
        }
    }
    if(!visit[damy][damx]){
        cout << "KAKTUS\n"; 
    } else{
        cout << visit[damy][damx]-1 << '\n';
    }

    return 0;
}