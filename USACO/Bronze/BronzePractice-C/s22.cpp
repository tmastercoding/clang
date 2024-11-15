// Payback 6106
#include <iostream>
using namespace std;

int main(){
    int size;
    cin >> size;

    int debts[size];
    for(int idx = 0; idx < size; idx++){
        cin >> debts[idx];
    }

    int cur = 0;
    int dist = 0;
    int idx = 0;
    int need = 0, needIdx = 0;
    for(int idx =0; idx < size; idx++){
        dist++;
        // cout << need << '\n';
        if(idx == size-1 && need == 0){
            break;
        } 
        if(debts[idx] > 0){
            cur += debts[idx];
            debts[idx] = 0;
        }
        if(debts[idx] < 0 && !need ){
            if(debts[idx]+ cur >= 0){
                cur += debts[idx];
                debts[idx] = 0;
            } else{
                need = debts[idx];
                needIdx = idx;
                debts[idx] = 0;
            }
        } else if(debts[idx] < 0 && need){
            need += debts[idx];
            debts[idx] = 0;
        }
        if(need+cur >= 0 && need != 0){
            dist += (idx-needIdx)*2;
            // idx = needIdx;
            cur += need;
            need = 0;
        }
    }
        
    // cout << cur << endl;
    cout << dist << '\n';
    return 0;   
}