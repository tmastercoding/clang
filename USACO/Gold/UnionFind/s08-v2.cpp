#include <iostream>
#include <queue>
using namespace std;

char lake[1501][1501];
int p[1500*1500], convert[1501][1501], visit[1501][1501];
int r, c;
int xpre = -1, ypre, xpost, ypost;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int Find(int x){
    if(x == p[x]) return x;
    return p[x] = Find(p[x]);
}

void Union(int a, int b){
    a = Find(a);
    b = Find(b);
    
    p[a] = b;
}

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    freopen("labudovi.i08", "r", stdin);

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

    queue<pair<int, int>> q, melt, temp;
    q.push({xpre, ypre});
    q.push({xpost, ypost});
    int x, y;
    
    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();
        visit[x][y] = 1;
        int xx = x, yy = y;
        for(int i = 0; i < 4; i++){
            xx = x+ dx[i], yy = y + dy[i];
            if(1 > xx || xx > c || 1 > yy || yy > r || visit[xx][yy]) continue;
            if(lake[xx][yy] != 'X'){
                q.push({xx, yy});
                Union(convert[x][y], convert[xx][yy]);
            } else{
                melt.push({x, y});
            }
        }
    }

    for(int x = 1; x <= c; x++){
        for(int y = 1; y <= r; y++){
            if(!visit[x][y] && lake[x][y] != 'X'){
                melt.push({x, y});
            }
        }
    }
    int t = 0;
    while(true){
        if(Find(convert[xpre][ypre]) == Find(convert[xpost][ypost])){
            cout << "REGULAR\n";
            break;
        }
        cout <<t << ";\n";
        bool didmelt = false;
        while(!melt.empty()){
            x = melt.front().first;
            y = melt.front().second;
            melt.pop();
            if(visit[x][y] == 2) continue;
            // cout << x << ' ' << y << '\n';
            visit[x][y] = 2;
            int xx = x, yy = y;
            for(int i = 0; i < 4; i++){
                xx = x + dx[i], yy = y +dy[i];
                if(1 > xx || xx > c || 1 > yy || yy > r) continue;
                if(visit[xx][yy] == 2){
                    if(Find(convert[xpre][ypre]) == Find(convert[xpost][ypost])){
                        temp.push({xx, yy});
                        Union(convert[x][y], convert[xx][yy]);
                        continue;
                    }
                    temp.push({xx, yy});
                    Union(convert[x][y], convert[xx][yy]);
                    
                    if(Find(convert[xpre][ypre]) == Find(convert[xpost][ypost])){
                        didmelt = true;
                        break;
                    }
                } else{
                    temp.push({xx, yy});
                    Union(convert[x][y], convert[xx][yy]);
                }
            }
        }
        if(didmelt){
            cout << "EARLY\n";
            break;
        }
        t++;
        while(!temp.empty()){
            melt.push({temp.front().first, temp.front().second});
            temp.pop();
        }
    }

    cout << t << '\n';
    return 0;
}