#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main(){ 
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    deque<int> q;
    int t, num;
    cin >> t;
    string command;
    for(int i = 0; i < t; i++){
        cin >> command;
        if(command == "push"){
            cin >> num;
            q.push_back(num);
        } else if(command == "pop"){
            if(!q.empty()){
                cout << q.front() << '\n';
                q.pop_front();
            } else{
                cout << "-1\n";
            }
        } else if(command == "size"){
            cout << q.size() << '\n';
        } else if(command == "empty"){
            cout << q.empty() << '\n';
        } else if(command == "front"){
            if(!q.empty()){
                cout << q.front() << '\n';
            } else{
                cout << "-1\n";
            }
        } else{
            if(!q.empty()){
                cout << q.back() << '\n';
            } else{
                cout << "-1\n";
            }
        }
    }
    return 0;
}