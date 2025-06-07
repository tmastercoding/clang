#include <iostream>
#include <set>
#include <vector>
using namespace std;

char lake[1600][1600];
int visit[1600][1600], convert[1600][1600], p[3000000];
int r, c;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int prex = -1, prey, postx, posty, idx = 0;
set<vector<int>> touch, temp; 

int Find(int x){
    if(x == p[x]) return x;
    return p[x] = Find(p[x]);
}

void Union(int a, int b){
    a = Find(a);
    b = Find(b);
    // if(a == b) return;
    p[a] = b;
}

void dfs(int y, int x, int side){
    visit[y][x] = 1;
    for(int i = 0; i < 4; i++){
        int yy = y+dy[i], xx = x+dx[i];
        if(yy > -1 && yy < r && xx > -1 && xx < c){
            if(lake[yy][xx] == '.' || lake[yy][xx] == 'L'){
                if(!visit[yy][xx]){
                    Union(convert[y][x], convert[yy][xx]);
                    dfs(yy, xx, side);
                } else{
                    Union(convert[y][x], convert[yy][xx]);
                    // if(side == 0){
                    //     if(Find(convert[yy][xx]) == Find(convert[posty][postx])){
                    //     }
                    // } else{
                    //     if(Find(convert[yy][xx]) == Find(convert[prey][prex])){
                    //         Union(convert[y][x], convert[yy][xx]);
                    //     }
                    // }
                }
            } else{
                if(!visit[yy][xx]){
                    temp.insert({yy, xx, side, y, x});
                }
            }
        }
    }
}

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    // freopen("labudovi.i05", "r", stdin);
    // freopen("mootube.out", "w", stdout);    
    cin >> r >> c;

    for(int y = 0; y < r; y++){
        for(int x = 0; x < c; x++){
            cin >> lake[y][x];
            // cout << lake[y][x] << ' ';
            visit[y][x] = 0;
            p[idx] = idx;
            convert[y][x] = idx++;
            if(lake[y][x] == 'L'){
                if(prex == -1){
                    prex = x, prey = y;
                } else{
                    postx = x, posty = y;
                }
            }
        }
        // cout << '\n';
    }
    
    dfs(prey, prex, 0);
    dfs(posty, postx, 1);
    for(int y = 0; y < r; y++){
        for(int x = 0; x < c; x++){
            if(!visit[y][x] && lake[y][x] == '.'){
                dfs(y, x, -1);
            }
        }
    }
    
    int day = 0;
    touch = temp;
    temp.clear();
    // for(auto m: touch){
    //     cout << m[0] << ' ' << m[1] << ' ' << m[2] << '\n';
    // }
    while(true){
        if(Find(convert[prey][prex]) == Find(convert[posty][postx])) break;
        while(!touch.empty()){
            int y = (*(touch.begin()))[0];
            int x = (*(touch.begin()))[1];
            Union(convert[y][x], convert[(*(touch.begin()))[3]][(*(touch.begin()))[4]]); 
            
            lake[y][x] = '.';
            dfs(y, x, (*(touch.begin()))[2]);
            touch.erase(touch.begin());
        }
        touch = temp;
        temp.clear();
        day++;

        // cout << "-------------" << day << '\n';
        // for(int y = 0; y < r; y++){
        //     for(int x = 0; x < c; x++){
        //         cout << lake[y][x] << ' ';
        //     }
        //     cout << '\n';
        // }
    }

    cout << day << '\n';
    return 0; 
}