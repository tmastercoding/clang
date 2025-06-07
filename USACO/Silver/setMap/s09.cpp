#include <iostream>
#include <map>
#include <set>
using namespace std;

int inputs[200100], outputs[200100];
int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int x;
    // idx, val
    // int left[200100], right[200100];
    set<int> lights;
    set<pair<int, int>> between;
    int n;
    cin >> x >> n;

    for(int i = 0; i < n; i++){
        cin >> inputs[i];
        lights.insert(inputs[i]);
    }

    lights.insert(0);
    lights.insert(x);

    // init
    int prev = 0, cnt = 0;
    for(auto it = lights.begin(); it != lights.end(); it++){
        left[*it] = prev;
        right[prev] = *it;
        // cout << *it << ' ' << *it-prev << '\n';
        between.insert({*it-prev, cnt++});
        prev = *it;
    }
    // between.insert(n-prev);

    // for(auto it = between.begin(); it != between.end(); it++){
    //     cout << *it << ' ' << between.count(*it) << '\n';
    // }

    for(int i = n-1; i > -1; i--){
        auto it = between.end();
        it--;
        outputs[i] = it->first;
        it = between.lower_bound({inputs[i]-left[inputs[i]], 0});
        if(it->first == inputs[i]-left[inputs[i]]){
            between.erase(it);
        } else{
            it--;
            if(it->first == inputs[i]-left[inputs[i]]){
                between.erase(it);
            }
        }
        
        
        it = between.lower_bound({right[inputs[i]]-inputs[i], 0});
        if(it->first == right[inputs[i]]-inputs[i]){
            between.erase(it);
        } else{
            it--;
            if(it->first == right[inputs[i]]-inputs[i]){
                between.erase(it);
            }
        }
        right[left[inputs[i]]] = right[inputs[i]];
        left[right[inputs[i]]] = left[inputs[i]];
        between.insert({right[inputs[i]]-left[inputs[i]], cnt++});
    }

    for(int i = 0; i < n; i++){
        cout << outputs[i] << ' ';
    }
    cout << '\n';

    return 0;
}