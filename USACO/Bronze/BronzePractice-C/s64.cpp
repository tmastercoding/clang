#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int x, y, map[1000][1000], cows[100000][2];

    for(int idx = 0; idx < n; idx++){
        cin >> x >> y;
        map[y][x] = 1;
        cows[idx][0] = y;
        cows[idx][1] = x;

        int dx[4] = {0, 0, -1, 1};
        int dy[4] = {-1, 1, 0, 0};
        int tot = 0;
        for(int i = 0; i < idx; i++){
            int cnt = 0;
            for(int jdx = 0; jdx < 4; jdx++){
                y = cows[i][0] + dy[jdx];
                x = cows[i][1] + dx[jdx];
                if( 0 > y || y > 999 || 0 > x || x > 999) continue;
                if(map[y][x] == 1){
                    cnt++;
                }
            }
            if(cnt == 3){
                tot++;
            }
        }
        cout << tot<<'\n';
    }

    
    return 0;
}