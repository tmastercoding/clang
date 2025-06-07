#include <iostream>
using namespace std;

int n, b;
int snow[500], boots[500][2], visit[500] = {}, mindis = 500;

void dfs(int cur, int bdx){
    // if(mindis == 500){
    //     cout << snow[cur] << ' ' << boots[bdx][0] << ':' << boots[bdx][1] << '\n';
    // }
    if(visit[cur]!= -1 && visit[cur] <= bdx ) return;
    visit[cur] = bdx;
    if(cur < n-1){
        for(int i = bdx; i < b; i++){
            if(boots[i][0] < snow[cur]) continue;
            // cout << "b: " << bdx << '\n';
            int to = boots[i][1]+cur;
            if(to > n-1) to = n-1;
            for(int j = to; j > cur; j--){
                if(snow[j] <= boots[i][0]){
                    dfs(j,i);
                }
            }
        }
    } else{
        if(bdx < mindis){

            // cout << "asdf\n";
            mindis = bdx;
        }
    }
}

int main(){
    // freopen("snowboots.in", "r", stdin);
    // freopen("snowboots.out", "w", stdout);
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n >> b;
    for(int i = 0; i < n; i++){
        cin >> snow[i];
        visit[i] = -1;
    }

    for(int i = 0; i < b; i++){
        cin >> boots[i][0] >> boots[i][1];
    }
    // boots[b][0] = 0;
    // boots[b][1] = 1;
    dfs(0, 0);
    cout << mindis << '\n';
    return 0;
}