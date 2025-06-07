#include <iostream>
#include <stack>
using namespace std;

int main(){
    int cows[300000] = {};
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> cows[i];
    }

    stack<pair<int, int>> cur;
    long long sum = 0, dist = 0;
    for(int i = 0; i < n; i++){
        while(cur.size()){
            // cout << cur.top().first << ' ';
            if(cows[i] > cur.top().first){
                sum += i-cur.top().second+1;
                cur.pop();
            } else{
                sum += i-cur.top().second+1;
                break;
            }
        }
        // cout << '\n';
        // dist += cur.size();
        // sum += dist;
        // cout << dist << '\n';
        cur.push({cows[i], i});
        // dist += 1;
    }
    cout << sum << '\n';

    return 0;
}