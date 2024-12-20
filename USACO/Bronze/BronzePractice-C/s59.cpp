#include <iostream>
using namespace std;

int main(){
    int n;
    char dir;
    long long int cows[50][3], minCur,cur, difx, dify, results[50];
    cin >> n;
    for(int idx = 0; idx < n; idx++){
        cin >> dir;
        cin >> cows[idx][1] >> cows[idx][2];
        cows[idx][0] = dir;
    }
    
    for(int idx = 0; idx < n; idx++){
        minCur = 1000000001;
        for(int jdx = 0; jdx < n; jdx++){
            // cout << "------" << idx << ' ' << jdx << '\n';
            cur = -1;
            if(idx == jdx){
                continue;
            }
            // dir same
            if(cows[idx][0] == cows[jdx][0]){
                // cout<<"asdf\n";
                if(cows[idx][0] == 'N'){
                    // x same
                    if(cows[idx][1] == cows[jdx][1]){
                        // y smaller
                        if(cows[idx][2] < cows[jdx][2]){
                            cur = cows[jdx][2]-cows[idx][2];
                        }
                    } 
                } else{
                    // y same
                    if(cows[idx][2] == cows[jdx][2]){
                        // y smaller
                        if(cows[idx][1] < cows[jdx][1]){
                            cur = cows[jdx][1]-cows[idx][1];
                        }
                    } 
                }
            } else{
                if(cows[idx][0] == 'N'){
                    // x bigger
                    if(cows[idx][1] > cows[jdx][1]){
                        // y smaller
                        if(cows[idx][2] < cows[jdx][2]){
                            difx = cows[idx][1]-cows[jdx][1];
                            dify = cows[jdx][2]-cows[idx][2];
                            // jdx gets there first
                            if(difx < dify ){
                                cur = dify;
                            }
                        }
                    }
                } else{
                    // x smaller
                    if(cows[idx][1] < cows[jdx][1]){
                        // y bigger
                        if(cows[idx][2] > cows[jdx][2]){
                            // cout << "met\n";
                            difx = cows[jdx][1]-cows[idx][1];
                            dify = cows[idx][2]-cows[jdx][2];
                            // cout << difx << ' ' << dify << '\n';
                            // jdx gets there first
                            if(dify < difx ){
                                cur = difx;
                            }
                        }
                    }
                }

            }   
            // cout << cur << '\n';
            if(cur < minCur && cur > -1){
                minCur = cur;
            }
        }
        results[idx] = minCur;
    }

    for(int idx = 0; idx < n; idx++){
        minCur = 1000000001;
        if(results[idx] != 1000000001){
            for(int jdx = 0; jdx < n; jdx++){
                // cout << "------" << idx << ' ' << jdx << '\n';
                cur = -1;
                if(idx == jdx){
                    continue;
                }
                // dir same
                if(cows[idx][0] == cows[jdx][0]){
                    // cout<<"asdf\n";
                    if(cows[idx][0] == 'N'){
                        // x same
                        if(cows[idx][1] == cows[jdx][1]){
                            // y smaller
                            if(cows[idx][2] < cows[jdx][2]){
                                cur = cows[jdx][2]-cows[idx][2];
                            }
                        } 
                    } else{
                        // y same
                        if(cows[idx][2] == cows[jdx][2]){
                            // y smaller
                            if(cows[idx][1] < cows[jdx][1]){
                                cur = cows[jdx][1]-cows[idx][1];
                            }
                        } 
                    }
                } else{
                    if(cows[idx][0] == 'N'){
                        // x bigger
                        if(cows[idx][1] > cows[jdx][1]){
                        
                            // y smaller
                            if(cows[idx][2] < cows[jdx][2]){
                                difx = cows[idx][1]-cows[jdx][1];
                                dify = cows[jdx][2]-cows[idx][2];
                                // jdx gets there first
                                if(difx < dify && results[jdx] >= difx ){
                                    cur = dify;
                                }
                            }
                        }
                    } else{
                        // x smaller
                        if(cows[idx][1] < cows[jdx][1]){
                            // y bigger
                            if(cows[idx][2] > cows[jdx][2]){
                                // cout << "met\n";
                                difx = cows[jdx][1]-cows[idx][1];
                                dify = cows[idx][2]-cows[jdx][2];
                                // cout << difx << ' ' << dify << '\n';
                                // jdx gets there first
                                if(dify < difx && results[jdx] >= dify){
                                    cur = difx;
                                }
                            }
                        }
                    }

                }   
                // cout << cur << '\n';
                if(cur < minCur && cur > -1){
                    minCur = cur;
                }
            }
        }
        if(minCur == 1000000001){
            cout << "Infinity\n";
        } else{
            cout << minCur << '\n';
        }
    }

    return 0;
}