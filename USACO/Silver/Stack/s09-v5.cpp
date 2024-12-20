#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
    string text, censor;
    cin >> text >> censor;

    stack<char> s;
    for(int idx = 0; idx < text.size(); idx++){
        s.push(text[idx]);
        if(s.size() >= censor.size()){
            string temp;
            for(int idx = 0; idx < censor.size(); idx++){
                temp += s.top();
                s.pop();
            }
            bool match = true;
            for(int idx = censor.size()-1; idx > -1; idx--){
                if(temp[idx] != censor[censor.size()-idx-1]){
                    match = false;
                }   
            }
            // cout << match <<'\n';
            if(!match){
                for(int idx = temp.size()-1; idx > -1; idx--){
                    s.push(temp[idx]);
                }
            }
        }
    }

    string temp;
    int size = s.size();
    for(int idx = 0; idx < size; idx++){
        temp += s.top();
        // cout << s.top();
        s.pop();
    }
    // cout << temp << '\n';
    for(int idx = size-1; idx > -1; idx--){
        cout << temp[idx];
    }
    cout << '\n';
    return 0;
}