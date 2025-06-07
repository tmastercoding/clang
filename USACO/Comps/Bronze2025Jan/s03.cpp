#include <iostream>
#include <string>
using namespace std;


int main(){
    int t = 0;
    cin >> t;
    for(int idx = 0; idx < t; idx++){
        int n, a, b;
        int map[1000][1000];
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
            }
        }

        // for(int y = 0; y < n; y++){
        //     for(int x = 0; x < n; x++){
        //         cout << map[y][x] << ' ';
        //     }
        //     cout << '\n';
        // }

        long long cnt = 0;
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
        // cout << cnt << '\n';
        for(int y = 0; y < n; y++){
            for(int x = 0; x < n; x++){
                if(map[y][x] == 2){
                    cnt = -1;
                    break;
                }
            }
        }
        if(cnt == -1){
            cout << cnt <<'\n';
        } else{
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
            // cout << cnt << '\n';
            // for(int y = 0; y < n; y++){
            //     for(int x = 0; x < n; x++){
            //         cout << map[y][x] << ' ';
            //     }
            //     cout << '\n';
            // }
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
            cout << cnt << '\n';
        }
    }

    return 0;
}