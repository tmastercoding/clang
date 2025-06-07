#include <iostream>
#include <string>
using namespace std;


int main(){
    int t = 0;
    cin >> t;
    for(int idx = 0; idx < t; idx++){
        int n, a, b;
        int map[1000][1000], map2[1000][1000];
        char color;
        string buffer;
        cin >> n >> a >> b;
        for(int y = 0; y < n; y++){
            cin >> buffer;
            for(int x = 0; x < n; x++){
                color = buffer[x];
                if(color == 'W') map[y][x] = 0;
                if(color == 'G') map[y][x] = 1;
                if(color == 'B') map[y][x] = 2;
                if(color == 'W') map2[y][x] = 0;
                if(color == 'G') map2[y][x] = 1;
                if(color == 'B') map2[y][x] = 2;
            }
        }

        int cnt = 0;
        // first black
        int dx, dy;
        for(int y = 0; y < n; y++){
            for(int x = 0; x < n; x++){
                if(map[y][x] == 2){
                    // dx, dy = original pos
                    dy = y-b;
                    dx = x-a;
                    // cout << dy << ' ' << dx << '\n';
                    if(dx == x && dy == y){
                        map[dy][dx] -= 2;
                        cnt++;
                        continue;
                    }
                    if(-1 < dx && dx < n && -1 < dy && dy < n){
                        if(map[dy][dx] > 0){
                            map[dy][dx]--;
                            map[y][x]--;
                            cnt++;
                        }
                    }
                }
            }
        }
        // then gray
        for(int y = 0; y < n; y++){
            for(int x = 0; x < n; x++){
                if(map[y][x] == 1){
                    // dx, dy = original pos
                    dy = y-b;
                    dx = x-a;
                    // cout << dy << ' ' << dx << '\n';
                    if(dx == x && dy == y){
                        map[dy][dx] -= 1;
                        cnt++;
                        continue;
                    }
                    if(-1 < dx && dx < n && -1 < dy && dy < n){
                        if(map[dy][dx] > 0){
                            map[dy][dx]--;
                            map[y][x]--;
                            cnt++;
                        }
                    }
                }
            }
        }
        for(int y = 0; y < n; y++){
            for(int x = 0; x < n; x++){
                if(map[y][x] == 2){
                    cnt = -1;
                    break;
                }
                cnt += map[y][x];
            }
        }
        if(cnt > n*n) cnt = -1;
        int op1 = cnt, op2;
        cnt = 0;

        // first gray
        for(int y = 0; y < n; y++){
            for(int x = 0; x < n; x++){
                if(map2[y][x] == 1){
                    // dx, dy = original pos
                    dy = y-b;
                    dx = x-a;
                    // cout << dy << ' ' << dx << '\n';
                    if(dx == x && dy == y){
                        map2[dy][dx] -= 1;
                        cnt++;
                        continue;
                    }
                    if(-1 < dx && dx < n && -1 < dy && dy < n){
                        if(map2[dy][dx] > 0){
                            map2[dy][dx]--;
                            map2[y][x]--;
                            cnt++;
                        }
                    }
                }
            }
        }
        for(int y = 0; y < n; y++){
            for(int x = 0; x < n; x++){
                if(map2[y][x] == 2){
                    // dx, dy = original pos
                    dy = y-b;
                    dx = x-a;
                    // cout << dy << ' ' << dx << '\n';
                    if(dx == x && dy == y){
                        map2[dy][dx] -= 2;
                        cnt++;
                        continue;
                    }
                    if(-1 < dx && dx < n && -1 < dy && dy < n){
                        if(map2[dy][dx] > 0){
                            map2[dy][dx]--;
                            map2[y][x]--;
                            cnt++;
                        }
                    }
                }
            }
        }
        for(int y = 0; y < n; y++){
            for(int x = 0; x < n; x++){
                if(map2[y][x] == 2){
                    cnt = -1;
                    break;
                }
                cnt += map2[y][x];
            }
        }
        op2 = cnt;
        if(op1 < op2){
            if(op1 == -1){
                cout << op2 << '\n';
            } else{
                cout << op1 << '\n';
            }
        } else{
            if(op2 == -1){
                cout << op1 << '\n';
            } else{
                cout << op2 << '\n';
            }
        }
    }

    return 0;
}