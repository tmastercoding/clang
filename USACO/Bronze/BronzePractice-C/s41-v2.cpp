#include <iostream>
#include <string>
using namespace std;

int main(){
    freopen("1.in", "r", stdin);
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        int n, m;
        cin >> n >> m;
        string temp;
        int result;

        int input[100][101];
        for(int idx = 0; idx < m; idx++){
            cin >> temp >> result;
            input[idx][0] = result;
            for(int jdx = 0; jdx < n; jdx++){
                input[idx][jdx+1] = temp[jdx]-'0'; 
            }
        }

        // if pos = val return 1
        int conditions[100], cur[100];
        int curVal;
        bool lie = false;
        for(int idx = 0; idx < m; idx++){
            for(int jdx = 1; jdx <= n; jdx++){
                // cout << input[idx][0] << '\n';
                if(input[idx][0] == 0){
                    // cout << "asdf\n";
                    // curVal = -1;
                    curVal = !(input[idx][jdx]);
                    // cout << curVal << '\n';
                } else{
                    curVal = input[idx][jdx];
                    // curVal = -1;
                    // if(input[idx][jdx] == 0){
                    //     curVal = -1;
                    // }
                }
                // cout << "LOG: " << conditions[0] << " " << conditions[1] << '\n';
                // if(idx > 0 && conditions[jdx-1] != curVal){
                //     lie = true;
                //     break;
                // } 
                // conditions[jdx-1] = curVal;
                cur[jdx-1] =  curVal;
            }
            if(idx == 0){
                for(int jdx = 0; jdx < n; jdx++){
                    conditions[jdx] = cur[jdx];
                }
            } else{
                bool valid = false;
                for(int jdx = 0; jdx < n; jdx++){
                    if(conditions[jdx] == cur[jdx]){
                        valid = true;
                        break;
                    }
                    if(cur[jdx] == -1 || conditions[jdx] == -1){
                        valid = true; 
                        break;
                    }
                }
                if(!valid){
                    lie = true;
                    break;
                }
            }
        }

        if(lie){
            cout << "LIE\n";
        } else{
            cout << "OK\n";
        }
    }
    return 0;
}