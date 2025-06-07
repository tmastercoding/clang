#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;
    long long a, b;
    cin >> n >> a >> b;
    pair<long long, long long> cows[200000];
    for(int i = 0; i < n; i++){
        cin >> cows[i].second >> cows[i].first;
    }

    sort(cows, cows+n);
    long long cnt = 0;
    for(int i = 0; i < n; i++){
        // cout << cows[i].first << ' ' <<  cows[i].second << '\n';
        pair<long long, long long> findPair = { a-cows[i].first, -1};
        auto found = lower_bound(cows, cows+n, findPair);
        if(found != cows+n){
            // cout << "A: " << found->first << ' ' << found->second << '\n';
            if(found->first+cows[i].first == a){
                if(cows[i] == *found){
                    continue;
                    long long temp = cows[i].second/2;
                    cows[i].second -= temp*2;
                    cnt += temp;
                } else if(cows[i].second <= found->second){
                    found->second -= cows[i].second;
                    cnt += cows[i].second;
                    cows[i].second = 0;
                } else{
                    cows[i].second -= found->second;
                    cnt += found->second;
                    found->second = 0;
                }
            }
        }
        findPair = {b-cows[i].first, 0};
        found = lower_bound(cows, cows+n, findPair);
        // cout << b-cows[i].first << '\n';
        if(found != cows+n){
            // cout << "B: " << found->first << ' ' << found->second << '\n';
            if(found->first+cows[i].first == b){
                if(cows[i] == *found){
                    continue;
                    long long temp = cows[i].second/2;
                    cows[i].second -= temp*2;
                    cnt += temp;
                } else if(cows[i].second <= found->second){
                    found->second -= cows[i].second;
                    cnt += cows[i].second;
                    cows[i].second = 0;
                } else{
                    cows[i].second -= found->second;
                    cnt += found->second;
                    found->second = 0;
                }
            }
        }
    }

    for(int i = 0; i < n; i++){
        // cout << cows[i].first << ' ' <<  cows[i].second << '\n';
        pair<long long, long long> findPair = { a-cows[i].first, -1};
        auto found = lower_bound(cows, cows+n, findPair);
        if(found != cows+n){
            // cout << "A: " << found->first << ' ' << found->second << '\n';
            if(found->first+cows[i].first == a){
                if(cows[i] == *found){
                    long long temp = cows[i].second/2;
                    cows[i].second -= temp*2;
                    cnt += temp;
                }
            }
        }
        findPair = {b-cows[i].first, 0};
        found = lower_bound(cows, cows+n, findPair);
        // cout << b-cows[i].first << '\n';
        if(found != cows+n){
            // cout << "B: " << found->first << ' ' << found->second << '\n';
            if(found->first+cows[i].first == b){
                if(cows[i] == *found){
                    long long temp = cows[i].second/2;
                    cows[i].second -= temp*2;
                    cnt += temp;
                }
            }
        }
    }
    cout << cnt << '\n';
    return 0;
}