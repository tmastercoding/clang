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
    for(int idx = 0; idx < size; idx++){
        if(cows[idx] != cur){
            if(hasChanged){
                cows[idx] = cur;
                cnt++;
            } else{
                cnt1 = 0, cnt2 = 0;
                for(int jdx = idx; jdx < size; jdx++){
                    if(cows[jdx] == 1){
                        cnt1++;
                    } else{
                        cnt2++;
                    }
                }

                if(cur == 2){
                    if(cnt2 > cnt1){
                        cows[idx] = 2;
                        cnt++;
                    } else{
                        cur = 1;  
                    }
                } else{
                    if(cnt1 > cnt2){
                        cows[idx] = 1;
                        cnt++;
                    } else{
                        cur = 2;
                        hasChanged = true;  
                    }
                }
            }
        }
    }

    cout << cnt << '\n';

    return 0;
}
