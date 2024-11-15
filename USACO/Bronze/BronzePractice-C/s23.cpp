// Dining Cows 6168
#include <iostream>
using namespace std;

int main(){
    int size;
    cin >> size;
    int cows[size];
    for(int idx = 0; idx < size; idx++){
        cin >> cows[idx];
    }

    int cur = 1;
    int cnt = 0;
    int cnt1, cnt2;
    bool hasChanged = false;
    if(size > 1){

        for(int idx = 0; idx < size; idx++){
            if(hasChanged){
                if(cows[idx]!= cur){
                    cows[idx] = cur;
                    cnt++;
                }
            } else if(cows[idx] != cur){
                cnt1 = 0, cnt2 = 0;
                for(int jdx = idx; jdx < size; jdx++){
                    if(cows[jdx] == 1){
                        cnt1++;
                    } else{
                        cnt2++;
                    }
                }

                if(cur == 2){
                    if(cnt2 >= cnt1){
                        cows[idx] = 2;
                        cnt++;
                    } else{
                        cur = 1;  
                    }
                } else{
                    if(cnt1 >= cnt2){
                        cows[idx] = 1;
                        cnt++;
                    } else{
                        cur = 2;
                        hasChanged = true;  
                    }
                }
                // for(int idx = 0; idx < size; idx++){
                //     cout << cows[idx] << ' ';
                // }
                // cout << '\n';
                // cout << cnt1 << " " << cnt2 << endl;
            }
        }

    } 
    cout << cnt << '\n';

    return 0;
}
