#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n = 0, temp;
    cin >> n;
    int pos[100000], want[100000];
    vector<int> cur;
    for(int idx = 0; idx < n; idx++){
        cin >> temp;
        pos[temp-1] = idx;
        cur.push_back(temp-1);
    }
    for(int idx = 0; idx < n; idx++){
        cin >> temp;
        want[idx] = temp-1;
    }

    // v.pop_back();
    // v.insert(v.begin(), 5);
    int cnt = 0;
    while(true){
        bool flag = true;
        for(int idx =0; idx < n; idx++){
            // cout << pos[want[idx]] << ' ' << idx << '\n';
            if(pos[want[idx]] > idx){
                flag = false;
                cnt++;
                // cout << idx+1 << ' ' << pos[want[idx]] << ' ' << want[idx] << '\n';
                cur.erase(cur.begin()+pos[want[idx]]);
                cur.insert(cur.begin()+idx, want[idx]);
                break;
            }
        } 
        for(int idx =0; idx < n; idx++){
            // cout << cur[idx]+1 << ' ';
            pos[cur[idx]] = idx;
        }
        // cout << '\n';

        // cur.clear();
        
        if(flag){
            break;
        }
        // i++;
        // if(i == 2){
        //     break;
        // }

    }
    cout << cnt << '\n';

    return 0;
}