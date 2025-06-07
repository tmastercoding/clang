// Haybale Feast 15459
#include <iostream>
#include <set>
using namespace std;

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    pair<long long, long long> arr[100000];   
    set<pair<long long, long long>> spicy;
    set<pair<long long, long long>>::iterator it;
    
    long long n, m, f, s;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> f >> s;
        arr[i] = {f, s};
    }

    int lo = 0, hi = -1;
    long long sum = 0, minSpice = 10000000000;
    while(true){
        hi++;
        if(hi >= n) break;
        sum += arr[hi].first;
        spicy.insert({arr[hi].second, hi});
        if(sum >= m){
            while(sum >= m){
                if(spicy.size()){
                    it = prev(spicy.end());
                    if(it != spicy.end()){
                        if(it->first < minSpice){
                            minSpice = it->first;
                        }   
                    }
                }

                sum -= arr[lo].first;
                it = spicy.find({arr[lo].second, lo});
                if(it != spicy.end()){
                    spicy.erase(it);
                }
                lo++;
            }
        }
    }
    cout << minSpice << '\n';
    return 0;
}