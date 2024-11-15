// The last battle 19747
#include <iostream>
#include <vector>
using namespace std;

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int size = 0;
    int temp;
    cin >> size;
    vector<int> people, martian;
    int move[200000] = {0, };

    for(int idx = 0; idx < size; idx++){
        cin >> temp;
        martian.push_back(temp);
        people.push_back(idx+1);
    }

    int cnt = 0;
    for(int idx = 0; idx < size; idx++){
        // cout << idx << " " << martian[idx]-1 << '\n';
        if(idx == martian[idx]-1){
            cnt = 0;
        } else if(idx > martian[idx]-1){
            cnt = idx - martian[idx]+1;
        } else{
            cnt = size +idx - martian[idx]+1 ;
        }
        // cout << cnt << '\n';
        move[cnt] += 1;
    }

    // for(int idx = 0; idx < size; idx++){
    //     cout << idx << ": "<< move[idx] << '\n';
    // }

    bool hasFound = false;
    for(int idx = 0; idx < size; idx++){
        if(!move[idx]){
            hasFound = true;
            cout << idx << '\n';
            break;
        }
    }
    if(!hasFound){
        cout << -1 << '\n';
    }

    return 0;
}   
