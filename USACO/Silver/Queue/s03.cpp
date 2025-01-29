#include <iostream>
#include <queue>
using namespace std;

int main(){
    int n, k, rem;
    cin >> n >> k;
    queue<int> q, temp, out;
    
    for(int idx = 1; idx <= n; idx++){
        q.push(idx);
    }

    while(true){
        if(q.empty()){
            break;
        }
        rem = k;
        if(q.size() < k){
            rem = k%q.size();
            if(rem == 0){
                rem = q.size();
            }
        }
        for(int idx = 0; idx < rem-1; idx++){
            temp.push(q.front());
            q.pop();
        }
        out.push(q.front());
        q.pop();
        int s = temp.size();
        for(int i = 0; i < s; i++){
            q.push(temp.front());
            temp.pop();
        }
    }
    cout << "<";
    for(int i = 0; i < n-1; i++){
        cout << out.front() << ", ";
        out.pop();
    }
    cout << out.front() << ">\n";
    return 0;
}