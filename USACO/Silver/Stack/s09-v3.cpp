// Censoring 10750
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
    freopen("3.in", "r", stdin);

    string s, censor, temp;
    cin >> s >> censor;
    
    stack<char> token;
    int sameFor = 0;
    while(true){
        // cout << s << ' ' << temp << '\n';
        for(int idx = 0; idx < s.size(); idx++){
            if(token.size() == censor.size()){
                cout << idx << '\n';
                int tSize = token.size();
                for(int jdx = 0; jdx < tSize; jdx++){
                    temp.pop_back();
                    token.pop();
                }
            }
            if(s[idx] == censor[token.size()]){
                token.push(s[idx]);
            } else{
                string token2;
                // cout << s[idx] << ' ' << idx << '\n';
                int tSize = token.size();
                for(int jdx = 0; jdx < tSize; jdx++){
                    if(jdx!= tSize-1){
                        token2 += token.top();
                    }
                    token.pop();
                }
                cout << token2 << '\n';
                for(int jdx = tSize-2; jdx > -1; jdx--){
                    token.push(token2[jdx]);
                }
            }
            temp.push_back(s[idx]);
        }
        int tSize = token.size();
        for(int idx = 0; idx < tSize; idx++){
            token.pop();
        }
        if(!temp.compare(s)){
            break;
            // if(sameFor < 10){
            //     sameFor++;
            // } else{
            //     break;
            // }
        }
        s = temp;
        temp.clear();
        
    }

    cout << temp << '\n';
    return 0;
}