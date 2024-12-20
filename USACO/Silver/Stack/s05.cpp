#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
    int t;
    cin >> t;
    int cnt = 0;
    for(int i = 0; i < t; i++){
        string word;
        cin >> word;
        stack<char> s;
        for(char ch: word){
            if(s.empty()){
                s.push(ch);
            } else{
                if(s.top() != ch){
                    s.push(ch);
                } else{
                    s.pop();
                }
            }
        }
        cnt += s.empty();
    }

    cout << cnt << '\n';

    return 0;
}