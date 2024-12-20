#include <iostream>
#include <stack>
using namespace std;

int main(){
    int n, x;
    cin >> n;
    stack<pair<int, int>> s;
    pair<int, int> temp;
    for(int idx = 0; idx < n; idx++){
        cin >> x;
        temp.first = x;
        temp.second = idx;


        bool hasFound = false;
        int size = s.size();
        for(int jdx = size; jdx > -1; jdx--){
            if(!s.empty()){
                if(s.top().first < x){
                    cout << s.top().second+1 << ' ';
                    hasFound = true;
                    break;
                }
                s.pop();
            } else{
                break;
            }
        }

        if(!hasFound){
            cout <<"0 ";
        }
        s.push(temp);
            

    }
    cout << '\n';
    return 0;
}