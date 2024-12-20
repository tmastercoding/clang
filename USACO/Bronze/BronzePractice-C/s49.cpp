// Air Cownditioning
#include <iostream>
using namespace std;

int main(){
    freopen("2.in", "r", stdin);

    int n;
    int cows[100000][2], dif[100000], groups[100000][2];
    cin >> n;
    for(int idx = 0; idx < n; idx++){
        cin >> cows[idx][0];
    }
    for(int idx = 0; idx < n; idx++){
        cin >> cows[idx][1];
        dif[idx] = cows[idx][0]-cows[idx][1];
        cout << dif[idx] << ' ';
    }
    cout << '\n';

    int cnt = 0;
    int i = 0;
    while(true){

        bool isEmpty = true;
        int g = 0, cur = 0;
        for(int idx = 0; idx < n; idx++){
            // cout << dif[idx] << ' ';
            if(dif[idx] != 0){
                isEmpty = false;
            }
            if(dif[idx] == 0){
                if(cur != 0){
                    groups[g++][1] = idx-1;
                    cur = 0;
                }
            } else if(dif[idx] > 0){
                if(cur == 1){
                    groups[g][1] = idx;
                } else{
                    if(cur == -1){
                        groups[g++][1] = idx-1;
                    }
                    groups[g][0] = idx;
                    cur = 1;
                }
            } else{
                if(cur == -1){
                    groups[g][1] = idx;
                } else{
                    if(cur == 1){
                        groups[g++][1] = idx-1;
                    }
                    groups[g][0] = idx;
                    cur = -1;
                }
            }
            // cout << g << '\n';
        }
        g++;
        // cout << '\n';
        if(isEmpty){
            break;
        }

        for(int idx = 0; idx < g; idx++){

            // cout << groups[idx][0] << '-' << groups[idx][1] << '\n';
            int type = (bool)(dif[groups[idx][0]] > 0);
            int extreme = 0;
            if(!type){
                extreme = 10000;
            }
            // cout << type << '\n';
            for(int jdx = groups[idx][0]; jdx <= groups[idx][1]; jdx++){
                if(type){
                    // cout << dif[jdx] << '\n';
                    if(dif[jdx] > extreme){
                        extreme = dif[jdx];
                    }
                } else{
                    if(dif[jdx] < extreme){
                        extreme = dif[jdx];
                    }
                }
            }
            // cout <<"Extreme: " << extreme << '\n';
            for(int jdx = groups[idx][0]; jdx <= groups[idx][1]; jdx++){
                dif[jdx] -= extreme;
                // cout << dif[jdx] << ' ';
            }
            // cout << '\n';
            cnt += abs(extreme);
        }
        // cout << cnt << '\n';
        // i++;
    }

    cout << cnt << '\n';

    return 0;
}