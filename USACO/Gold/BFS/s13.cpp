#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    string buffer;
    int visit[500][500][2];
    // switch, gravity
    char barn[500][500];
    queue<vector<int>> q;
    int startx, starty, endx, endy;
    for(int x = 0; x < n; x++){
        cin >> buffer;
        for(int y = 0; y < m; y++){
            visit[x][y][0] = 0;
            visit[x][y][1] = 0;
            barn[x][y] = buffer[y];
            if(buffer[y] == 'C'){
                startx = x, starty = y;
            } 
            if(buffer[y] == 'D'){
                endx = x, endy = y;
            } 
        }
    }

    q.push({startx, starty, 0});
    visit[startx][starty][0] = 1;
    while(!q.empty()){
        int x = q.front()[0], y = q.front()[1], g = q.front()[2];
        // cout << x << ' ' << y << ' ' << g << '\n';
        q.pop();
        if(g == 0){
            bool flag = true;
            int stop;
            for(int xx = x; xx < n; xx++){
                if(barn[xx][y] == '#'){
                    stop = xx-1;
                    flag = false;
                    break;
                }
            }
            if(!flag){
                if(!visit[stop][y][0]){
                    visit[stop][y][0] = visit[x][y][0];
                }
                if(!visit[stop][y][1]){
                    visit[stop][y][1] = visit[x][y][0]+1;
                    q.push({stop, y, 1});
                }                
                if(y+1 < m && !visit[stop][y+1][0] && barn[stop][y+1] != '#'){
                    visit[stop][y+1][0] = visit[x][y][0];
                    q.push({stop, y+1, 0});
                }
                if(y-1 > -1 && !visit[stop][y-1][0] && barn[stop][y-1] != '#'){
                    visit[stop][y-1][0] = visit[x][y][0];
                    q.push({stop, y-1, 0});
                }
            }

        } else{
            bool flag = true;
            int stop;
            for(int xx = x; xx > -1; xx--){
                if(barn[xx][y] == '#'){
                    stop = xx+1;
                    flag = false;
                    break;
                }
            }
            if(!flag){
                if(!visit[stop][y][1]){
                    visit[stop][y][1] = visit[x][y][1];
                }
                if(!visit[stop][y][0]){
                    visit[stop][y][0] = visit[x][y][1]+1;
                    q.push({stop, y, 0});
                }                
                if(y+1 < m && !visit[stop][y+1][1] && barn[stop][y+1] != '#'){
                    visit[stop][y+1][1] = visit[x][y][1];
                    q.push({stop, y+1, 1});
                }
                if(y-1 > -1 && !visit[stop][y-1][1] && barn[stop][y-1] != '#'){
                    visit[stop][y-1][1] = visit[x][y][1];
                    q.push({stop, y-1, 1});
                }
            }
        }

    }
    int minval = 100000;
    if(visit[endx][endy][0]){
        if(!visit[endx][endy][1]){
            minval = visit[endx][endy][0];
        } else{
            if(visit[endx][endy][0] < visit[endx][endy][1]){
                minval = visit[endx][endy][0];
            } else{
                minval = visit[endx][endy][1];
            }
        }
    } else if(visit[endx][endy][1]){
        if(!visit[endx][endy][0]){
            minval = visit[endx][endy][1];
        } else{
            if(visit[endx][endy][0] < visit[endx][endy][1]){
                minval = visit[endx][endy][0];
            } else{
                minval = visit[endx][endy][1];
            }
        }
    } else{
        minval = 0;
    }
    cout << minval-1<< '\n';
    return 0;
}