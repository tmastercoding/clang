// Problem 2. Non-Transitive Dice
#include <iostream>
#include <algorithm>
using namespace std;

int d1[4], d2[4], d3[4];
bool work = false;
void func(int i){
    if(i == 4){
        int odd12= 0, odd13 = 0, odd21 = 0, odd23 = 0, odd31 = 0, odd32 = 0;

        for(int idx = 0; idx < 4; idx++){
            for(int jdx = 0; jdx < 4; jdx++){
                if(d1[idx] > d2[jdx]){
                    odd12++;
                } else{
                    break;
                }
            }
        }
        for(int idx = 0; idx < 4; idx++){
            for(int jdx = 0; jdx < 4; jdx++){
                if(d1[idx] > d3[jdx]){
                    odd13++;
                } else{
                    break;
                }
            }
        }
        for(int idx = 0; idx < 4; idx++){
            for(int jdx = 0; jdx < 4; jdx++){
                if(d2[idx] > d1[jdx]){
                    odd21++;
                } else{
                    break;
                }
            }
        }
        for(int idx = 0; idx < 4; idx++){
            for(int jdx = 0; jdx < 4; jdx++){
                if(d2[idx] > d3[jdx]){
                    odd23++;
                } else{
                    break;
                }
            }
        }
        for(int idx = 0; idx < 4; idx++){
            for(int jdx = 0; jdx < 4; jdx++){
                if(d3[idx] > d1[jdx]){
                    odd31++;
                } else{
                    break;
                }
            }
        }
        for(int idx = 0; idx < 4; idx++){
            for(int jdx = 0; jdx < 4; jdx++){
                if(d3[idx] > d2[jdx]){
                    odd32++;
                } else{
                    break;
                }
            }
        }
        int win1 = 0, win2 =0,  win3=0;
        if(odd12 > odd21){
            win1++;
        } else if(odd21 > odd12){
            win2++;
        }
        if(odd13 > odd31){
            win1++;
        } else if(odd31 > odd13){
            win3++;
        }
        if(odd23 > odd32){
            win2++;
        } else if(odd32 > odd23){
            win3++;
        }

        if(win1 == 1 && win2 == 1 && win3 == 1){
            // for(int idx = 0; idx < 4; idx++){
            //     cout << d3[idx] << ' ';
            // }
            // cout << '\n';
            work = true;
        }
        return;
    }
    int start = 1;
    if(i > 0){
        start = d3[i-1];
    }
    for(int x = start; x <= 10; x++){
        d3[i] = x;
        func(i+1);
    }
}

int main(){
    int t = 0;
    cin >> t;
    for(int i = 0; i < t; i++){

        for(int idx = 0; idx < 4; idx++){
            cin >> d1[idx];
        }
        for(int idx = 0; idx < 4; idx++){
            cin >> d2[idx];
        }

        sort(d1, d1+4);
        sort(d2, d2+4);
        int odd1, odd2;
        for(int idx = 0; idx < 4; idx++){
            for(int jdx = 0; jdx < 4; jdx++){
                if(d1[idx] > d2[jdx]){
                    odd1++;
                } else{
                    break;
                }
            }
        }
        
        for(int idx = 0; idx < 4; idx++){
            for(int jdx = 0; jdx < 4; jdx++){
                if(d2[idx] > d1[jdx]){
                    odd2++;
                } else{
                    break;
                }
            }
        }
        work = 0;
        func(0);
        if(work){
            cout << "yes\n";
        } else{
            cout << "no\n";
        }
    }
    return 0;
}