#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int maxp[20001];
int value[20001], in[20001] = {};
int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int t;
    cin >> t;
    for(int ci = 0; ci < t; ci++){
        
        int n, e;
        cin >> n >> e;
        vector<pair<int, int>> adj[n+1], badj[n+1];
        for(int i = 1; i < 20001; i++){
            value[i] = 0;
            in[i] = 0;
            maxp[i] = -1000000000;
        }
        
        for(int i = 1; i <= n; i++){
            cin >> value[i];
        }
        int a, b, c;
        for(int i = 0; i < e; i++){
            cin >> a >> b >> c;
            in[b]++;
            adj[a].push_back({b, c});
            badj[b].push_back({a, c});
        }
    
        queue<int> q;
        q.push(1);
        maxp[1] = value[1];

    
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            
            for(int i = 0; i < adj[cur].size(); i++){
                if(maxp[adj[cur][i].first] < maxp[cur]+value[adj[cur][i].first]-adj[cur][i].second){
                    maxp[adj[cur][i].first] = maxp[cur]+value[adj[cur][i].first]-adj[cur][i].second;
                }
                in[adj[cur][i].first]--;
                if(!in[adj[cur][i].first]){
                    q.push(adj[cur][i].first);
                }
            }
        }
    
        int max = -1, maxi = 0;
        for(int i = 1; i <= n; i++){
            if(maxp[i] > max){
                max = maxp[i];
                maxi = i;
            }
        }

        int cur = maxi;
        vector<int> v = {};
        while(true){
            v.push_back(cur);
            if(cur == 1) break;
            for(int i = 0; i < badj[cur].size(); i++){
                if(maxp[cur]-value[cur]+badj[cur][i].second == maxp[badj[cur][i].first]){
                    cur = badj[cur][i].first;
                    break;
                }
            }

        }
        cout << max << ' ' << v.size() << '\n';
        for(int i = v.size()-1; i > -1; i--){
            cout << v[i] << ' ';
        }
        // cout << maxi;
        cout << '\n';
    }
    return 0;
}