#include <iostream>
#include <string>
using namespace std;

int main(){
    // freopen("2.in", "r", stdin);
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        int size, k;
        cin >> size >> k;
        string cows;
        cin >> cows;
        string output = "";
        int cnt = 0;
        for(int idx = 0; idx < size; idx++){
            output += '.';
        }
        for(int idx = 0; idx < size; idx++){
            // cout << cows[idx] << '\n';
            int start = idx-k, end = idx+k+1;
            if(start < 0){
                start = 0;
            }
            if(end > size){
                end = size;
            }
            bool found = false;
            for(int jdx = end-1; jdx > start-1; jdx--){
                if(output[jdx] == cows[idx]){
                    found = true;
                    break;
                }
            }
            if(!found){
                if(idx+k > size-1 || output[idx+k] != '.'){
                    int start = idx-k, end = idx+k+1;
                    if(start < 0){
                        start = 0;
                    }
                    if(end > size){
                        end = size;
                    }
                    for(int jdx = end-1; jdx >start-1; jdx--){
                        if(output[jdx] == '.'){
                            output[jdx] = cows[idx];
                            cnt++;
                            break;
                        }
                    }
                } else{
                    output[idx+k] = cows[idx];
                    cnt++;
                }
            }
        }

        cout << cnt << '\n' << output << '\n';
    }
    return 0;
}