#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    queue<string> q;
    string names[300000] = {};
    int lens[22] = {};
    long long cnt = 0;
    for(int idx = 0; idx < n; idx++){
        cin >> names[idx];
    }

    q.push(names[0]);
    lens[q.front().length()]++;
    for(int idx = 1; idx < n; idx++){
        if(q.size() > k){
            lens[q.front().length()]--;
            q.pop();
        }
        q.push(names[idx]);
        lens[names[idx].length()]++;

        // cout << lens[names[idx].length()] << '\n';
        cnt += lens[names[idx].length()]-1;
        // cout << cnt << '\n';
    }
    cout << cnt << '\n';
    return 0;
}