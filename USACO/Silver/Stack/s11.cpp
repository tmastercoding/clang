#include <iostream>
#include <stack>
using namespace std;
 
int main(){
    int n, x;
    stack<int> s;
    cin >> n;
    int maxArea =0, curArea, minHeight = 0;
    for(int idx = 0; idx < n; idx++){
        cin >> x;
        s.push(x);
        if(minHeight == 0){
            minHeight = x;
        } else if(minHeight > x){
            minHeight = x;
        }
 
        curArea = s.size() * minHeight;
        // cout << curArea << '\n';
        if(curArea > maxArea){
            maxArea = curArea;
        } else if(minHeight*(s.size()+1) < maxArea){
            int size = s.size();
            for(int jdx = 0; jdx < size; jdx++){
                s.pop();
                minHeight  = 0;
            }
        }
    }
    if(maxArea < n){
        maxArea = n;
    }
    cout << maxArea << '\n';
    return 0;   
}