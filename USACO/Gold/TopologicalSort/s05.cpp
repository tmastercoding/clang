#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    int t;
    cin >> t;
    for(int c = 0; c < t; c++){
        int n, k, d;
        cin >> n >> k;
        int need[1001] = {}, time[1001] = {}, in[1001] = {};
        vector<int> adj[1001];
        queue<int> q;
    
        for(int i = 1; i <= n; i++){
            cin >> need[i];
        }
        int a, b;
        for(int i = 0; i < k; i++){
            cin >> a >> b;
            in[b]++;
            adj[a].push_back(b);
        }
        cin >> d;
        for(int i = 1; i <= n; i++){
            if(!in[i]) q.push(i);
        }
    
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            for(int nxt: adj[cur]){
                if(time[nxt] < need[cur]+time[cur]){
                    time[nxt] = need[cur]+time[cur];
                }
                in[nxt]--;
                if(!in[nxt]) q.push(nxt);
            }
        }
        cout << time[d]+need[d] << '\n';

    }
    return 0;
}