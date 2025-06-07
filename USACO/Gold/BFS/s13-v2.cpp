#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    string buffer;
    int visit[500][500];
    // switch, gravity
    char barn[500][500];
    queue<vector<int>> q;
    int startx, starty, endx, endy;
    for(int x = 0; x < n; x++){
        cin >> buffer;
        for(int y = 0; y < m; y++){
            visit[x][y] = 0;
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
    visit[startx][starty] = 1;
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
                for(int yy = y-1; yy > -1 ; yy--){
                    if(barn[stop+1][yy] == '#' && barn[stop][yy] != '#'){
                        if(!visit[stop][yy]){
                            visit[stop][yy] = visit[x][y];
                            q.push({stop, yy, g});
                        }
                        for(int xx = stop; xx > -1; xx--){
                            if(barn[xx][yy] == '#'){
                                if(!visit[xx+1][yy]){
                                    visit[xx+1][yy] = visit[x][y]+1;
                                    q.push({xx+1, yy, 1});
                                }
                                break;
                            }
                            if(xx == endx && yy == endy && !visit[xx][yy]){
                                visit[xx][yy] = visit[x][y]+1;
                            }
                        }
                    } else{
                        break;
                    }
                }
                for(int yy = y; yy < m ; yy++){
                    if(barn[stop+1][yy] == '#' && barn[stop][yy] != '#'){
                        if(!visit[stop][yy]){
                            visit[stop][yy] = visit[x][y];
                            q.push({stop, yy, g});
                        }
                        for(int xx = stop; xx > -1; xx--){
                            if(barn[xx][yy] == '#'){
                                // cout << xx << ' ' << yy << '\n';
                                if(!visit[xx+1][yy]){
                                    visit[xx+1][yy] = visit[x][y]+1;
                                    q.push({xx+1, yy, 1});
                                }
                                break;
                            }
                            if(xx == endx && yy == endy && !visit[xx][yy]){
                                visit[xx][yy] = visit[x][y]+1;
                            }
                        }
                    } else{
                        break;
                    }
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
                for(int yy = y-1; yy > -1 ; yy--){
                    if(barn[stop-1][yy] == '#' && barn[stop][yy] != '#'){
                        if(!visit[stop][yy]){
                            visit[stop][yy] = visit[x][y];
                            q.push({stop, yy, g});
                        }
                        for(int xx = stop; xx < n; xx++){
                            if(xx == endx && yy == endy && !visit[xx][yy]){
                                visit[xx][yy] = visit[x][y]+1;
                            }
                            if(barn[xx][yy] == '#'){
                                if(!visit[xx-1][yy]){
                                    visit[xx-1][yy] = visit[x][y]+1;
                                    q.push({xx-1, yy, 0});
                                }
                                break;
                            }
                        }
                    } else{
                        break;
                    }
                }
                for(int yy = y; yy < m ; yy++){
                    if(barn[stop-1][yy] == '#' && barn[stop][yy] != '#'){
                        if(!visit[stop][yy]){
                            visit[stop][yy] = visit[x][y];
                            q.push({stop, yy, g});
                        }
                        for(int xx = stop; xx < n; xx++){
                            if(xx == endx && yy == endy && !visit[xx][yy]){
                                visit[xx][yy] = visit[x][y]+1;
                            }
                            if(barn[xx][yy] == '#'){
                                if(!visit[xx-1][yy]){
                                    visit[xx-1][yy] = visit[x][y]+1;
                                    q.push({xx-1, yy, 0});
                                }
                                break;
                            }
                        }
                    } else{
                        break;
                    }
                }
            }
        }

    }
    // for(int x = 0; x < n; x++){
    //     for(int y = 0; y < m; y++){
    //         cout << visit[x][y] << ' ';
    //     }
    //     cout << '\n';
    // }
    cout << visit[endx][endy]-1<< '\n';
    return 0;
}