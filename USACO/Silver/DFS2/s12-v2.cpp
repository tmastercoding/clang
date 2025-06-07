#include <iostream>
#include <vector>
using namespace std;

// S or A -> number 
long long islands[123457][2] = {}, temp;
vector<long long> adj[123457];
int visit[123457] = {};
long long cnt = 0;

long long dfs(long long cur){
    visit[cur] = 1;
    long long have = 0;
    for(int i = 0; i < adj[cur].size(); i++){
        have += dfs(adj[cur][i]);
    }
    if(islands[cur][0] == 'S'){
        have += islands[cur][1];
    } else{
        have -= islands[cur][1];
        if(have < 0) have = 0;
    }
    return have;
}

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    long long n;
    cin >> n;
    for(long long i = 2; i <= n; i++){
        char ch;
        long long pop, to;
        cin >> ch >> pop >> to;
        islands[i][0] = ch;
        islands[i][1] = pop;
        adj[to].push_back(i);
        // cout << i << '\n';
    }
    cout << dfs(1) << '\n';
    // for(long long i = 2; i <= n; i++){
    //     if(!visit[i] && islands[i][0] == 'S' && adj[i] != 1){
    //         temp = 0;
    //         dfs(i);
    //     }
    // }

    // for(long long i = 2; i <= n; i++){
    //     if(!visit[i] && islands[i][0] == 'S' && adj[i] == 1){
    //         temp = 0;
    //         dfs(i);
    //     }
    // }

    // cout << cnt << '\n';

    return 0;
}