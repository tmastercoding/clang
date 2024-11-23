// Daisy Chains in the Field 5938
#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> chains[500];
int visit[500] = {0};

void dfs(int cur){
    visit[cur] = 1;

    for(int idx = 0; idx < chains[cur].size(); idx++){
        int next = chains[cur][idx];
        if(visit[next] == 0){
            dfs(next);  
        }
    }
}


int main(){
    cin >> n >> m;
    int c1, c2;
    for(int idx = 0; idx < m; idx++){
        cin >> c1 >> c2;
        chains[c1].push_back(c2);
        chains[c2].push_back(c1);
    }

    dfs(1);

    bool hasPrinted = false;
    for(int idx = 1; idx <=n; idx++){
        if(!visit[idx]){
            cout << idx << '\n';
            hasPrinted = true;
        }
    }

    if(!hasPrinted){
        cout << "0\n";
    }
    return 0;
}