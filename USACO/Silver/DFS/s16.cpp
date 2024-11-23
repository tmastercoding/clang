#include <iostream>
#include <string>
using namespace std;

int n, k, map[100][10], visit[100][10];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1, 0,0};
int each[1000][2], eachCnt = 0;

void dfs(int y, int x){
    // map[y][x] = 0;
    each[eachCnt][0] = y;
    each[eachCnt++][1] = x;
    visit[y][x] = 1;

    int yy, xx;
    for(int i = 0; i < 4; i++){
        yy = y + dy[i];
        xx = x + dx[i];
        // cout << yy << xx << '\n';
        if(0 > yy || 0 > xx || yy >= n || xx >= 10){
            continue;
        }
        if(map[yy][xx] == map[y][x] && visit[yy][xx] == 0){
            dfs(yy, xx);
        }
    }
}

int main(){
    cin >> n >> k;

    string row;
    for(int y = 0; y < n; y++){
        cin >> row;
        for(int x = 0; x <10; x++){
            map[y][x] = row[x] - '0';
        }
    }
    // for(int y = 0; y < n; y++){
    //     for(int x = 0; x < 10; x++){
    //         cout << map[y][x] -'0';
    //     }
    //     cout << '\n';
    // }

    while(true){
        for(int y = 0; y < n; y++){
            for(int x = 0; x <10; x++){
                visit[y][x] = 0;
            }
        }

        eachCnt = 0;
        int cnt = 0;
        for(int y = 0; y < n; y++){
            for(int x = 0; x <10; x++){
                if(map[y][x] != 0 && visit[y][x] == 0){
                    // cout << y << x << '\n';
                    // cout << map[y][x] << '\n';
                    eachCnt = 0;
                    dfs(y, x);
                    if(eachCnt >= k){
                        cnt++;
                        for(int idx = 0; idx < eachCnt; idx++){
                            map[each[idx][0]][each[idx][1]] = 0;
                        }
                    }
                }
            }
        }
        // cout << cnt << '\n';

        // apply gravity
        for(int x = 0; x < 10; x++){
            for(int idx = 0; idx < n; idx++){
                int zero = -1;
                for(int y = n-1; y > -1 ; y--){
                    if(map[y][x] == 0){
                        zero = y;
                    }
                    // zero below and cur = coloured
                    if(zero > y && zero != -1 && map[y][x] != 0){
                        // cout << zero << '\n';
                        map[zero][x] = map[y][x];
                        zero = y;
                        map[y][x] = 0;
                    }
                }

            }
        }
        // cout << "___________________________\n";
        if(!cnt){
            break;
        }
    }
    for(int y = 0; y < n; y++){
        for(int x = 0; x < 10; x++){
            cout << map[y][x];
        }
        cout << '\n';
    }
    return 0;

}