// 제로 10773

#include <iostream>
#include <stack>
using namespace std;

int main(){
    stack<int> s;
    int n, temp;
    long long sum = 0;

    cin >> n;

    for(int idx = 0; idx < n; idx++){
        cin >> temp;
        if(temp == 0){
            s.pop();
        } else{
            s.push(temp);
        }
    }

    int size = s.size();
    for(int idx = 0; idx < size; idx++){
        sum += s.top();
        s.pop();
    }

    cout << sum << '\n';
    return 0;
}