#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

long long n, m, myd, myc;
vector<vector<long long>> radj[100001];
long long visit[100001] = {};
// d, e
set<pair<long long, long long>> ds;
// c(0, 1, 2 ... 10) -> vector<maxD needed, totE>
set<vector<long long>> maxds[11];
long long ddx = 0, mdx = 0;
void rdfs(long long cur, long long e){
    visit[cur] = 1;
    for(long long i = 0; i < radj[cur].size(); i++){
        if(!visit[radj[cur][i][0]]){
            ds.insert({radj[cur][i][1], ddx++});
            // cout << radj[cur][i][0] << '\n';
            // for(auto i:ds){
            //     cout << i.first << '\n';
            // }
            set<pair<long long, long long>>::iterator it = ds.end();
            it--;
            long long temp = it->first;
            bool past = false;
            for(long long c = 0; c <= 10; c++){
                maxds[c].insert({temp, e+radj[cur][i][2], mdx++});
                if(!past){
                    it--;
                    temp = it->first;
                    if(it == ds.begin()) past = true;   
                } else{
                    temp = 0;
                }
            }
            rdfs(radj[cur][i][0], e+radj[cur][i][2]);
            ds.erase(ds.lower_bound({radj[cur][i][1], -1}));
        }
    }
}

int main(){
    cin >> n;
    long long to, d, e;
    for(long long i = 2; i <= n; i++){
        cin >> to >> d >> e;
        // adj[i] = {to, d, e};
        radj[to].push_back({i, d, e});
    }

    cin >> m;
    set<vector<long long>> cows;
    long long output[100001];
    for(long long i = 0; i < m; i++){
        cin >> myd >> myc;
        cows.insert({myc, myd, i}); 
    }

    rdfs(1, 0);

    // for(long long c = 0; c < 11; c++){
    //     cout << c << '\n';
    //     for(vector<long long> v : maxds[c]){
    //         cout << v[0]<< ' ' <<  v[1]<< ' ' << v[2] << '\n';

    //     }
    // }

    long long cdx = 0;
    set<long long> enjoys = {0};
    auto doneTil = maxds[cdx].begin();
    for(auto cow: cows){
        if(cow[0] != cdx){
            cdx = cow[0];
            enjoys.clear();
            enjoys.insert(0);
            doneTil = maxds[cdx].begin();
        }
        auto it = maxds[cdx].upper_bound({cow[1], 100000000000000, 100000000000000});
        for(;doneTil != it ; doneTil++){
            enjoys.insert((*doneTil)[1]);
        }
        auto temp = enjoys.end();
        temp--;
        // if(cow[0] == 2){
        //     cout << cow[0] << ' ' << cow[1] << ' ' << cow[2] << ' ' << *temp << '\n';
        // }
        output[cow[2]] = *temp;
    }
    for(long long i = 0; i < m; i++){
        cout << output[i] << '\n';
    }
    // cout << "---------------------\n";

    // for(long long i = 0; i < m; i++){
    //     auto it = maxds[cows[i][1]].upper_bound({cows[i][0], LLONG_MAX, LLONG_MAX});
    //     cout << cows[i][0] << ' ' << cows[i][1] << " : ";
        
    //     if(it != maxds[cows[i][1]].end()){
    //         cout << (*it)[0] << ' ' << (*it)[1] << ' '<< (*it)[2] << '\n';
    //     } else{
    //         cout << "ANY\n";
    //     }

    //     long long max = 0;
    //     for(auto jt = maxds[cows[i][1]].begin(); jt != it; jt++){
    //         if((*jt)[1] > max) max = (*jt)[1];
    //     }
    //     cout << max << '\n';
    // }
    // if(!isZero){
    //     for(long long i = 0; i < m; i++){
    //         for(long long j = 1; j < 100001; j++) visit[j] = 0;
    //         maxe = 0;
    //         myd = cows[i][0];
    //         rdfs(1, cows[i][1], 0);
    //         cout << maxe << '\n';
    //     }
    // } else{
    //     rzdfs(1, 0, 0);
    //     sort(paths.begin(), paths.end());
    // }
    return 0;
}