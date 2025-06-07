#include <iostream>
#include <string>
using namespace std;


int main(){
    int t = 0;
    cin >> t;
    for(int idx = 0; idx < t; idx++){
        int n, a, b;
        int map[1001][1001], visit[1001][1001];
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
        for(int y = n-1; y > -1; y--){
            for(int x = n-1; x > -1; x--){
                if(map[y][x]){
                    // dx, dy = original pos
                    dy = y-b;
                    dx = x-a;
                    
                    if(-1 < dx && dx < n && -1 < dy && dy < n){
                        if(map[dy][dx] > 0 && !visit[dy][dx]){
                            visit[dy][dx] = 1;
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
                } else if(map[y][x] == 1){
                    if(visit[y][x]){
                        cnt = -1;
                        break;
                    } else{
                        cnt++;
                    }
                }
            }
        }
        cout << cnt << '\n';
    }

    return 0;
}