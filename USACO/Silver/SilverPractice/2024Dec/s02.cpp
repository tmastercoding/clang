#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main(){
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        int n, k;
        long long x, start, end, least;
        cin >> n >> k;
        vector<long long> trees;

        for(int idx = 0; idx < n; idx++){
            cin >> x;
            trees.push_back(x);
        }
        sort(trees.begin(), trees.end());
        vector<vector<long long>> rst;
        set<pair<long long, long long>> rstAct;
        vector<long long> r;

        for(int idx = 0; idx < k; idx++){
            cin >> start >> end >> least;
            r.clear();
            r.push_back(start);
            r.push_back(end);
            r.push_back((upper_bound(trees.begin(), trees.end(), end)-trees.begin() - (lower_bound(trees.begin(), trees.end(), start)-trees.begin()))-least);
            rst.push_back(r);
            // cout << lower_bound(trees.begin(), trees.end(), start)-trees.begin() << ' ';
            // cout << upper_bound(trees.begin(), trees.end(), end)-trees.begin() << '\n';
        }
        sort(rst.begin(), rst.end());
        int cnt = 0, rstidx=0;
        for(int idx = 0; idx < n; idx++){
            while(rstidx<rst.size() && rst[rstidx][0] <= trees[idx]) {
                rstAct.insert({cnt + rst[rstidx][2], rst[rstidx][1]});
                rstidx++;
            }
            while(!rstAct.empty() && (*rstAct.begin()).second < trees[idx]) {
                rstAct.erase(rstAct.begin());
            }
            if(rstAct.empty() || rstAct.begin()->first > cnt) cnt++;
        }
        cout << cnt << '\n';
    }

    return 0;
}