#include <iostream>
#include <vector>
#include <queue>
using namespace std;
pair<int, int> maxp[20001];
vector<pair<int, int>> adj[20001];
int value[20001], in[20001] = {};

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int t;
    cin >> t;
    for(int ci = 0; ci < t; ci++){

        int n, e;
        cin >> n >> e;
        
        for(int i = 1; i <= n; i++){
            cin >> value[i];
            in[i] = 0;
            adj[i].clear();
            maxp[i].first = -100000000;
            maxp[i].second = -1;
        }
        int a, b, c;
        for(int i = 0; i < e; i++){
            cin >> a >> b >> c;
            in[b]++;
            adj[a].push_back({b, c});
        }
    
        queue<int> q;
        q.push(1);
        maxp[1].first = value[1];
        maxp[1].second = -1;
    
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            
            for(int i = 0; i < adj[cur].size(); i++){
                if(maxp[adj[cur][i].first].first < maxp[cur].first+value[adj[cur][i].first]-adj[cur][i].second){
                    maxp[adj[cur][i].first].first = maxp[cur].first+value[adj[cur][i].first]-adj[cur][i].second;
                    maxp[adj[cur][i].first].second = cur;
                }
                in[adj[cur][i].first]--;
                if(!in[adj[cur][i].first]){
                    q.push(adj[cur][i].first);
                }
            }
        }
    
        int max = 0, maxi = 0;
        for(int i = 1; i <= n; i++){
            if(maxp[i].first > max){
                max = maxp[i].first;
                maxi = i;
            }
        }

        int cur = maxi;
        vector<int> v = {};
        while(true){
            v.push_back(cur);
            if(maxp[cur].second != -1){
                cur = maxp[cur].second;
            } else{
                break;
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