#include <iostream>
#include <queue>
using namespace std;

int main(){
    int n, k;
    int visit[100001] = {};
    cin >> n >> k;
    queue<int> q;
    visit[n] = 1;
    q.push(n);

    while(!q.empty()){
        int cur = q.front();
        // cout << cur << '\n';
        if(cur == k) break;
        q.pop();
        int back, go, teleport;
        back = cur-1;
        go = cur+1;
        teleport = cur*2;
        if(back > -1 && !visit[back]){
            visit[cur-1] = visit[cur]+1;
            q.push(back);
        }
        
        if(go < 100001 && !visit[go]){
            visit[go] = visit[cur]+1;
            q.push(go);
        } 

        if(teleport < 100001 && !visit[teleport]){
            visit[teleport] = visit[cur]+1;
            q.push(teleport);
        }
    }
    cout << visit[k]-1 << '\n';
    return 0;
}