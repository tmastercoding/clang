// 괄호의 값 2504
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
    string str;
    cin >> str;
    stack<char> s;

    int multiply = 1;
    int tot = 0;
    bool isWork = true;
    for(int idx = 0; idx < str.size(); idx++){
        if(idx > 0){
            if(str[idx-1] == '(' && str[idx] == ')'){
                // cout << "()\n";
                tot += multiply;
            } else if(str[idx-1] == '[' && str[idx] == ']'){
                // cout << "[]\n";
                tot += multiply;
            }
        } 
        if(str[idx] == '('){
            multiply *= 2;
            s.push(str[idx]);
        } else if (str[idx] == '['){
            multiply *= 3;
            s.push(str[idx]);
        } else if(str[idx] == ')'){
            multiply /= 2;
            if(s.empty() || s.top() != '('){
                isWork = false;
                break;
            }
            s.pop();
        } else{
            multiply/=3;
            if(s.empty() || s.top() != '['){
                isWork = false;
                break;
            }
            s.pop();
        }
        // cout << tot << '\n';
    }

    if(isWork && s.empty()){
        cout << tot << '\n';
    } else{
       cout << "0\n";
    }
    return 0;
}