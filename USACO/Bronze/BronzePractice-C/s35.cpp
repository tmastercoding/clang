#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int size, qSize;
    cin >> size >> qSize;
    int closing[200005], visit[200005], dif[200005], farms[1000005] = {0, };
    for(int idx = 0; idx < size; idx++){
        cin >> closing[idx];
    }
    for(int idx = 0; idx < size; idx++){
        cin >> visit[idx];
    }
    int i = 0;
    for(int idx = 0; idx < size; idx++){
        dif[idx] = closing[idx]-visit[idx];
    }

    sort(dif, dif+size);
    
    // for(int idx = 0; idx < size; idx++){
    //     cout << dif[idx] << ' ';
    // }
    // cout << '\n';
    int latest = dif[size-1];
    for(int idx = 0; idx < latest; idx++){
        if(idx >= dif[i]){
            while(i < size){
                if(dif[i] > idx){
                    break;
                }
                i++;
            }
        }
        if(idx < dif[i]){
            farms[idx] = size-i;
        } 
    }
    // for(int idx = 0; idx < 10; idx++){
    //     cout << farms[idx] << ' ';
    // }
    // cout << '\n';
    int goal, start;
    for(int jdx = 0; jdx < qSize; jdx++){
        cin >> goal >> start;
        
        if(farms[start] >= goal){
            cout << "YES\n";
        } else{
            cout << "NO\n";
        }
    }
    
    return 0;
}