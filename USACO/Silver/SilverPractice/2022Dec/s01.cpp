#include <iostream>
#include <vector>
using namespace std;

int n;
long long barns[200100], avg;
vector<pair<int, long long>> adj[200100];
int visit[200100] = {};
vector<vector<long long>> out;

long long dfs(int cur){
    visit[cur] = 1;
    long long sum = 0;
    for(int i = 0; i < adj[cur].size(); i++){
        if(!visit[adj[cur][i].first]){
            adj[cur][i].second = avg-barns[adj[cur][i].first]+dfs(adj[cur][i].first);
        }
        sum += adj[cur][i].second;
    }
    return sum;
}

void distPos(int cur){
    visit[cur] = 1;
    for(int i = 0; i < adj[cur].size(); i++){
        if(!visit[adj[cur][i].first]){
            distPos(adj[cur][i].first);
            out.push_back({adj[cur][i].first, cur, -adj[cur][i].second});
        }
    }
}

void distNeg(int cur){
    visit[cur] = 1;
    for(int i = 0; i < adj[cur].size(); i++){
        if(!visit[adj[cur][i].first]){
            out.push_back({cur, adj[cur][i].first, adj[cur][i].second});
            distNeg(adj[cur][i].first);
        }
    }
}



void order(int cur){
    visit[cur] = 1;
    for(int i = 0; i < adj[cur].size(); i++){
        if(!visit[adj[cur][i].first]){
            if(adj[cur][i].second < 0){
                // cout << "TEST:" << adj[cur][i].first << ' ' << adj[cur][i].second << '\n';
                distPos(adj[cur][i].first);
                out.push_back({adj[cur][i].first, cur, -adj[cur][i].second});
            }
        }
    }
    
    for(int i = 0; i < adj[cur].size(); i++){
        if(!visit[adj[cur][i].first]){
            // cout << adj[cur][i].second << '\n';
            if(adj[cur][i].second > 0){
                // cout << "TEST:\n";
                // cout << cur << ' ' << adj[cur][i].first << ' ' <<  -adj[cur][i].second << '\n';
                out.push_back({cur, adj[cur][i].first, adj[cur][i].second});
                distNeg(adj[cur][i].first);
            }
        }
    }
}


int main(){
    cin >> n;
    long long sum = 0;
    for(int i = 1; i <= n; i++){
        cin >> barns[i];
        sum += barns[i];
    }
    avg = sum/n;
    int a, b;
    for(int i = 0; i < n-1; i++){
        cin >> a >> b;
        adj[a].push_back({b, 0});
        adj[b].push_back({a, 0});
    }

    dfs(1);
    for(int i = 1; i <= n; i++){
        visit[i] = 0;
    }
    // for(int i = 1; i <= n; i++){
    //     for(int j = 0; j < adj[i].size(); j++){
    //         cout << i << "<-" << adj[i][j].first << ": " << adj[i][j].second << '\n';
    //     }
    // }

    order(1);
    cout <<out.size() << '\n';
    for(int i = 0; i < out.size(); i++){
        cout << out[i][0] << ' '<< out[i][1] << ' ' << out[i][2] << '\n';
    }

    return 0;
}