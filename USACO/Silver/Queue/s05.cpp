#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main(){
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){

        string str;
        deque<char> before, after;

        cin >> str;
        for(int idx = 0; idx < str.size(); idx++){
            if(str[idx] == '<'){
                if(!before.empty()){
                    after.push_front(before.back());
                    before.pop_back();
                }
            } else if(str[idx] == '>'){
                if(!after.empty()){
                    before.push_back(after.front());
                    after.pop_front();
                }
            } else if(str[idx] == '-'){
                if(!before.empty()) before.pop_back();
            } else{
                before.push_back(str[idx]);
            }
        }

        int bSize = before.size(), aSize = after.size();
        for(int idx = 0; idx < bSize; idx++){
            cout << before.front();
            before.pop_front();
        }
        for(int idx = 0; idx < aSize; idx++){
            cout << after.front();
            after.pop_front();
        }
        cout << '\n';
    }
    return 0;
}