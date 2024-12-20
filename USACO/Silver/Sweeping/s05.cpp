#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

bool comp(pair<long long, long long> pre, pair<long long, long long> post){
    if(pre.second < post.second){
        return true;
    } 
    return false;
}

int main(){
    int n;
    pair <long long, long long> people[100000], person;
    long long d, h, o;
    
    cin >> n;
    for(int idx = 0; idx < n; idx++){
        cin >> h >> o;
        if(h < o){
            person.first = h;
            person.second = o;
        } else{
            person.first = o;
            person.second = h;
        }
        people[idx] = person;
    }

    cin >> d;
    sort(people, people+n, comp);
    // for(int idx = 0; idx < n; idx++){
    //     cout << people[idx].first << ' ' << people[idx].second << '\n';
    // }

    set<pair<long long, long long>> s;
    long long max = 0;
    for(int idx = 0; idx < n; idx++){
        s.insert({people[idx].first, idx});
        while(true){
            if(s.empty()){
                break;
            }
            if( (*s.begin()).first < people[idx].second-d){
                // cout << (*s.begin()).first << ' ' << people[idx].second << '\n';
                s.erase(s.begin());
            } else{
                break;
            }
        }
        
        if(s.size() > max){
            max = s.size();
        }
        // if(start == -1){
        //     if(people[idx].second - people[idx].first < d){
        //         cur = 1;
        //     }
        //     start = idx;
        // } else if(people[start].first + d < people[idx].second){
        //     if(cur > max){
        //         max = cur;
        //     }
        //     start++;
        //     cur--;
        //     idx--;
        // } else{
        //     cur++;
        // }
    }
    
    cout << max << '\n';
    return 0;
}