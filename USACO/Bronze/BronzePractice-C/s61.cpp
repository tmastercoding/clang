#include <iostream>
using namespace std;

int main(){
    int n, cows[1000];
    cin >> n;
    for(int idx = 0; idx < n; idx++){
        cin >> cows[idx];
    }

    int oddCnt = 0, evenCnt = 0;
    for(int idx = 0; idx < n; idx++){
        if(cows[idx] & 1){
            oddCnt++;
        } else{
            evenCnt++;
        }
    }

    // cout << evenCnt << ' ' << oddCnt << '\n';
    int tot = 0;
    if(evenCnt > oddCnt){
        tot += oddCnt*2;
        tot++;
    } else if(oddCnt > evenCnt){
        tot += evenCnt*2;
        tot += (int)((oddCnt-evenCnt)/3)*2;
        // cout << tot << '\n';
        if((oddCnt-evenCnt)%3 == 2){
            tot++;
        } else if((oddCnt-evenCnt)%3 == 1){
            tot--;
        }
    } else{ 
        tot = evenCnt*2;
    }
    cout << tot << '\n';
    return 0;
}