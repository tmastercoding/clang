#include <iostream>
#include <string>
using namespace std;

int main(){
    int n, arr[100000];
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int pos = 0;
    char dir = 'R';
    string line;
    while(true){
        if(pos < 0) break;
        
        if(dir == 'R'){
            if(pos < n){
                if(arr[pos+1] > 1){
                    arr[pos]--;
                    pos++;
                } else{
                    dir = 'L';
                    arr[pos]--;
                    pos--;
                }
            } else{
                dir = 'L';
                arr[pos]--;
                pos--;
            }
        } else{
            if(arr[n-1] == 1){
                arr[pos]--;
                pos--;
            } else if(0 < pos){
                if(arr[pos-1] > 1){
                    arr[pos]--;
                    pos--;
                } else{
                    dir = 'R';
                }
            } else{
                dir = 'R';
                arr[pos]--;
                pos++;
            }
        }
        // cout << dir;
        line += dir;
        for(int idx = 0; idx < n; idx++){
            cout << arr[idx] << ' ';
        }
        cout << '\n';
    }
    cout << line << '\n';
    return 0;
}