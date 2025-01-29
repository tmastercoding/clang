#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int main(){
    int n, k, l;
    int map[101][101] = {}, x, y;
    pair<int, char> commands[101];
    deque<pair<int, int>> snake;
    snake.push_front({1,1});
    cin >> n >> k;
    for(int i = 0; i < k; i++){
        cin >> x >> y;
        map[x][y] = 1;
    }

    map[1][1] = 2;
    cin >> l;
    for(int i = 0; i < l; i++){
        cin >> commands[i].first >> commands[i].second;
    }
    sort(commands, commands+l);

    int ldx = 0, time = 1;
    int dx = 1, dy = 0;
    snake.push_front({snake.front().first+dy, snake.front().second+dx});
    while(true){
        // cout << snake.front().first << ' ' << snake.front().second << '\n';
        // for(int x = 1; x <= n; x++){
        //     for(int y = 1; y <= n; y++){
        //         cout << map[x][y] << ' ';
        //     }
        //     cout << '\n';
        // }
        if(snake.front().first < 1|| snake.front().first > n || snake.front().second < 1 || snake.front().second > n){
            break;
        }
        if( map[snake.front().first][snake.front().second] == 2){
            break;
        }
        if(map[snake.front().first][snake.front().second] == 0){
            map[snake.back().first][snake.back().second] = 0;
            snake.pop_back();
        }
        map[snake.front().first][snake.front().second] = 2;

        if(commands[ldx].first == time){
            if(dx == 1){
                if(commands[ldx].second == 'L') dx = 0, dy = -1;
                if(commands[ldx].second == 'D') dx = 0, dy = 1;
            } else if(dx == -1){
                if(commands[ldx].second == 'L') dx = 0, dy = 1;
                if(commands[ldx].second == 'D') dx = 0, dy = -1;
            } else if(dy == 1){
                if(commands[ldx].second == 'L') dx = 1, dy = 0;
                if(commands[ldx].second == 'D') dx = -1, dy = 0;
            } else{
                if(commands[ldx].second == 'L') dx = -1, dy = 0;
                if(commands[ldx].second == 'D') dx = 1, dy = 0;
            }
            ldx++;
        }
        
        snake.push_front({snake.front().first+dy, snake.front().second+dx});
        time++;
    }
    cout << time << '\n';

    return 0;
}