#include <iostream>
#include <cmath>
using namespace std;

int round(int num, int p){
    string s =  to_string(num);
    int x;
    int cnt = 0;
    for(int idx = s.size()-1; idx > -1; idx--){
        cnt++;
        if(cnt == p){
            x = s[idx]-'0';
        }
    }
    
    if(x>= 5){
        num += pow(10, p);
    }
    s = to_string(num);

    cnt = 0;
    for(int idx = s.size()-1; idx > -1; idx--){
        cnt++;
        s[idx] = '0';
        if(cnt == p){
            break;
        }
    }

    num = stoi(s);
    // cout << num << '\n';
    return num;
}

int chainRound(int num, int p){
    for(int power = 1; power <=p; power++){
        num = round(num, power);
    }
    return num;
}

int main(){
    int t = 0;
    cin >> t;
    for(int i = 0; i < t; i++){
        int to, cnt = 0;
        cin >> to;
        for(int test = 2; test <= to; test++){
            int p = to_string(test).size();
            if(round(test, p) != chainRound(test, p)){
                cnt++;
            }
        }
        cout << cnt << '\n';
    }

    return 0;
}