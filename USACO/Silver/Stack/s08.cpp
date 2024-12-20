// 옥상 정원 꾸미기 6198
#include <iostream>
#include <stack>
using namespace std;

int main(){
    int n; 
    cin >> n;
    stack<int> s;
    long long int cur;
    long long int cnt = 0;
    for( long long int idx = 0; idx < n; idx++){
        cin >> cur;
        if(s.empty()){
            s.push(cur);
        } else{
            // if(cur >= s.top()){
            int size = s.size();
            for(int jdx = 0; jdx < size; jdx++){
                if(cur >= s.top()){
                    s.pop();
                } else{
                    break;
                }

            }
            // }
            s.push(cur);
            
        }
        cnt+= s.size()-1;
        // cout <<  cnt << '\n';
        // cout << "T: " << s.top() << '\n';
    }
    cout << cnt << '\n';
    return 0;
}