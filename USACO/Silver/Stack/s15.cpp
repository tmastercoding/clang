// 과제는 끝나지 않아! 17952
#include <iostream>
#include <stack>
using namespace std;

int main(){
    int n, is, time, score;
    stack<pair<int, int>> s;
    pair<int, int> p;
    cin >> n;
    int tot = 0;
    for(int idx = 0; idx < n; idx++){
        cin >> is;
        if(is){
            cin >> score >> time;
            time--;
            p.first = time;
            p.second = score;
            if(time){
                s.push(p);
            } else{
                tot += score;
            }
            
        } else{
            if(s.size()){
                s.top().first--;
                if(!s.top().first){
                    tot += s.top().second;
                    s.pop();
                }
            }
        }
    }
    cout << tot << '\n';
    return 0;
}