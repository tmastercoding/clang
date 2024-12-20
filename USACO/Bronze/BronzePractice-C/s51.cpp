// Herdle
#include <iostream>
#include <string>
using namespace std;

int main(){
    int actual[26] {0}, total[26]{0};
    int green = 0, yellow = 0;
    string ans[3], guess[3];
    for(int idx = 0; idx < 3; idx++){
        cin >> ans[idx];
    }
    for(int idx = 0; idx < 3; idx++){
        cin >> guess[idx];
    }

    for(int idx = 0; idx < 3; idx++){
        for(int jdx = 0; jdx < 3; jdx++){
            if(ans[idx][jdx] == guess[idx][jdx]){
                green++;
            } else{
                actual[ans[idx][jdx]-'A']++;
                total[guess[idx][jdx]-'A']++;
            }
        }
    }


    for(int idx = 0; idx < 26; idx++){
        if(actual[idx] > 0){
            // cout << actual[idx] << ' ' <<total[idx];
            if(total[idx] > actual[idx]){
                yellow += actual[idx];
            } else{
                yellow += total[idx];
            }
        }
    }
    cout << green << '\n' << yellow << '\n';
    return 0;
}