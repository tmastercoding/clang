#include <iostream>
#include <string>
using namespace std;

char map[1500][1500] = {};
int val[1500][1500] = {};
int visit[1500][1500] = {};
int feedVer[1500] = {};
int feedHoz[1500] = {};
int n;
int curY, curX, visitCnt = 0;
int sum = 0;
bool endByVisit = false;

void dfs(int y, int x){
    if(n <= y || n <= x){
        curY = y;
        curX = x;
        return;
    }
    if(visit[y][x]){
        curY = y;
        curX = x;
        endByVisit = true;
        return;
    }
    visit[y][x] =1;
    if(map[y][x] == 'R'){
        dfs(y,x+1);
    } else{
        dfs(y+1, x);
    }
}

void rdfs(int y, int x, int replace, bool flag){
    // cout << y <<" " << x << '\n';
    if(0 > y || 0 > x){
        return;
    }
    if(!flag && val[y][x]){
        return;
    }
    sum -= val[y][x];
    val[y][x] = replace;
    sum+= replace;

    if(y > 0){
        if(map[y-1][x] == 'D'){
            rdfs(y-1,x, replace, flag);

        }
    }
    if(x > 0){
        if(map[y][x-1] == 'R'){
            rdfs(y,x-1, replace, flag);

        }
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


    for(int y = 0; y < n; y++){
        for(int x = 0; x < n; x++){
            if(visit[y][x]){
                continue;
            }
            endByVisit = false;
            visitCnt = 0;
            dfs(y, x);

            // cout << curY << ' ' << curX << '\n';
            if(endByVisit){
                rdfs(curY, curX, val[curY][curX], false);
            } else if(curX >= n){
                rdfs(curY, curX-1, feedVer[curY], false);
            } else{
                rdfs(curY-1, curX, feedHoz[curX], false);
            }
            // for(int y = 0; y < n; y++){
            //     for(int x = 0; x < n; x++){
            //         cout << val[y][x] << ' ';
            //     }
            //     cout << '\n';
            // }
        }
    }

    cout << sum << '\n';
    
    int q;
    int changeY, changeX;
    cin >> q;
    for(int day = 0; day < q; day++){
        cin >> changeY >> changeX;
        int replace;
        if(map[changeY-1][changeX-1] == 'R'){
            map[changeY-1][changeX-1] = 'D';
            if(changeY-1 < n-1){
                replace = val[changeY][changeX-1];
            } else{
                replace = feedHoz[changeX-1];
            }
        } else{
            map[changeY-1][changeX-1] = 'R';
            if(changeX-1 < n-1){
                replace = val[changeY-1][changeX];
            } else{
                replace = feedVer[changeY-1];
            }
        }
        // cout << replace << '\n';
        rdfs(changeY-1, changeX-1, replace, true);
        cout << sum << '\n'; 

    }
    return 0;
}