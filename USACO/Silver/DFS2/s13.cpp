#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> adj[100001];
int visit[100001] = {}, temp[100001] = {}, n, m;
bool work = true;
void dfs(int cur){
    visit[cur] = 1;
    for(int i = 0; i < adj[cur].size(); i++){
        if(visit[adj[cur][i].first]){
            if(adj[cur][i].second == 'S' && temp[adj[cur][i].first] != temp[cur]){
                work = false;
            }
            if(adj[cur][i].second == 'D' && temp[adj[cur][i].first] == temp[cur]){
                work = false;
            }
        } else{
            if(adj[cur][i].second == 'S'){
                temp[adj[cur][i].first] = temp[cur];
            } else{
                if(temp[cur] == 1) {
                    temp[adj[cur][i].first] = 2;
                } else{
                    temp[adj[cur][i].first] = 1;
                }
            }
            dfs(adj[cur][i].first);
        }
    }
    
}

int main(){
    // freopen("revegetate.in", "r", stdin);
    // freopen("revegetate.out", "w", stdout);
    cin >> n >> m;
    char type;
    int pre, post;
    for(int i = 0; i < m; i++){
        cin >> type >> pre >> post;
        adj[pre].push_back({post, type});
        adj[post].push_back({pre, type});
    }
    string size = "1";
    for(int i = 1; i <= n; i++){
        work = true;
        // cout << i << '\n';
        if(!visit[i]){
            temp[i] = 1;
            dfs(i);
            if(!work){
                size = "0";
                break;
            } else{
                size+= "0";
            }
        }
    }
    
    cout << size << '\n';
    return 0;
}