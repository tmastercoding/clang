#include <iostream>
using namespace std;

// S or A -> number 
long long islands[123457][2] = {}, temp;
long long adj[123457], visit[123457] = {};
long long cnt = 0;

void dfs(long long cur){
    visit[cur] = 1;
    
    if(islands[adj[cur]][0] == 'S'){
        if(islands[cur][0] == 'S'){
            islands[adj[cur]][1] += islands[cur][1];
            islands[cur][1] = 0;
        } else{
            islands[adj[cur]][1] += temp;
            temp = 0;
        }
        dfs(adj[cur]);
    } else if(islands[adj[cur]][0] == 'W'){
        long long t = islands[adj[cur]][1];
        if(islands[cur][0] == 'S'){
            if(t > islands[cur][1]){
                islands[adj[cur]][1] -= islands[cur][1];
                islands[cur][1] = 0;
                temp = 0;
            } else{
                islands[adj[cur]][1] = 0;
                temp = islands[cur][1] - t;
                islands[cur][1] = 0;
            }
        } else{
            if(t > temp){
                islands[adj[cur]][1] -= temp;
                temp = 0;
            } else{
                islands[adj[cur]][1] = 0;
                temp -= t;
            }
        }
        dfs(adj[cur]);
    } else{
        if(islands[cur][0] == 'S'){
            cnt += islands[cur][1];
            islands[cur][1] = 0;
        } else{
            cnt += temp;
            temp = 0;
        }
    }
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
        adj[i] = to;
        // cout << i << '\n';
    }

    for(long long i = 2; i <= n; i++){
        if(!visit[i] && islands[i][0] == 'S' && adj[i] != 1){
            temp = 0;
            dfs(i);
        }
    }

    for(long long i = 2; i <= n; i++){
        if(!visit[i] && islands[i][0] == 'S' && adj[i] == 1){
            temp = 0;
            dfs(i);
        }
    }

    cout << cnt << '\n';

    return 0;
}