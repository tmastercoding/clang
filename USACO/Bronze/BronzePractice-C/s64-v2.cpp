#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int x, y, map[1000][1000];
    for(int y = 0; y < 1000; y++){
        for(int x = 0; x < 1000; x++){
            map[y][x] = -1;
        }
    }
    int tot = 0;
    for(int idx = 0; idx < n; idx++){
        cin >> x >> y;
        map[y][x] = 0;

        int dx[4] = {0, 0, -1, 1};
        int dy[4] = {-1, 1, 0, 0};
        int yy, xx, cnt = 0;
        for(int jdx = 0; jdx < 4; jdx++){
            yy = y + dy[jdx];
            xx = x + dx[jdx];
            if( 0 > yy || yy > 999 || 0 > xx || xx > 999) continue;
            if(map[yy][xx] != -1){
                map[yy][xx]++;
                cnt++;
                if(map[yy][xx] == 3){
                    tot++;
                } else if(map[yy][xx] > 3){
                    tot--;
                }
            }
        }
        map[y][x] = cnt;
        cout << tot<<'\n';
    }

    
    return 0;
}