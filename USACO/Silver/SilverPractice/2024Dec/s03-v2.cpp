#include <iostream>
#include <vector>
using namespace std;

char map[1002][1002], visit[1002][1002];
vector<pair<int, int>> input;
vector<int> output;
pair<int, int> locat;
int n;
int cnt = 0;
// int dx[4] = {1,-1,0,0}, dy[4] = {0,0,1,-1};


void rdfs(int x, int y){
    if(visit[y][x])return;
    // cout << y << ' ' << x << '\n';
    // if(y < 0 || x < 0 || y >= n || x >= n ){
    //     return;
    // }
    cnt++;
    visit[y][x] = 1;
    if(y > 0){
        
        // cout << "UP: " << y-1 << ' ' << x << map[y-1][x] << '\n';
        if(map[y-1][x] == 'D' || map[y-1][x]==0){
            // cout << map[y-1][x]<< "asdf\n";
            rdfs(x, y-1);
        }
    } 
    if(y <= n){
        if(map[y+1][x] == 'U' || map[y+1][x] == 0){
            rdfs(x, y+1);
        }
    }
    if(x > 0){
        if(map[y][x-1] == 'R' || map[y][x-1] == 0){
            rdfs(x-1, y);
        }
    } 
    if(x <= n){
        if(map[y][x+1] == 'L' || map[y][x+1] == 0){
            rdfs(x+1, y);
        }
    }

}
void printmap(){

    for(int y = 0; y < n+2; y++){
        for(int x = 0; x < n+2; x++){
            if(map[y][x]){
                cout << map[y][x] << ' ';

            } else{
                cout <<"? ";
            }
        }
        cout << '\n';
    }
    for(int y = 0; y < n+2; y++){
        for(int x = 0; x < n+2; x++){
            cout << (int)visit[y][x] << ' ';

        }
        cout << '\n';
    }

}

int main(){
    int q, x, y;
    char dir;
    // cout << (int)map[0][0];
    cin >> n >> q;
    for(int idx = 0; idx < q; idx++){
        cin >> y >> x >> dir;
        locat.first = y;
        locat.second = x;
        input.push_back(locat);
        map[y][x] = dir;
    }

    rdfs(0, 0);
    output.push_back((n+2)*(n+2) - cnt);

    // cout << cnt << '\n';
    for(int idx = q-1; idx > -1; idx--){
        int yy = input[idx].first, xx = input[idx].second;
        map[yy][xx] = 0;
        bool usable = false;
        if(yy > 0){
            if(visit[yy-1][xx]){
                usable = true;
            }
        } 
        
        if(yy <= n){
            if(visit[yy+1][xx]){
                usable = true;
            }

        }
        if(xx > 0){
            if(visit[yy][xx-1]){
                usable = true;
            }
        } 
        
        if(xx <= n){
            if(visit[yy][xx+1]){
                usable = true;
            }
        }
        // printmap();
        // cout << "---------" << idx << '\n';
        if(usable){
            rdfs(xx, yy);
        }
        // cout << cnt << '\n';
        output.push_back((n+2)*(n+2) - cnt);
    }

    for(int idx = q-1; idx >-1; idx--){
        cout << output[idx] << '\n';
    }


    return 0;
}