// Walking Home
#include <iostream>
#include <string>
using namespace std;

int n, k, map[50][50];
int dx[2] = {0, 1};
int dy[2] = {1, 0};
int cnt = 0;

// prev = 0 = down, 1 = right
void dfs(int y, int x, int turns, int prev){
    // cout << y << ' ' << x <<  ' ' << turns << ' ' << prev << '\n';
    if(y == n-1 && x == n-1){
        cnt++;
    }
    int yy, xx;
    for(int idx = 0; idx < 2; idx++){
        int stored = turns;
        yy = y + dy[idx];
        xx = x + dx[idx];
        // cout << "temp: " << yy << xx << '\n';
        if(0 > yy || 0 > xx || yy >= n || xx >= n) continue;

        if(idx != prev && turns == k) continue;
        bool hasIncreased = false;
        if(idx != prev){
            // cout << yy << ' ' << xx << '\n';
            // cout << idx << ' ' << prev << '\n';
            hasIncreased = true;
            turns++;
        }

        // cout << (char)map[yy][xx] << '\n';
        if(map[yy][xx] == '.'){
            // cout <<"ASDf\n";
            dfs(yy, xx, turns, idx);
            // cout << idx;
            // turns = stored;
        } 
        if(hasIncreased || (x == 0 && y == 0)){
            turns--;
        }
        // cout << "_______\n";
    }
}


int main(){
    int t;
    cin >> t;
    for(int idx = 0; idx < t; idx++){
        cnt = 0;
        cin >> n >> k;
        string row;
        for(int y = 0; y < n; y++){
            cin >> row;
            for(int x = 0; x < n; x++){
                map[y][x] = row[x];
            }
        }

        dfs(0,0, 0, 0);
        cout << cnt << '\n';
    }
    return 0;
}