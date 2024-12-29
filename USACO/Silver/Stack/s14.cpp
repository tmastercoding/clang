// LVM 9843
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
    int n, r = 0, num;
    pair<string, int> command, commands[1000];
    cin >> n;
    string c;
    for(int idx = 0; idx < n; idx++){
        cin >> c;
        command.first = c;
        if(c == "PUSH" || c == "IFZERO"){
            cin >> num;
            command.second = num;
        } 

        commands[idx] = command;
    }

    int idx = 0;
    stack<int> s;
    while(true){
        if(commands[idx].first == "PUSH"){
            s.push(commands[idx].second);
        } else if(commands[idx].first == "STORE"){
            r = s.top();
            s.pop();
        } else if(commands[idx].first == "LOAD"){
            s.push(r);
        } else if(commands[idx].first == "PLUS"){
            num = s.top();
            s.pop();
            num += s.top();
            s.pop();
            s.push(num);
        } else if(commands[idx].first == "TIMES"){
            num = s.top();
            s.pop();
            num *= s.top();
            s.pop();
            s.push(num);
            
        } else if(commands[idx].first == "IFZERO"){
            num = s.top();
            s.pop();
            // cout << s.top() << '\n';
            if(num == 0){
                // cout << s.top() << '\n';
                idx = commands[idx].second;
                continue;
            }
        } else{
            cout << s.top() << '\n';
            break;
        }
        // cout << s.top() << '\n';
        idx++;

    }

    return 0;
}