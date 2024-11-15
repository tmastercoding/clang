#include <iostream>
#include <string>
using namespace std;

int main(){
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        string text;
        cin >> text;
        int len = text.length();
        long long int cnt = -1, minCnt = 100000000;
        for(int idx = 0; idx < len-2; idx++){
            string temp = text.substr(idx, 3);
            cnt = -1;
            // cout << temp << '\n';
            if(temp == "MOO"){
                cnt = 0;
                cnt += len-3;
            } else if(temp == "OOO" || temp == "MOM"){
                cnt = 1;
                cnt += len-3;
            } else if(temp == "OOM"){
                cnt = 2;
                cnt += len-3;
            }
            // cout << cnt << '\n';
            if(cnt != -1){
                if(minCnt > cnt){
                    minCnt = cnt;
                }
            }
        }

        if(minCnt == 100000000){
            cout << -1 << '\n';
        } else{
            cout << minCnt << '\n';
        }
    }
    return 0;
}