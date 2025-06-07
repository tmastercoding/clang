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
        cout << cur << '\n';
        if(cur == k) break;
        q.pop();
        int back, go, teleport;
        back = cur-1;
        go = cur+1;
        teleport = cur*2;
        if(back > -1){
            back = abs(k-back);
        } else{
            back = 100002;
        }
        
        if(go < 100001){
            go = abs(k-go);
        } else{
            go = 100002;
        }

        if(teleport < 100001){
            teleport = abs(k-teleport);
        } else{
            teleport = 100002;
        }

        if(go <= back && go <= teleport){
            visit[cur+1] = visit[cur]+1;
            q.push(cur+1);
        } else if(back <= go && back <= teleport){
            visit[cur-1] = visit[cur]+1;
            q.push(cur-1);
        } else{
            visit[cur*2] = visit[cur]+1;
            q.push(cur*2);
        }
    }
    cout << visit[k]-1 << '\n';
    return 0;
}