    #include <iostream>
    #include <string>
    #include <queue>
    #include <vector>
    using namespace std;

    int main(){
        int w, h;
        cin >> w >> h;
        char pasture[100][100];
        int visit[100][100][4];
        string buffer;
        int cx = -1, cy, endx, endy;
        for(int y = 0; y < h; y++){
            cin >> buffer;
            for(int x = 0; x < w; x++){
                pasture[x][y] = buffer[x];
                visit[x][y][0] = 0;           
                visit[x][y][1] = 0;           
                visit[x][y][2] = 0;           
                visit[x][y][3] = 0;           
                if(pasture[x][y] == 'C'){
                    if(cx == -1){
                        cx = x, cy = y;
                    } else{
                        endx = x, endy = y;
                    }
                }
            }
        }

        // x, y, dir
        queue<vector<int>> q;
        // UDLR
        int dx[4] = {0, 0, -1, 1};
        int dy[4] = {-1, 1, 0, 0};
        q.push({cx, cy, 0});
        q.push({cx, cy, 1});
        q.push({cx, cy, 2});
        q.push({cx, cy, 3});
        visit[cx][cy][0] = 1;
        visit[cx][cy][1] = 1;
        visit[cx][cy][2] = 1;
        visit[cx][cy][3] = 1;

        while(!q.empty()){
            int x = q.front()[0], y = q.front()[1], dir = q.front()[2];
            q.pop();
            // cout << x << ' ' << y << ' ' << dir<< '\n';
            if(x == endx && y == endy){
                cout << visit[x][y][dir]-1 << '\n';
                break;
            }
            // continue dir
            int xx = x+dx[dir], yy = y+dy[dir];
            while(xx > -1 && xx < w && yy > -1 && yy < h && pasture[xx][yy] != '*'){
                if(!visit[xx][yy][dir]){
                    visit[xx][yy][dir] = visit[x][y][dir];
                    q.push({xx, yy, dir});
                }
                xx += dx[dir], yy += dy[dir];
            }
            xx = x+dx[dir], yy = y+dy[dir];
            if(xx > -1 && xx < w && yy > -1 && yy < h){
                if(pasture[xx][yy] != '*'){
                    if(dir == 0 || dir == 1){
                        if(!visit[xx][yy][2]){
                            visit[xx][yy][2] = visit[x][y][dir]+1;
                            q.push({xx, yy, 2});
                        }
                        if(!visit[xx][yy][3]){
                            visit[xx][yy][3] = visit[x][y][dir]+1;
                            q.push({xx, yy, 3});
                        }
                    } else{
                        if(!visit[xx][yy][0]){
                            visit[xx][yy][0] = visit[x][y][dir]+1;
                            q.push({xx, yy, 0});
                        }
                        if(!visit[xx][yy][1]){
                            visit[xx][yy][1] = visit[x][y][dir]+1;
                            q.push({xx, yy, 1});
                        }
                    }
                }
            }
            // change 

        }
        return 0;
    }