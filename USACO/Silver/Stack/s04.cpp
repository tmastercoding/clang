// 괄호 9012
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){

        string pStr;
        cin >> pStr;
        stack<char> s;
        
        bool vps = true;
        for(int idx = 0; idx < pStr.size(); idx++){
            if(pStr[idx] == '('){
                s.push('(');
            } else{
                if(!s.empty()){
                    s.pop();
                } else{
                    vps = false;
                    break;
                }
            }
            // cout << s.size() << '\n';
        }
        if(s.empty() && vps){
            cout << "YES\n";
        } else{
            cout << "NO\n";
        }
    }

    return 0;
}