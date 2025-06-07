#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> adj[100001];
int regions[100001] = {};
int rdx = 0;
void dfs(int cur){
    regions[cur] = rdx;
    for(int i = 0; i < adj[cur].size(); i++){
        if(regions[adj[cur][i]] == 0){
            dfs(adj[cur][i]);
        }
    }
}

int main(){
    int t;
    cin >> t;
    for(int c = 0; c < t; c++){
        cin >> n >> m;
        rdx = 0;
        for(int i = 1; i <= n; i++){
            regions[i] = 0;
            adj[i].clear();
        }
        int pre, post;
        for(int i = 0; i < m; i++){
            cin >> pre >> post;
            adj[pre].push_back(post);
            adj[post].push_back(pre);
        }
        
        for(int i = 1; i <= n; i++){
            if(!regions[i]){
                rdx++;
                dfs(i);
            }
        }
    
        vector<int> ones, ns;
        for(int i = 1; i <= n; i++){
            if(regions[i] == 1){
                ones.push_back(i);
            }
            if(regions[i] == regions[n]){
                ns.push_back(i);
            }
        }
        
        // for(int i = 0; i < ones.size(); i++) cout << ones[i] << ' ';
        // cout << '\n';
        // for(int i = 0; i < ns.size(); i++) cout << ns[i] << ' ';
        // cout << '\n';
    
        long long distToOne[100001], distToN[100001];
        for(int i = 1; i <= rdx; i++){
            distToOne[i] = -1;
            distToN[i] = -1;
        }
        for(int i = 1; i <= n; i++){
            long long dist = 0;
            int temp = lower_bound(ones.begin(), ones.end(), i)-ones.begin();
            pre = 100001, post = 100001;
            if(temp < ones.size()){
                pre = abs(ones[temp]-i);
            } 
            if(temp-1 > -1){
                post = abs(ones[temp-1]-i);
            }
            if(pre < post){
                dist = pre;
            } else{
                dist = post;
            }
    
            dist *= dist;
            if(distToOne[regions[i]] > dist || distToOne[regions[i]] == -1){
                distToOne[regions[i]] = dist;
            }
            
            dist = 0;
            temp = lower_bound(ns.begin(), ns.end(), i)-ns.begin();
            pre = 100001, post = 100001;
            if(temp < ns.size()){
                pre = abs(ns[temp]-i);
            } 
            if(temp-1 > -1){
                post = abs(ns[temp-1]-i);
            }
            if(pre < post){
                dist = pre;
            } else{
                dist = post;
            }
    
            dist *= dist;
            if(distToN[regions[i]] > dist || distToN[regions[i]] == -1){
                distToN[regions[i]] = dist;
            }
        }
    
        long long min = 100000000000, cur;
        for(int i = 1; i <= rdx; i++){
            cur = distToOne[i] + distToN[i];
            // cout << cur << '\n';
            if(cur < min) min = cur;
        }
        cout << min << '\n';

    }
    return 0;
}