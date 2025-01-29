// 맥주 축제 17503
#include <iostream>
#include <algorithm>
using namespace std;

bool comp(pair<int, long long> pre, pair<int, long long> post){
    if(pre.first > post.first){
        return true;
    }
    if(pre.first == post.first){
        if(pre.second < post.second ){
            return true;
        }
    }
    return false;
}

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    long long days, totLike, types;
    cin >> days >> totLike >> types;
    pair<int, long long> beers[200000], beer;
    for(int i = 0; i < types; i++){
        cin >> beers[i].first >> beers[i].second;
    }
    sort(beers, beers+types, comp);

    long long lo = 1, mid, hi = 2147483648, sum;
    long long cnt = 0;
    for(int i = 0; i < days; i++){
        sum += beers[i].first;
    }
    if(sum >= totLike){
        while(lo < hi){
            mid = (lo+hi+1)/2;
            sum = 0, cnt = 0;
            for(int i = 0; i < types; i++){
                if(beers[i].second < mid){
                    sum += beers[i].first;
                    cnt++;
                }
                if(cnt == days){
                    break;
                }
            }
            if(cnt == days){
                if(sum >= totLike){
                    hi = mid-1;
                } else{
                    lo = mid;
                }
            } else{
                // cout << "ERROR\n";
                // break;
                lo = mid;
            }
        }

        cout << lo << '\n';

    } else{
        cout << "-1\n";
    }

    return 0;
}