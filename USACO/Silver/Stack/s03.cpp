// Cleaning the Dishes 5957
#include <iostream>
#include <stack>
using namespace std;

int main(){
    int n;
    cin >> n;
    stack<int> dirty, washed, clean;

    for(int idx = n; idx > 0; idx--){
        dirty.push(idx);
    }

    int command, dishes;
    while(true){
        cin >> command >> dishes;
        if(command == 1){
            for(int idx = 0; idx < dishes; idx++){
                washed.push(dirty.top());
                dirty.pop();
            }
        } else{
            for(int idx = 0; idx < dishes; idx++){
                clean.push(washed.top());
                washed.pop();
            }
        }
        if(clean.size() == n){
            break;
        }
    }

    for(int idx = 0; idx < n; idx++){
        cout << clean.top() << '\n';
        clean.pop();
    }

    return 0;
}