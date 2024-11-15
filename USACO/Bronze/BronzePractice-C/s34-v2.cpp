#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int main(){
    // freopen("4.in", "r", stdin);

    long long int size, time;
    cin >> size >> time;
    string exchange;
    cin >> exchange;

    long long int limits[200000];
    long long int drought[200000];
    char exch[200000];
    long long int milk = 0;
    for(int idx = 0; idx < size; idx++){
        cin >> limits[idx];
        exch[idx] = exchange[idx];
        milk += limits[idx];
    }

    long long int cnt = 0;
    for(long long int idx = 0; idx < size; idx++){
        bool hasFound = false;
        if(idx == 0){
            if(exch[size-1] == 'R' || exch[idx+1] == 'L'){
                continue;
            } else{
                drought[cnt] = limits[idx];
                hasFound = true;
            }
        } else if(idx == size-1){
            if(exch[idx-1] == 'R' || exch[0] == 'L'){
                continue;
            } else{
                drought[cnt] = limits[idx];
                hasFound = true;
            }
        } else{
            if(exch[idx-1] == 'R' || exch[idx+1] == 'L'){
                continue;
            } else{
                drought[cnt] = limits[idx];
                hasFound = true;
            }
        }
        if(hasFound){
            if(exch[idx] == 'L'){
                for(int jdx = idx-1; jdx > -1; jdx--){
                    if(exch[jdx] == 'R'){
                        break;
                    }
                    drought[cnt] += limits[jdx];
                }
            } else{
                for(int jdx = idx+1; jdx < size; jdx++){
                    if(exch[jdx] == 'L'){
                        break;
                    }
                    drought[cnt] += limits[jdx];
                }
            }
            cnt++;
            // cout << drought[idx] << '\n';
        }
    }
    // cout << milk << '\n';
    for(long long int idx = 0; idx < cnt; idx++){
        // cout << drought[idx] << '\n';
        if(drought[idx] >= time){
            milk -= time;
            // cout << time << '\n';
        } else{
            milk -= drought[idx]-1;
            // cout << limits[drought[idx]] << '\n';
        }
    }
    cout << milk << '\n';
    return 0;
}
