#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main(){
    int t;
    cin >> t;
    for(int cas = 0; cas < t; cas++){
        
        int n, arr[1000000] = {}, maxSum[1000000] = {};
        cin >> n;
        set<int> s;
        vector<int> pos[1000000];
        for(int i = 0; i < n; i++){
            cin >> arr[i];
            s.insert(arr[i]);
            pos[arr[i]].push_back(i);
        }
        for(int i = n-1; i > -1; i--){
            maxSum[i] = max(maxSum[i+1], arr[i]);
        }
    
        auto it = s.rbegin();
        int start = 0, last = 0;
        bool firstTerm = true;
    
        while(it != s.rend()){
            int large = *it;
            it++;
            last = pos[large].back();
    
            bool flag = false;
            for(int i = pos[large].size()-1; i > -1; i--){
                if(pos[large][i] >= start){
                    if(firstTerm){
                        cout << large;
                        firstTerm = false;
                    } else{
                        cout << ' ' << large;
                    }
                    flag = true;
                } else{
                    break;
                }
            }
            if(!flag) continue;
            int target = -1;
            for(int i = last-1; i >= start; i--){
                if(arr[i] == large){
                    start = i+i;
                    break;
                } 
                if(arr[i] >= maxSum[last+1]){
                    target = i;
                }
            }
    
            if(target != -1){
                arr[pos[large].back()] = 0;
                vector<int> rrmax(n+1); 
                rrmax[n] = -1;
                // rrmax[n] = -1;
                for(int i = n-1; i >= start; i--){
                    rrmax[i] = max(rrmax[i+1], arr[i]);
                }
                for(int i = start; i < n; i++){
                    if(arr[i] && rrmax[i] == arr[i]){
                        if(firstTerm){
                            cout << arr[i];
                            firstTerm = false;
                        } else{
                            cout << ' ' << arr[i];
                        }
                    }
                }
                break;
            }
            start = last+1;
        }
        cout << '\n';
    }
    return 0;
}