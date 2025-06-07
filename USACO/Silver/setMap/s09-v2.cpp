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
        // cout << *it << ' ' << *it-prev << '\n';
        between.insert({*it-prev, cnt++});
        prev = *it;
    }
    // // between.insert(n-prev);

    // // for(auto it = locations.begin(); it != locations.end(); it++){
    // //     cout << it->first << ' ' << it->second.first << ' ' << it->second.second<< '\n';
    // // }

    for(int i = n-1; i > -1; i--){
        auto it = between.end();
        it--;
        outputs[i] = it->first;
        auto ldx = lights.find(inputs[i]);
        auto rdx = ldx;
        ldx--;
        auto left = between.lower_bound({inputs[i]-*ldx, 0});
        if(left->first == inputs[i]-*ldx){
            between.erase(left);
        } 
        rdx++;
        // cout << *ldx << ' ' << inputs[i] << ' ' << *rdx << '\n';
        auto right = between.lower_bound({*rdx-inputs[i], 0});
        if(right->first == *rdx-inputs[i]){
            between.erase(right);
        } 
        between.insert({*rdx-*ldx, cnt++});
        ldx++;
        lights.erase(ldx);
        
    }

    for(int i = 0; i < n; i++){
        cout << outputs[i] << ' ';
    }
    cout << '\n';

    return 0;
}