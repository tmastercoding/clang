#include <iostream>
#include <stack>
using namespace std;

int main(){
    freopen("art2.in", "r", stdin);
    freopen("art2.out", "w", stdout);
    int n, x, check[100001] = {0}; 
    cin >> n;
    bool work = true;
    stack<int> s;
    for(int idx = 0; idx < n; idx++){
        cin >> x;
        
        if(x == 0){
            while(!s.empty()){
                check[s.top()] = -1;
                s.pop();
            }
        }
        if(check[x] == 1){
            while(!s.empty() && s.top() != x){
                check[s.top()]++;
                s.pop();
            }
        } else if(check[x] > 1){
            cout << "-1\n";
            work = false;
            break;
        } else if(check[x] == -1){
            cout << "-1\n";
            work = false;
            break;
        }
        if(x > 0){
            s.push(x);
            if(check[x] == 0){
                check[x]++;
            }

        }
    }

    int max = 0;
    for(int idx = 0; idx < 6; idx++){
        if(check[idx] > max){
            max = check[idx];
        }
    }
    if(work){
        cout << max << '\n';
    }
    return 0;
}