// 스택 10828
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int n;
    cin >> n;
    stack<int> s;
    string command;

    for(int idx = 0; idx < n; idx++){
        cin >> command;
        int num;
        if(command == "push"){
            cin >> num;
            s.push(num);
        } else if(command == "pop"){
            if(!s.empty()){
                cout << s.top() << '\n';
                s.pop();
            } else{
                cout << -1 << '\n';
            }
        } else if(command == "size"){
            cout << s.size() << '\n';
        } else if(command == "empty"){
            cout << s.empty() << '\n';
        } else{
            if(!s.empty()){
                cout << s.top() << '\n';
            } else{
                cout << -1 << '\n';
            }
        }
    }

    return 0;
}