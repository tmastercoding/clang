#include <iostream>
#include <queue>
using namespace std;

char lake[1501][1501];
int p[1500*1500], convert[1501][1501], visit[1501][1501];
int r, c;
int xpre = -1, ypre, xpost, ypost;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
queue<pair<int, int>> melt;

int Find(int x){
    if(x == p[x]) return x;
    return p[x] = Find(p[x]);
}

void Union(int a, int b){
    a = Find(a);
    b = Find(b);
    
    p[a] = b;
}

void dfs(int x, int y){
    visit[x][y] = 1;
    for(int i = 0; i < 4; i++){
        int yy = y+dy[i], xx = x+dx[i];
        if(yy > 0 && yy <= r && xx > 0 && xx <= c){
            if(lake[xx][yy] == '.' || lake[xx][yy] == 'L'){
                if(!visit[xx][yy]){
                    Union(convert[x][y], convert[xx][yy]);
                    dfs(xx, yy);
                } else{
                    Union(convert[x][y], convert[xx][yy]);
                }
            } else{
                if(visit[x][y] != 2){
                    visit[x][y] = 2;
                    melt.push({x, y});
                }
            }
        }
    }
}
int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    // freopen("labudovi.i08", "r", stdin);

    cin >> r >> c;
    int idx = 0;
    for(int y = 1; y <= r; y++){
        for(int x = 1; x <= c; x++){
            cin >> lake[x][y];
            p[idx] = idx;
            convert[x][y] = idx++;
            visit[x][y] = 0;
            if(lake[x][y] == 'L'){
                if(xpre == -1){
                    xpre = x;
                    ypre = y;
                } else{
                    xpost = x;
                    ypost = y;
                }
            }
        }
    }

    queue<pair<int, int>> q, temp, check;

    for(int x = 1; x <= c; x++){
        for(int y = 1; y <= r; y++){
            if(!visit[x][y] && lake[x][y] != 'X'){
                dfs(x, y);
            }
        }
    }

    int x, y;
    
    // while(!q.empty()){
    //     x = q.front().first;
    //     y = q.front().second;
    //     q.pop();
    //     visit[x][y] = 1;
    //     int xx = x, yy = y;
    //     for(int i = 0; i < 4; i++){
    //         xx = x+ dx[i], yy = y + dy[i];
    //         if(1 > xx || xx > c || 1 > yy || yy > r || visit[xx][yy]) continue;
    //         if(lake[xx][yy] != 'X'){
    //             q.push({xx, yy});
    //             Union(convert[x][y], convert[xx][yy]);
    //         } else{
    //             if(visit[x][y] != 2){
    //                 melt.push({x, y});
    //                 visit[x][y] = 2;
    //             }
    //         }
    //     }
    // }
    int t = 0;
    while(true){
        while(!check.empty()){
            x = check.front().first;
            y = check.front().second;
            check.pop();
            int xx = x, yy = y;
            for(int i = 0; i < 4; i++){
                xx = x + dx[i], yy = y +dy[i];
                if(1 > xx || xx > c || 1 > yy || yy > r) continue;
                if(lake[xx][yy] != 'X'){
                    Union(convert[x][y], convert[xx][yy]);
                }
            }
        }
        if(Find(convert[xpre][ypre]) == Find(convert[xpost][ypost])){
            // cout << "REGULAR\n";
            break;
        }
        
        // cout <<t << ";\n";
        while(!melt.empty()){
            x = melt.front().first;
            y = melt.front().second;
            melt.pop();
            // cout << x << ' ' << y << '\n';
            visit[x][y] = 2;
            int xx = x, yy = y;
            for(int i = 0; i < 4; i++){
                xx = x + dx[i], yy = y +dy[i];
                if(1 > xx || xx > c || 1 > yy || yy > r) continue;
                if(lake[xx][yy] == 'X'){
                    temp.push({xx, yy});
                    Union(convert[x][y], convert[xx][yy]);
                    lake[xx][yy] = '.';
                }
            }
        }

        t++;
        while(!temp.empty()){
            melt.push({temp.front().first, temp.front().second});
            check.push({temp.front().first, temp.front().second});
            temp.pop();
        }
    }

    cout << t << '\n';
    return 0;
}