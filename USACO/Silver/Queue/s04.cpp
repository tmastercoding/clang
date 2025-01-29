#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    deque<int> d;
    int n, num;
    string command;
    cin >> n;

    for(int idx = 0; idx < n; idx++){
        cin >> command;
        if(command == "push_back"){
            cin >> num;
            d.push_back(num);
        } else if(command == "push_front"){
            cin >> num;
            d.push_front(num);
        } else if(command == "front"){
            if(d.empty()){
                cout <<"-1\n";
            } else{
                cout << d.front() << '\n';
            }
        } else if(command == "back"){
            if(d.empty()){
                cout <<"-1\n";
            } else{
                cout << d.back() << '\n';
            }
        } else if(command == "empty"){
            cout << d.empty() << '\n';
        } else if(command == "size"){
            cout << d.size() << '\n';
        } else if(command == "pop_front"){
            if(d.empty()){
                cout <<"-1\n";
            } else{
                cout << d.front() << '\n';
                d.pop_front();
            }

        } else{
            if(d.empty()){
                cout <<"-1\n";
            } else{
                cout << d.back() << '\n';
                d.pop_back();
            }

        }
    }

    return 0;
}