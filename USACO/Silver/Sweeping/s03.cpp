// Mountain View 17026
#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(pair<long long, long long> pre, pair<long long, long long> post){
    if(pre.first == post.first){
        return (pre.second > post.second);
    } 
    return (pre.first < post.first);
}

int main(){
    // freopen("mountains.in", "r", stdin);
    // freopen("mountains.out", "w", stdout);
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    pair<long long, long long> peaks[100000], peak;
    cin >> n;
    long long x, y;
    for(int idx = 0; idx < n; idx++){
        cin >> x >> y;
        peak.first = x-y;
        peak.second = x+y;
        peaks[idx] = peak;
    }
    
    sort(peaks, peaks+n, cmp);
    long long max = -1;
    int cnt = 0;
    for(int idx = 0; idx < n; idx++){
        if(peaks[idx].second > max){
            max = peaks[idx].second;
            cnt++;
        }
        
    }
    cout << cnt << '\n';
    return 0;
}