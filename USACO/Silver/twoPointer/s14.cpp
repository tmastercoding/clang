// Cow Lineup 5926
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main(){
    int n;
    cin >> n;
    pair<long long, long long> arr[50000];
    map<long long, long long> m;
    map<long long, long long>::iterator it;
    long long x, breed;
    for(int i = 0; i < n; i++){
        cin >> x >> breed;
        arr[i] = {x, breed};
        it = m.find(breed);
        if(it == m.end()){
            m.insert({breed, 0});
        }
    }
    sort(arr, arr+n);

    int lo = 0, hi = -1, covered = 0;
    long long minSize = 1000000000;
    while(true){
        hi++;
        if(hi >= n) break;
        it = m.find(arr[hi].second);
        if(it != m.end()){
            if(it->second == 0) covered++;
            (it->second)++;
        }
        if(covered == m.size()){
            while(covered == m.size()){
                if(arr[hi].first-arr[lo].first < minSize) minSize = arr[hi].first-arr[lo].first;
                it = m.find(arr[lo].second);
                (it->second)--;
                if(it->second == 0) covered--;
                lo++;
            }
        }
    }
    cout << minSize << '\n';
    return 0;
}