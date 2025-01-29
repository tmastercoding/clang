#include <iostream>
#include <string>
using namespace std;

char map[1500][1500] = {};
int visit[1500][1500] = {};
int feedVer[1500] = {};
int feedHoz[1500] = {};
int n;
int curY, curX;

void dfs(int y, int x){
    if(n <= y || n <= x){
        curY = y;
        curX = x;
        return;
    }
    if(map[y][x] == 'R'){
        dfs(y,x+1);
    } else{
        dfs(y+1, x);
    }
}

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    string buffer;
    cin >> n;
    for(int y = 0; y < n; y++){
        cin >> buffer;
        for(int x = 0; x < n; x++){
            map[y][x] = buffer[x];
        }
        cin >> feedVer[y];
    }
    for(int x = 0; x < n; x++){
        cin >> feedHoz[x];
    }
    int q;
    int changeY, changeX;
    cin >> q;
    for(int day = 0; day <= q; day++){
        if(day > 0){
            cin >> changeY >> changeX;
            if(map[changeY-1][changeX-1] == 'R'){
                map[changeY-1][changeX-1] = 'D';
            } else{
                map[changeY-1][changeX-1] = 'R';
            }
        }
        int sum = 0;
        for(int y = 0; y < n; y++){
            for(int x = 0; x < n; x++){
                dfs(y, x);
                // cout << curY << ' ' << curX << '\n';
                if(curX >= n){
                    sum+= feedVer[curY];
                } else{
                    sum += feedHoz[curX];
                }
            }
        }
        cout << sum << '\n';

    }
    return 0;
}