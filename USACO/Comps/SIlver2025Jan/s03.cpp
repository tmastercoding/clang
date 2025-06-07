#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    int map[1001][1001];
    int post[2001] = {}, org[2001] = {}, dict[2001] = {};
    cin >> n;
    for(int y = 0; y < n; y++){
        for(int x = 0; x < n; x++){
            cin >> map[y][x];
            post[map[y][x]]++;
        }
    }

    for(int y = 1; y <= n; y++){
        for(int x = 1; x <= n; x++){
            org[y+x]++;
        }
    }

    for(int idx = 2; idx <n*2; idx++){
        cout << idx << ' ' <<  post[idx] << ' ' << org[idx] << '\n';
        if(post[idx] != org[idx]){
            // cout<<"________\n";
            for(int jdx = n*2; jdx > 1; jdx--){
                // cout << jdx << ' ' <<post[jdx] << ' ' << org[jdx] << '\n';
                if(post[jdx] == org[idx] && post[jdx] != org[jdx]){
                    int temp = post[jdx];
                    post[jdx] = post[idx];
                    post[idx] = temp;

                    dict[jdx] = idx;
                    dict[idx] = jdx;
                    break;
                }
            }
            // cout<<"________\n";
        } else{
            dict[idx] = idx;
        }
        cout<<"________\n";
        for(int y = 0; y < n; y++){
            for(int x = 0; x < n; x++){
                cout << dict[map[y][x]] << ' ';
            }
            cout << '\n';
        }
    }
    
    return 0;
}