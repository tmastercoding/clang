#include <iostream>
#include <stack>
using namespace std;

int main(){
    // freopen("art2.in", "r", stdin);
    // freopen("art2.out", "w", stdout);
    int n;
    cin >> n;
    stack<pair<int, int>> s;
    int visit[100001], arr[100001]; 
    pair<int, int> p;
    int cur, ssize, maxDepth = 0, pMaxDepth = 0;
    bool possible = true;
    for(int idx = 0; idx < n; idx++){
        cin >> arr[idx];
    }
    for(int idx = 0; idx < n; idx++){
        cur = arr[idx];
        
        if (cur){
            p.first = cur;
            p.second = 1;
            if(visit[cur]){
                bool found = false;
                ssize = s.size();
                pMaxDepth = 0;
                for(int jdx = 0; jdx < ssize; jdx++){
                    if(s.top().first == cur){
                        found = true;
                        if(s.top().second < pMaxDepth+1){
                            s.top().second = pMaxDepth+1;
                        }
                        p.second = s.top().second;
                        break;
                    }
                    if(s.top().second > pMaxDepth){
                        pMaxDepth = s.top().second;
                    }
                    s.pop();
                }
                if(!found){
                    possible = false;
                    break;
                } 
                s.push(p);

            } else{
                visit[cur] = 1;
                s.push(p);
            }
            if(p.second > maxDepth){
                maxDepth = p.second;
            }
            // cout << maxDepth << '\n';
        } else{
            ssize = s.size();
            for(int jdx = 0; jdx < ssize; jdx++){
                s.pop();
            }
        }
    }
    if(possible){
        cout << maxDepth << '\n';
    } else{
        cout << "-1\n";
    }
    return 0;
}