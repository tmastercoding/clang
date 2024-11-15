// Cow Gymnastics 18268
#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    freopen("gymnastics.in", "r", stdin);
	freopen("gymnastics.out", "w", stdout);
    int kSize, nSize; 
    cin >> kSize >> nSize;
    int rank[kSize][nSize];

    for(int idx = 0; idx < kSize; idx++){
        for(int jdx = 0; jdx < nSize; jdx++){
            cin >> rank[idx][jdx];
        }
    }
    int cnt = 0;
    for(int idx = 1; idx < nSize+1; idx++){
        for(int jdx = idx; jdx < nSize+1; jdx++){
            if(idx == jdx){
                continue;
            }
            int greaterCow = 0;
            bool isValid = true;
            for(int kdx = 0; kdx < kSize; kdx++){
                if(!isValid){
                    break;
                }
                for(int ldx = 0; ldx < nSize; ldx++){
                    if(!greaterCow){
                        if(rank[kdx][ldx] == idx){
                            greaterCow = idx;
                            break;
                        } 
                        if(rank[kdx][ldx] == jdx){
                            greaterCow = jdx;
                            break;
                        } 
                    } else{
                        if(rank[kdx][ldx] == idx){
                            if(greaterCow != idx){
                                isValid = false;
                            }
                            break;
                        } 
                        if(rank[kdx][ldx] == jdx){
                            if(greaterCow != jdx){
                                isValid = false;
                            }
                            break;
                        } 
                    }
                }
            }
            if(isValid){
                cnt++;
            }
        }
    }

    cout << cnt << '\n';
    return 0;
}