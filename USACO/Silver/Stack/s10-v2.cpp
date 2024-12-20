// Nearest Smaller Values
#include <iostream>
#include <stack>
using namespace std;

int main(){
    int arr[200000], n, x;
    stack<int> s, out;
    cin >> n;
    for(int idx = 0; idx < n; idx++){
        cin >> arr[idx];
    }

    for(int j = n-1; j > -1; j--){
        int cur = arr[j];
        for(int idx = 0; idx < j; idx++){
            s.push(arr[idx]);
        }
        bool isDone = false;
        for(int idx = j; idx > -1; idx--){
            if(!s.empty()){
                if(s.top()< cur && !isDone){
                    out.push(idx);
                    isDone = true;
                    cur = s.top();
                }
                s.pop();
            }
        }
        if(!isDone){
            out.push(0);
        }
    }
    // for(int idx = n-1; idx > -1; idx--){
    //     if(!s.empty()){
    //         if(arr[idx] < s.top()){
    //             cout << idx+1 << ' ';
    //             out.push(idx+1);
    //             s.pop();
    //         }
    //     }
    //     s.push(arr[idx]);
    // }

    for(int idx = 0; idx < n; idx++){
        if(!out.empty()){
            cout << out.top() << ' ';
            out.pop();
        } 
    }
    cout << '\n';
    return 0;
}