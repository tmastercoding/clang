#include <iostream>
#include <stack>
using namespace std;

int main(){
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);

    cout << s.top() << '\n';
    s.pop();
    cout << s.top() << '\n';
    s.pop();

    cout << s.size() << '\n';
    s.pop();

    if(s.empty()){
        cout << "stack is empty\n";
    }

    return 0;
}