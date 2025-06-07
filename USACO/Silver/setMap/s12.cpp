#include <iostream>
#include <set>
using namespace std;

int main(){
    freopen("convention2.in", "r", stdin);
	freopen("convention2.out", "w", stdout);

    int n;
    set<pair<pair<long long, long long>, int>> cows; 
    cin >> n;
    long long a, t;
    for(int i = 0; i < n; i++){
        cin >> a >> t;
        cows.insert({{a, i}, t});
    }
    
    // for(int i = 0; i < n; i++){
    //     cout << cows[i].first.first <<" " << cows[i].first.second << ' ' <<  cows[i].second << '\n';
    // }

    set<pair<int, pair<long long, long long>>> st;
    
    long long time = cows.begin()->first.first+cows.begin()->second, maxWait = 0;
    cows.erase(cows.begin());
    while(!cows.empty()){
        for(auto it: cows){
            if(it.first.first <= time){
                st.insert({it.first.second, {it.first.first, it.second}});
            }
        }

        if(st.empty()){
            time = cows.begin()->first.first;
            st.insert({cows.begin()->first.second, {cows.begin()->first.first, cows.begin()->second}});
        }
        if(maxWait < time - st.begin()->second.first) maxWait = time - st.begin()->second.first;
        time += st.begin()->second.second;
        cows.erase({{st.begin()->second.first, st.begin()->first}, st.begin()->second.second});
        st.clear();
    }
    cout << maxWait << '\n';
    return 0;
}