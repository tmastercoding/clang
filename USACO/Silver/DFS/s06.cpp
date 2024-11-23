// 적록색약 10026
#include <iostream>
#include <string>
using namespace std;

int n;
char nMap[100][100], bMap[100][100];
int nVisit[100][100], bVisit[100][100];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int ncnt = 0, bcnt = 0;

void dfs(int y, int x, int type, char colour){
    if(type == 0){
        nVisit[y][x] = 1;
    } else{
        bVisit[y][x] = 1;
    }

    for(int i = 0; i < 4; i++){
        int yy = y + dy[i];
        int xx = x + dx[i];

        if(xx < 0 || yy < 0 || yy >= n || xx >= n) continue;
        if(type == 0){
            if(nMap[yy][xx] == colour && nVisit[yy][xx] == 0){
                dfs(yy, xx, type, colour);
            } 
        } else{
            if(bMap[yy][xx] == colour && bVisit[yy][xx] == 0){
                dfs(yy, xx, type, colour);
            } 
        }
    }
}

int main(){
    cin >> n;
    string row;
    for(int y = 0; y < n; y++){
        cin >> row;
        for(int x = 0; x < n; x++){
            nMap[y][x] = row[x];
            bMap[y][x] = row[x];
            if(row[x] == 'G'){
                bMap[y][x] = 'R';
            }
        }
    }

    for(int y = 0; y < n; y++){
        for(int x = 0; x < n; x++){
            if(nVisit[y][x] == 0){
                dfs(y, x, 0, nMap[y][x]);
                ncnt++;
            }
        }
    }

    for(int y = 0; y < n; y++){
        for(int x = 0; x < n; x++){
            if(bVisit[y][x] == 0){
                dfs(y, x, 1, bMap[y][x]);
                bcnt++;
            }
        }
    }
    cout << ncnt << ' ' << bcnt << '\n';
    return 0;
}