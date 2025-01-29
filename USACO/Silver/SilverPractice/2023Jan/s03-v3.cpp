#include <iostream>
#include <string>
using namespace std;

int main(){
    int n, arr[100001] = {};
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int pos = 0;
    char dir = 'R';
    bool done = false;
    string line;
    while(true){
        if(dir == 'R'){
            if(pos < n){
                arr[pos]--;
                pos++;
            } else{
                dir = 'L';            
            }
        }
        if(dir == 'L'){
            if(0 < pos){
                if(arr[pos-1] > 1){
                    arr[pos-1]--;
                    pos--;
                } else{
                    if(arr[pos] > 1){
                        dir = 'R';
                        arr[pos]--;
                        pos++;
                    } else{
                        if(arr[pos-1] == 0){
                            done = true;
                        } else{
                            arr[pos-1]--;
                            pos--;
                        }
                    }
                }
            } else{
                if(arr[pos] == 0){
                    done = true;
                }
            }
        }

        if(done) break;
        line += dir;
        // cout << pos << ' ' << dir << '\n';
        // for(int idx = 0; idx < n; idx++){
        //     cout << arr[idx] << ' ';
        // }
        // cout << '\n';
    }
    cout << line << '\n';
    return 0;
}