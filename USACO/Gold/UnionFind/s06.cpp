// The Gangs 1765
#include <iostream>
#include <vector>
#include <set>
using namespace std;
int p[1001];
vector<int> enemies[1001];

int Find(int x){
    if(x == p[x]) return x;
    return p[x] = Find(p[x]);
}

void Union(int a, int b){
    a = Find(a);
    b = Find(b);
    
    if(a == b) return;
    p[a] = b;
}

int main(){
    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        p[i] = i;
    }
    char type;
    int a, b;
    for(int i = 0; i < m; i++){
        cin >> type >> a >> b;
        if(type == 'F'){
            Union(a, b);
        } else{
            enemies[a].push_back(b);
            enemies[b].push_back(a);
            if(enemies[a].size() > 1){
                Union(enemies[a][0], enemies[a][1]);
                enemies[a].erase(enemies[a].begin());
            }
            if(enemies[b].size() > 1){
                Union(enemies[b][0], enemies[b][1]);
                enemies[b].erase(enemies[b].begin());
            }
        }
    }

    set<int> gangs;
    for(int i = 1; i <= n; i++){
        // cout << p[i] << '\n';
        gangs.insert(Find(i));
    }
    cout << gangs.size() << '\n'; 
    return 0;
}