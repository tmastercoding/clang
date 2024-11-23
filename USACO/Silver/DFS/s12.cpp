#include <iostream>
using namespace std;

int n, visit[64][64], map[64][64];
bool hasWon = false;
int dy[2] = {0, 1};
int dx[2] = {1, 0};


void dfs(int y, int x){
    if(map[y][x] == -1){
        hasWon = true;
    }
    visit[y][x] = 1;
    for(int r = 0; r < 2; r++){
        int yy = y+dy[r]*map[y][x], xx = x+dx[r]*map[y][x];
        if(yy >= n || xx >= n) continue;
        if(visit[yy][xx] == 0){
            dfs(yy, xx);
        }        
    }
}

int main(){
    cin >> n;

    for(int y = 0; y < n; y++){
        for(int x = 0; x < n; x++){
            cin >> map[y][x];
        }
    }

    dfs(0,0);
    if(hasWon){
        cout <<"HaruHaru\n";
    } else{
        cout <<"Hing\n";
    }
    return 0;
}