#include <iostream>
#include <vector>
using namespace std;

int n, m, myd, myc;
vector<vector<int>> radj[100001];
int visit[100001] = {};
long long maxe = 0;
void rdfs(int cur, int c, int e){
    visit[cur] = 1;
    if(e > maxe) maxe = e;
    for(int i = 0; i < radj[cur].size(); i++){
        if(!visit[radj[cur][i][0]]){
            if(radj[cur][i][1] <= myd){
                rdfs(radj[cur][i][0], c, e+radj[cur][i][2]);
            } else if(c > 0){
                rdfs(radj[cur][i][0], c-1, e+radj[cur][i][2]);
            }
        }
    }
}

// d, e
vector<pair<int, int>> paths;
void rzdfs(int cur, int e, int maxD){
    visit[cur] = 1;
    for(int i = 0; i < radj[cur].size(); i++){
        if(!visit[radj[cur][i][0]]){
            int temp = maxD;
            if(radj[cur][i][1] > temp) temp = radj[cur][i][1];
            paths.push_back({temp, e});
            rzdfs(radj[cur][i][0], e+radj[cur][i][2], temp);
        }
    }
}
int main(){
    cin >> n;
    int to, d, e;
    for(int i = 2; i <= n; i++){
        cin >> to >> d >> e;
        // adj[i] = {to, d, e};
        radj[to].push_back({i, d, e});
    }

    cin >> m;
    int cows[100001][2];
    bool isZero = true;
    for(int i = 0; i < m; i++){
        cin >> myd >> myc;
        cows[i][0] = myd;
        cows[i][1] = myc;
        if(myc != 0){
            isZero = false;
        }
    }
    // if(!isZero){
    for(int i = 0; i < m; i++){
        for(int j = 1; j < 100001; j++) visit[j] = 0;
        maxe = 0;
        myd = cows[i][0];
        rdfs(1, cows[i][1], 0);
        cout << maxe << '\n';
    }
    // } else{
    //     rzdfs(1, 0, 0);
    //     sort(paths.begin(), paths.end());
    // }
    return 0;
}