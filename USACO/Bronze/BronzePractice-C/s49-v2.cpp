// Air Cownditioning
#include <iostream>
using namespace std;

int main(){
    // freopen("5.in", "r", stdin);
    int n;
    int cows[100000][2], dif[100000], groups[100000][2];
    cin >> n;
    for(int idx = 0; idx < n; idx++){
        cin >> cows[idx][0];
    }
    for(int idx = 0; idx < n; idx++){
        cin >> cows[idx][1];
        dif[idx] = cows[idx][0]-cows[idx][1];
    }

    int cnt = 0;
    
    int prev = 0;
    for(int idx = 0; idx < n; idx++){
        if(prev != dif[idx]){
            if(prev < dif[idx]){
                cnt += dif[idx]-prev;
            }
            prev = dif[idx];
        }
        // cout << cnt << ' ' << prev<< '\n';
        
    }
    if(prev < 0){
        cnt += abs(prev);
    }
    cout << cnt << '\n';

    return 0;
}