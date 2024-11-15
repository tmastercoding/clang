#include <iostream>
#include <string>
using namespace std;

// RECURSIVE 

int main(){
    freopen("7.in", "r", stdin);

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

        // conditions
        // if b[idx] == ival: return 1;

        bool isOverlap = false;
        for(int idx = 0; idx < m; idx++){
            for(int jdx = 0; jdx < m; jdx++){
                if(jdx == idx){
                    continue;
                }
                isOverlap = true;
                for(int kdx = 1; kdx <= n; kdx++){
                    if(input[idx][kdx] != input[jdx][kdx]){
                        isOverlap = false;
                        break;
                    }
                }
                if(isOverlap){
                    if(input[idx][0] == input[jdx][0]){
                        isOverlap = false;
                    } else{
                        break;
                    }
                }
            }
            if(isOverlap){
                break;
            }
        }

        if(isOverlap){
            cout << "LIE\n";
        } else{
            bool isValid = true;
            for(int idx = 0; idx < n; idx++){
                for(int ival = 0; ival <= 1; ival++){
                    for(int ri = 0; ri <= 1; ri++){
                        // else if
                        for(int jdx = 0; jdx < n; jdx++){
                            if(jdx == idx){
                                continue;
                            }
                            for(int jval = 0; jval <= 1; jval++){
                                for(int rj = 0; rj <= 1; rj++){
                                    for(int re = 0; re <= 1; re++){
                                        isValid = true;
                                        for(int kdx = 0; kdx < m; kdx++){
                                            int rval;
                                            if(input[kdx][idx+1] == ival){
                                                rval = ri;
                                            } else if(input[kdx][jdx+1] == jval){
                                                rval = rj;
                                            } else{
                                                rval = re;
                                            }
                                            // cout << rval << ' ' << input[kdx][0] << '\n'; 
                                            if(rval != input[kdx][0]){
                                            
                                                isValid = false;
                                                break;
                                            }
                                        }
                                        if(isValid){
                                            // cout << idx << ' ' << ival << ' ' << ri << ' ' << jdx << ' ' << jval << ' '<< rj << '\n'; 
                                            break;
                                        }
                                    }
                                    if(isValid){
                                        // cout << idx << ' ' << ival << ' ' << ri << ' ' << jdx << ' ' << jval << ' '<< rj << '\n'; 
                                        break;
                                    }
                                }
                                if(isValid){
                                    break;
                                }
                            }
                            if(isValid){
                                break;
                            }
                        }
                        if(isValid){
                            break;
                        }
                    }
                    if(isValid){
                        break;
                    }
                }
                if(isValid){
                    break;
                }
            }
            if(isValid){
                cout << "OK\n";
            } else{
                cout << "LIE\n";
            }
        }
    }
    return 0;
}