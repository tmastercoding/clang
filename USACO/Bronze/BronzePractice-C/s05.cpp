// Cow Tipping 14457
#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

int check(string* arr, int size);

int main(){
    int size = 0;
    cin >> size;
    string* arr;
    string temp;
    int cnt = 0;
    int toggle = 0;
    int maxToggle = 0;
    int maxIdx, maxJdx;
    arr = (string *)malloc(sizeof(string) * size);
    for(int idx = 0; idx < size; idx++){
        cin >> temp;
        arr[idx] = temp;
    }

    while(1){
        for(int idx = size-1; idx >= 0; idx--){
            for(int jdx = size-1; jdx >= 0; jdx--){
                if (arr[idx][jdx] == '1'){
                    for(int tidx = 0; tidx <= idx; tidx++){
                        for(int tjdx = 0; tjdx <= jdx; tjdx++){
                            // cout << arr[tidx][tjdx] << endl;
                            if (arr[tidx][tjdx] == '1'){
                                arr[tidx][tjdx] = '0';
                            } else{
                                arr[tidx][tjdx] = '1';
                            }
                        }
                    }
                    cnt++;
                    if(check(arr, size)){
                        break;
                    }
                }

            }
            // cout << '\n';
        }
        break;

        // cout << maxToggle << endl;
    }

    cout << cnt << endl;
    return 0;
}

int check(string* arr, int size){
    for(int idx = 0; idx <  size; idx++){
        for(int jdx = 0; jdx < size; jdx++){
            if(arr[idx][jdx] == '1'){
                return 0;
            }
        }
    }
    return 1;
}
        // maxToggle = 0;
        // for(int idx = size-1; idx >= 0; idx--){
        //     for(int jdx = size-1; jdx >= 0; jdx--){
        //         toggle = 0;
        //         for(int tidx = 0; tidx <= idx; tidx++){
        //             for(int tjdx = 0; tjdx <= jdx; tjdx++){
        //                 // cout << arr[tidx][tjdx] << endl;
        //                 if (arr[tidx][tjdx] == '1'){
        //                     toggle++;
        //                 } else{
        //                     toggle--;
        //                 }
        //             }
        //         }
        //         if (toggle > maxToggle){
        //             maxToggle = toggle;
        //             maxIdx = idx;
        //             maxJdx = jdx;
        //         }
        //         // cout << arr[idx][jdx];

        //     }
        //     // cout << '\n';
        // }
        // for(int tidx = 0; tidx <= maxIdx; tidx++){
        //     for(int tjdx = 0; tjdx <= maxJdx; tjdx++){
        //         // cout << arr[tidx][tjdx] << endl;
        //         if (arr[tidx][tjdx] == '1'){
        //             arr[tidx][tjdx] = '0';
        //         } else{
        //             arr[tidx][tjdx] = '1';
        //         }
        //     }
        // }
        // // cout << maxToggle << endl;
        // cnt++;
        // if(check(arr, size)){
        //     break;
        // }