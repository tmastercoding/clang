#include <iostream>
using namespace std;

int main(){
    freopen("feast.in", "r", stdin);
    freopen("feast.out", "w", stdout);
    int t, a, b;
    cin >> t >> a >> b;

    int check[5000001] = {};
    check[0] = 1;
    for(int i = 0; i <= t; i++){
        if(i-a >= 0 && check[i-a] || i-b >= 0 && check[i-b]){
            check[i] = 1;
        }
    }
    
    for(int i = 0; i <= t; i++){
        if(check[i]) check[i/2] = 1;
    }
    
    for(int i = 0; i <= t; i++){
        if(i-a >= 0 && check[i-a] || i-b >= 0 && check[i-b]){
            check[i] = 1;
        }
    }

    for(int i = t; i > -1; i--){
        if(check[i]){
            cout << i << '\n';
            break;
        }
    }
    return 0;
}