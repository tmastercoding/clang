#include <iostream>
using namespace std;

int main(){
    long long int size, time;
    cin >> size >> time;
    string exchange;
    cin >> exchange;

    long long int limits[200000];
    long long int milk = 0;
    for(int idx = 0; idx < size; idx++){
        cin >> limits[idx];
        milk+= limits[idx];
    }

    char check = exchange[0];
    bool allSame = true;
    for(int idx = 1; idx < size; idx++){
        if(check != exchange[idx]){
            allSame = false;
            break;
        }
    }

    if(allSame){
        cout << milk <<'\n';
    } else{
        exchange += exchange;
        long long int rLimits[200000];
        int i = 0;
        string rExch;
        for(int idx = 0; idx < size; idx++){
            if(exchange[idx] == 'R' && exchange[idx+size-1] == 'L'){
                for(int jdx = idx; jdx < idx+size; jdx++){
                    rExch += exchange[jdx];
                    if(jdx >= size){
                        rLimits[i++] = limits[jdx-size];
                    } else{
                        rLimits[i++] = limits[jdx];
                    }
                }
                break;
            }
        }
        // cout << rExch << '\n';
        // for(int idx = 0; idx < size; idx++){
        //     cout << rLimits[idx]<< ' ';
        // }
        // cout << '\n';
        char cur = 'R';
        long long int totSub = 0;
        long long int cnt = 0;

        for(int idx = 0; idx < size; idx++){
            if(rExch[idx] == 'R'){
                if(cur == 'R'){
                    cnt += rLimits[idx];
                } else{
                    // cout << cnt << '\n';
                    totSub += min(cnt, time);
                    cur = 'R';
                    cnt = rLimits[idx];
                }
            } else{
                if(cur == 'L'){
                    cnt += rLimits[idx];
                } else{
                    cnt -= rLimits[idx-1];
                    // cout << cnt << '\n';
                    totSub += min(cnt, time);
                    cur = 'L';
                    cnt = 0;
                }
            }
        }
        // cnt -= rLimits[size-1];
        totSub += min(cnt, time);
        cout << milk - totSub << '\n';
    }

    return 0;
}