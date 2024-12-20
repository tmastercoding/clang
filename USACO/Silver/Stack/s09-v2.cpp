// Censoring 10750
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
    freopen("1.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    string s, censor, temp;
    cin >> s >> censor;
    stack<char> token;
    while(true){
        // cout << s << ' ' << temp << '\n';
        int sSize = s.size();
        for(int idx = 0; idx < sSize; idx++){
            if(token.size() == censor.size()){
                for(int jdx = 0; jdx < censor.size(); jdx++){
                    temp.pop_back();
                    token.pop();
                }
            }
            if(s[idx] == censor[token.size()]){
                token.push(s[idx]);
            } else{
                int size = token.size();
                for(int jdx = 0; jdx < size; jdx++){
                    token.pop();
                }
            }
            temp += s[idx];
        }

        if(token.size() == censor.size()){
            for(int jdx = 0; jdx < censor.size(); jdx++){
                temp.pop_back();
                token.pop();
            }
        }
        if(!temp.compare(s)){
            break;
        }
        // cout << temp << '\n';
        int size = token.size();
        for(int idx = 0; idx < size; idx++){
            token.pop();
        }
        s = (string)temp;
        temp.clear();
    }

    cout << temp << '\n';
    return 0;
}