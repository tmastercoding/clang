#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(){
    int t;
    cin >> t;
    for(int c = 0; c < t; c++){

        int k, m, p;
        cin >> k >> m >> p;
        int in[1001] = {}, maxOrder[1001][2] = {}, order[1001] = {};
        vector<int> adj[1001];
        queue<int> q;
        int a, b;
    
        for(int i = 0; i < p; i++){
            cin >> a >> b;
            in[b]++;
            adj[a].push_back(b);
        }
    
        for(int i = 1; i <= m; i++){
            maxOrder[i][0] = 0;
            maxOrder[i][1] = 0;
            if(!in[i]){
                q.push(i);
                order[i] = 1;
            } 
        }
        
        while(!q.empty()){
            int cur = q.front();
            // cout << cur << '\n';
            q.pop();
            for(int nxt: adj[cur]){
                if(maxOrder[nxt][0] < order[cur]){
                    maxOrder[nxt][0] = order[cur];
                    maxOrder[nxt][1] = 1;
                } else if(maxOrder[nxt][0] == order[cur]){
                    maxOrder[nxt][1]++;
                } 
                in[nxt]--;
                if(!in[nxt]){
                    if(maxOrder[nxt][1] > 1){
                        order[nxt] = maxOrder[nxt][0]+1;
                    } else{
                        order[nxt] = maxOrder[nxt][0];
                    }
                    q.push(nxt);
                }
            }
        }
        // for(int i = 1; i <= m; i++){
        //     cout << order[i] << ' ';
        // }
        cout << k << ' ' << order[m] << '\n';
    }
    return 0;
}