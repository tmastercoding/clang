#include <iostream>
using namespace std;

char map[1000][1000], visit[1000][1000];
int n;
bool usable = true;
int cnt = 0;
// int dx[4] = {1,-1,0,0};
void dfs(int x, int y){
    cout << x  << ' ' << y << ':' << map[x][y] << '\n';
    if(y < 0 || x < 0 || y >= n || x >= n ){
        cout << "OUTSIDE\n";
        usable = true;
        return;
    }
    if(map[x][y] == 0){
        cout << "EMPTY\n";
        usable = true;
        return;
    }
    if(visit[x][y] || map[x][y] == 'X'){
        cout << "LOOP\n";
        usable = false;
        return;
    }
    visit[x][y] = 1;
    int xx = x, yy = y;
    if(map[x][y] == 'R'){
        xx++;
    } else if(map[x][y] == 'L'){
        xx--;
    } else if(map[x][y] == 'U'){
        yy--;
    } else{
        yy++;
    }
    dfs(xx, yy);
}

void rdfs(int x, int y){
    cout << "RDFS\n";
    cout << x  << ' ' << y << ':' << map[x][y] << '\n';
    if(y < 0 || x < 0 || y >= n || x >= n ){
        cout << "ROUTSIDE\n";
        return;
    }
    if(map[x][y] == 0){
        cout << "REMPTY\n";
        return;
    }
    if(map[x][y] == 'X'){
        cout << "RLOOP\n";
        return;
    }
    char dir = map[x][y];
    map[x][y] = 'X';
    cnt++;
    int xx = x, yy = y;
    if(dir == 'R'){
        xx--;
    } else if(dir == 'L'){
        xx++;
    } else if(dir == 'U'){
        yy++;
    } else{
        yy--;
    }
    rdfs(xx, yy);
}

void dfs_with_r(int x, int y){
    cout << "DFS_WITH_R\n";
    cout << x  << ' ' << y << ':' << map[x][y] << '\n';
    if(y < 0 || x < 0 || y >= n || x >= n ){
        cout << "OUTSIDE\n";
        return;
    }
    if(map[x][y] == 0){
        cout << "EMPTY\n";
        return;
    }
    if(map[x][y] == 'X'){
        cout << "LOOP\n";
        return;
    }
    char dir = map[x][y];
    
    rdfs(x, y);
    if(1 < x && map[x-1][y] == 'R'){
        dfs_with_r(x-1, y);
    }
    if(n-1 > x && map[x+1][y] == 'L'){
        dfs_with_r(x+1, y);
    }
    if(1 < y && map[x][y-1] == 'U'){
        dfs_with_r(x, y-1);
    }
    if(n-1 > y && map[x][y+1] == 'D'){
        dfs_with_r(x-1, y+1);
    }
    int xx = x, yy = y;
    if(dir == 'R'){
        xx++;
    } else if(dir == 'L'){
        xx--;
    } else if(dir == 'U'){
        yy--;
    } else{
        yy++;
    }
    dfs_with_r(xx, yy);
}

int main(){
    int q, x, y;
    char dir;
    // cout << (int)map[0][0];
    cin >> n >> q;
    for(int idx = 0; idx < q; idx++){
        cin >> y >> x >> dir;
        x--; 
        y--;
        map[x][y] = dir;
        int xx = x, yy = y;
        if(dir == 'R'){
            xx++;
        } else if(dir == 'L'){
            xx--;
        } else if(dir == 'U'){
            yy++;
        } else{
            yy--;
        }
        if(map[xx][yy] == 'X'){
            rdfs(x, y);
        } else{
            usable = true;
            for(int tx = 0; tx < n; tx++){
                for(int ty = 0; ty < n; ty++){
                    visit[tx][ty] = 0;
                }
            }
            dfs(x, y);
            cout << "USABLE: " << usable << '\n';
            if(!usable){
                dfs_with_r(x, y);
            }
        }
        if(1 < xx && 1 < yy && xx < n-1 && yy < n-1){
            if((map[xx][yy-1] == 'X' || map[xx][yy-1] == 'D') && 
               (map[xx][yy+1] == 'X' || map[xx][yy+1] == 'U') &&
               (map[xx+1][yy] == 'X' || map[xx+1][yy] == 'L') &&
               (map[xx-1][yy] == 'X' || map[xx-1][yy] == 'R')){
                cout << "SURROUNDED\n";
                dfs_with_r(xx, yy);
            }
        }
        
        cout << cnt << '\n';
    }

    return 0;
}