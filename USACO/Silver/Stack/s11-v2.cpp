#include <iostream>
#include <stack>
using namespace std;

int main(){
    int n, x; 
    cin >> n;
    stack<pair<int, int>> s;
    pair<int, int> temp;
    long long int maxArea = 0, curArea;

    for(int idx = 0; idx < n+1; idx++){
        if(idx == n){
            x = 0;
        } else{
            cin >> x;
        }
        temp.second = idx;
        while(!s.empty() && s.top().first >= x){
            temp.second = s.top().second;

            curArea = (long long int)(idx - s.top().second )* s.top().first;
            if(maxArea < curArea){
                maxArea = curArea;
            }
            // cout << curArea << '\n';
            s.pop();
            // }
        }
        temp.first = x;
        s.push(temp);
    }
    if(n > maxArea){
        maxArea = n;
    }
    cout << maxArea << '\n';
    return 0;
}