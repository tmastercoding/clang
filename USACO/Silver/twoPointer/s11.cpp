#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int main(){
    int n;
    long long d, x, h;
    pair<long long, long long> cows[50000];
    set<pair<long long, long long>> left = {}, right = {};
    set<pair<long long, long long>>::iterator temp;
    cin >> n >> d;
    for(int i = 0; i < n; i++){
        cin >> x >> h;
        cows[i] = {x, h};
    }
    sort(cows, cows+n);

    int lo = 0, mid = -1, hi = 0, cnt = 0;
    while(true){
        mid++;
        if(mid >= n) break;
        // height, pos
        // reduce right
        temp = right.find({cows[mid].second, cows[mid].first});
        if(temp!=right.end()){
            
            right.erase(temp);
        }
        // expand right
        while(true){
            hi++;
            if(cows[hi].first-cows[mid].first > d || hi >= n){
                hi--;
                break;
            } else{
                right.insert({cows[hi].second, cows[hi].first});
            }
        }
        // // expand left
        if(mid-1 >= 0) left.insert({cows[mid-1].second, cows[mid-1].first});
        // reduce left
        while(true){
            if(lo >= mid) break;
            if(cows[mid].first-cows[lo].first > d){
                temp = left.find({cows[lo].second, cows[lo].first});
                if(temp!=left.end()){
                    left.erase(temp);
                } else{
                    break;
                }
                lo++;
            } else{
                break;
            }
        }
        if(left.size()){
            temp = prev(left.end());
            
            if(temp->first>=2*cows[mid].second){
                if(right.size()){
                    temp = prev(right.end());
                    if(temp->first >= 2*cows[mid].second){
                        temp = left.begin();
                        // cout << "LEFT:\n";
                        // for(; temp != left.end(); temp++){
                        //     cout << temp->first << "; " << temp->second << ' ';
                        // }
                        // cout << '\n';
                        // cout << "RIGHT:\n";
                        temp = right.begin();
                        // for(; temp != right.end(); temp++){
                        //     cout << temp->first << "; " << temp->second << ' ';
                        // }
                        // cout << '\n';
                        // cout << mid << '\n';
                        cnt++;
                    }
                }
            }
        }
    }
    cout << cnt << '\n';
    return 0;
}