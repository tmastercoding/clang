#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    int time[501] = {}, need[501] = {}, in[501] = {};
    vector<int> adj[501];
    for(int i = 1; i <= n; i++){
        cin >> need[i];
        int req;
        while((cin >> req) && req != -1){
            in[i]++;
            adj[req].push_back(i);
        }
    }

    queue<int> q;
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

    for(int i = 1; i <= n; i++){
        cout << time[i]+need[i] << '\n';
    }

    return 0;
}