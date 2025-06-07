#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    for(int c = 0; c < n; c++){

        long long num, make;
        // cin >> n;
        // for(int i = 0; i < n; i++){
        cin >> num >> make;
        
        int minCnt = 1000000;
        for(int i = 0; (make >> i) > 0; i++){
            long long cnt = 0;
            long long tempMake = make;
            for(int j = 0; j < i; j++){
                if(tempMake & 1) cnt++;
                tempMake>>=1;
                cnt++;
            }
            long long tempNum = num;
            while(tempNum > tempMake){
                if(tempNum & 1){
                    tempNum+=1;
                } else{
                    tempNum >>= 1;
                }
                cnt++;
            }
            cnt += tempMake - tempNum;
            if(cnt < minCnt) minCnt = cnt;
        }
        cout << minCnt << '\n';
    }
    // while(num > make){
    //     if(num & 1){
    //         num+=1;
    //     } else{
    //         num >>= 1;
    //     }
    //     cnt++;
    // }
    // long long org = num;
    // int prev = -1, cur = 0, divideBy = 0;
    // while(true){
    //     num = org;
    //     cur = 0;
    //     for(int i = 0; i < divideBy; i++){
    //         if(num & 1){
    //             num+=1;
    //             num >>= 1;
    //             cur++;
    //         } else{
    //             num >>= 1;
    //         }
    //         cur++;
    //     }
        
    //     if(prev >= cur) break;
    //     prev = cur;
    //     divideBy++;
    // }

    // cout << num << ' ' << cnt << '\n';
    // }
    return 0;
}