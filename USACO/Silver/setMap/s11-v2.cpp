#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main(){
    int n, a, b;
    // a, b, idx
    pair<pair<int, int>, int> inputs[200000];
    int out[200000];

    multiset<pair<int, int>> st;
    cin >> n;
    int cnt = 1;
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        inputs[i] = {{a, b}, i};
    }

    sort(inputs, inputs+n);
    // for(int i = 0; i < n; i++){
    //     cout << inputs[i].first.first << ' ' << inputs[i].first.second << ": " << inputs[i].second << '\n';
    // }
    for(int i = 0; i < n; i++){

        if(st.empty()){
            st.insert({inputs[i].first.second, 1});
            out[inputs[i].second] = 1;
        } else{
            if(st.begin()->first < inputs[i].first.first){
                out[inputs[i].second] =  st.begin()->second;
                st.insert({inputs[i].first.second, st.begin()->second});
                st.erase(st.begin());
            } else{
                cnt++;
                st.insert({inputs[i].first.second, cnt});
                out[inputs[i].second] = cnt;
            }
        }
    }

    cout << cnt << '\n';
    for(int i = 0; i < n; i++){
        cout << out[i] << ' ';
    }
    cout << '\n';
    // cout << "1 1 2 1 1 2 3 1 1 1\n";

    

    return 0;
}