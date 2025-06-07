#include <iostream>
using namespace std;

int adj[1001] = {}, visit[1001] = {};
int n, setTo, returnval;

void dfs(int cur){
    visit[cur] = setTo;
    if(visit[adj[cur]] == setTo){
        returnval = 1;
    } else if(visit[adj[cur]]){
        returnval = 0;
    } else{
        dfs(adj[cur]);
    }
}

int main(){
    cin >> n;
    string buffer;
    cin >> buffer;
    for(int i = 0; i < n; i++){
        if(buffer[i] == 'E'){
            adj[i] = i+1;
        } else{
            adj[i] = i-1;
        }
    }

    int cnt = 0;
    for(int i = 0; i < n; i++){
        setTo = i+1;
        if(!visit[i]){
            dfs(i);
            if(returnval) cnt++;
        }
    }
    cout << cnt << '\n';
    return 0;
}