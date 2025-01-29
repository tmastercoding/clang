// 원 영역 10000
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
typedef long long ll;

bool comp(pair<ll, ll> pre, pair<ll, ll> post){
    if(pre.first+pre.second < post.first+post.second){
        return true;
    } else if(pre.first+pre.second == post.first+post.second){
        if(pre.second < post.second){
            return true;
        }
    } 
    return false;
}

int main(){
    int n;
    ll x, r;
    pair<ll, ll> circles[300000];
    pair<ll, ll> circle;
    stack<pair<ll, ll>> s;

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> circle.first >> circle.second;
        circles[i] = circle;
    }
    sort(circles, circles+n, comp);

    // for(int i = 0; i < n; i++){
    //     cout << circles[i].first << ' ' << circles[i].second << '\n';
    // }
    int cnt = 1;
    for(int i = 0; i < n; i++){
        ll start = circles[i].first-circles[i].second, radius = circles[i].second;
        bool flag = true;
        ll curEnd = start+2*radius;
        if(s.size() == 0){
            flag = false;
        }
        while(s.size()){
            // cout << curEnd << '\n';
            // cout << start << ' ' << s.top().first << ' ' <<  s.top().first + s.top().second*2 << ' ' <<start+2*radius <<  '\n';
            if( start <= s.top().first && s.top().first + s.top().second*2 <= start+2*radius){
                if(curEnd == s.top().second*2 + s.top().first){
                    curEnd = s.top().first;
                } else{
                    flag = false;
                }
                s.pop();
            } else{
                break;
            }
        }
        // cout << "______" << '\n';
        if(start != curEnd){
            // cout << "ASD\n";
            flag = false;
        }
    
        if(flag){
            cnt++;
        }
        s.push({start, radius});
        cnt++;
    }
    cout << cnt << '\n';
    return 0;
}