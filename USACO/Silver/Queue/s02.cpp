#include <iostream>
#include <queue>
using namespace std;

queue<int> q;
int main(){
    int n;
    cin >> n;
    for(int idx = 1; idx <= n; idx++){
        q.push(idx);
    }

    int idx = 0;
    while(true){
        if(q.size()==1){
            cout << q.front() << '\n';
            break;
        }
        // cout << q.front() << '\n';
        if(!(idx & 1)){
            q.pop();
        } else {
            q.push(q.front());
            q.pop();
        }
        if(q.size()==1){
            cout << q.front() << '\n';
            break;
        }
        idx++;
    }

    return 0;
}