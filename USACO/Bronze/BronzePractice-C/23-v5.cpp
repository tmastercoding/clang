#include <iostream>
using namespace std;

int main(){
    int size = 0;
    cin >> size;
    int cows[size];
    for(int idx = 0; idx < size; idx++){
        cin >> cows[idx];
    }

    // two pointer:
    int pre2Cnt = 0;
    int post1Cnt = 0;
    for(int idx = 0; idx < size; idx++){
        if(cows[idx] == 1){
            post1Cnt++;
        }
    }

    int minChange = 30000;
    for(int idx = 0; idx < size; idx++){
        if(post1Cnt + pre2Cnt < minChange){
            minChange = post1Cnt + pre2Cnt;
        }
        if(cows[idx] == 1){
            post1Cnt--;
        } 
        if(cows[idx] == 2){
            pre2Cnt++;
        }
    }
    if(post1Cnt + pre2Cnt < minChange){
        minChange = post1Cnt + pre2Cnt;
    }
    cout << minChange << '\n';
    
    return 0;
}