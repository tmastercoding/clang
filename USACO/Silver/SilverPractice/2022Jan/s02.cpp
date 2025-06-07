#include <iostream>
#include <stack>
using namespace std;

int main(){
    int cows[300000] = {};
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> cows[i];
    }

    stack<pair<int, int>> cur, temp;
    long long sum = 0;
    for(int i = 0; i < n; i++){
        int max = 0;
        while(cur.size()){
            if(min(cur.top().first, cows[i]) > max){
                // cout << cur.top().first << ' ' << cows[i] << ' ' << dist<< '\n';
                sum+= i-cur.top().second+1;
            }
            if(cur.top().first > cows[i]){
                temp.push(cur.top());
            }
            if(cur.top().first > max){
                max = cur.top().first;
            }
            cur.pop();
        }

        while(temp.size()){
            cur.push(temp.top());
            temp.pop();
        }
        cur.push({cows[i], i});
    }
    cout << sum << '\n';

    return 0;
}