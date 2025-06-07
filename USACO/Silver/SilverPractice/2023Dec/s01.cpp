#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

pair<long long, long long> cows[200000];
int main(){ 
    long long n, m, k;
    set<pair<long long, long long>> s;
    cin >> n >> m >> k;
    
    for(int i = 0; i < n; i++){
        cin >> cows[i].first >> cows[i].second;
    }
    sort(cows, cows+n);
    s.insert({0, m});
    long long cnt = 0;
    for(int i = 0; i < n; i++){
        // cout << cows[i].first << ' ' << cows[i].second << "OUT: \n";
        long long totFreq = 0;
        while(true){
            if(cows[i].second <= 0 || s.empty()) break;
            // cout << cows[i].first << ' ' << cows[i].second << ' ' << s.begin()->first << ' ' << s.begin()->second << '\n';
            if(cows[i].first - s.begin()->first >= k || s.begin()->first == 0){
                if(cows[i].second >=s.begin()->second){
                    long long weight = s.begin()->first, freq = s.begin()->second;
                    totFreq += freq;
                    s.erase(s.begin());
                    // s.insert({cows[i].first, freq});
                    cnt += freq;
                    cows[i].second -= freq;
                } else{
                    long long weight = s.begin()->first, freq = s.begin()->second;
                    s.erase(s.begin());
                    totFreq += cows[i].second;
                    // s.insert({cows[i].first, cows[i].second});
                    cnt += cows[i].second;
                    s.insert({weight,freq-cows[i].second});
                    cows[i].second = 0;
                    break;
                }
            } else{
                break;
            }
        }
        s.insert({cows[i].first, totFreq});
    }
    cout << cnt << '\n';
    return 0;
}