#include <iostream>
#include <string>
using namespace std;

int main(){
    string cowphabet, input;
    cin >> cowphabet >> input;

    int idx = 0, cur = 0, cnt = 0;
    while(idx != input.size()){
        for(; cur < 26; cur++){
            if(input[idx] == cowphabet[cur]){
                idx++;
                cur++;
                break;
            }
        }
        if(cur == 26){
            cur = 0;
            cnt++;
        }
    }
    cout << cnt+1 << '\n';
    return 0;
}