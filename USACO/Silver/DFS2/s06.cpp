#include <iostream>
#include <vector>
using namespace std;

int n, m, k;
int adj[100001], arr[100001], visit[100001] = {}, setTo =1, cnt = 0;
vector<int> cycle;
bool flag = false;

void dfs(int cur){
    visit[cur] = setTo;
    if(flag){
        visit[cur] = setTo+1;
        cycle.push_back(cur);
    }
    if(visit[adj[cur]] == setTo){
        flag = true;
        cnt++;
        dfs(adj[cur]);
    } else if(visit[adj[cur]] < setTo){
        dfs(adj[cur]);
    }
}


int main(){
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++){
        arr[i] = i;
    }
    int from, to;
    for(int i = 0; i < m; i++){
        cin >> from >> to;
        for(int j = 0; j < (to-from+1)/2; j++){
            int temp = arr[j+from];
            arr[j+from] = arr[to-j];
            arr[to-j] = temp;
        }
    }  
    
    for(int i = 1; i <= n; i++){
        adj[i] = arr[i];
        // cout << adj[i] << '\n';
    }

    for(int i = 1; i <= n; i++){
        if(!visit[i]){
            // dfs
            cycle.clear();
            flag = false;
            cnt = 0;
            dfs(i);
            // cout << i << '\n';
            // for(int i = 0; i < cnt; i++){
            //     cout << cycle[i] << ' ';
            // }
            // cout << '\n';
            // k % image
            int change = k % cnt;
            // cout << change << '\n';
            // switch
            for(int j = 0; j < cnt; j++){
                if(j+change < cnt){
                    arr[cycle[j]] = cycle[j+change];
                } else{
                    arr[cycle[j]] = cycle[j+change-cnt];
                }
            }
        }
        setTo += 2;
    }

    for(int i = 1; i <= n; i++){
        cout << arr[i] << '\n';
    }
    return 0;
}