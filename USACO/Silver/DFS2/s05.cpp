#include <iostream>
#include <vector>
using namespace std;

int main(){
    // cin.tie(NULL);
    // ios::sync_with_stdio(false);
    // freopen("cruise.in", "r", stdin);
    // freopen("cruise.out", "w", stdout);
    long long n, m, k;
    int adj[1002][2];
    char side;
    int d[500];
    
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++){
        cin >> adj[i][0] >> adj[i][1];
    }
    
    for(int i = 0; i < m; i++){
        cin >> side;
        if(side == 'L'){
            d[i] = 0;
        } else{
            d[i] = 1;
        }
    }

    int cur = 1;
    int visit[1001] = {};
    int repeat = 0;
    vector<int> path = {1};
    while(true){
        for(int i = 0; i < m; i++){
            cur = adj[cur][d[i]];
        }
        if(visit[cur]){
            repeat = cur;
            break;
        }
        visit[cur] = path.size();
        path.push_back(cur);
    }

    // for(int i = 0; i < path.size(); i++){
    //     cout << path[i] << '\n';
    // }
    
    int term = k;
    if(k > path.size()){
        k -= visit[repeat];
        term = k %( path.size()-visit[repeat]);
        term += visit[repeat];
    }

    cout << path[term] << '\n';
    return 0;
}