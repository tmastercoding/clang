// Censoring 10750
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
    freopen("7.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    // cin.tie(NULL);
    // ios::sync_with_stdio(false);
    string s, censor, temp;
    cin >> s >> censor;
    
    int sameFor = 0;

    while (true){

        for(int idx = 0; idx < s.size()-censor.size(); idx++){
            bool work = true;
            for(int jdx = 0; jdx < censor.size(); jdx++){
                if(s[idx+jdx] != censor[jdx]){
                    work = false;
                }
            }
            if(work == true){
                for(int jdx = 0; jdx < censor.size(); jdx++){
                    s[idx+jdx] = '-';
                }
                idx += censor.size();
            }
        }
        temp.clear();
        for(int idx = 0; idx < s.size(); idx++){
            if(s[idx] != '-'){
                temp += s[idx];
            }
        }
        if(!temp.compare(s)){
            if(sameFor < 10){
                sameFor++;
            } else{
                break;
            }
        }
        s = temp;
    }
    cout << temp << '\n';
}