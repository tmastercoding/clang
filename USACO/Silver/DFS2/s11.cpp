#include <iostream>
#include <set>
using namespace std;

int adj[101] = {}, visit[101] = {}, setTo;
set<int> out;
bool loop = false;

void dfs(int cur){
    visit[cur] = setTo;
    if(loop){
        visit[cur] = setTo+1;
        out.insert(cur);
    }
    if(visit[adj[cur]] == setTo){
        if(!loop){
            loop = true;
        }
        dfs(adj[cur]);
    } else if(visit[adj[cur]] == 0){
        dfs(adj[cur]);
    }

}

int main(){
    int n, num;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> num;
        adj[i] = num;
    }
    setTo = 1;
    for(int i = 1; i <= n; i++){
        loop = false;
        if(!visit[i]){
            dfs(i);
        }
        setTo+=2;
    }

    cout << out.size() << '\n';
    for(int i: out){
        cout << i << '\n';
    }
    return 0;
}