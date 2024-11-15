#include <iostream>
using namespace std;

int main(){
    int size = 0;
    cin >> size;
    int cows[size];
    for(int idx = 0; idx < size; idx++){
        cin >> cows[idx];
    }

    int cnt = 0;
    int cnt1 = 0, cnt2 = 0;
    int cur = 1;
    bool hasChanged = false;
    for(int idx = 0; idx < size; idx++){
        if(cows[idx]!= cur){
            if (hasChanged){
                cows[idx] = cur;
                cnt++;
            } else{

                cnt1 = 0;
                cnt2 = 0;
                for(int jdx = idx; jdx < size; jdx++){
                    if(cows[jdx] == 1){
                        cnt1++;
                    } else{
                        cnt2++;
                    }
                }
                if(cnt1 >= cnt2){
                    if(cows[idx] != 1){
                        cows[idx] = 1;
                        cnt++;
                    }
                } else{
                    if(cows[idx] != 2){
                        cows[idx] = 2;
                        cnt++;
                    } else{
                        cur = 2;
                        hasChanged = true;
                    }
                }
            }
            // for(int jdx = 0; jdx < size; jdx++){
            //     cout << cows[jdx] << " ";
            // }
            // cout << '\n';
        }
    }
    cout << cnt << '\n';
    return 0;
}