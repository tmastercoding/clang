#include <iostream>
using namespace std;

long long got[1020] = {};
int f(int n){
    if(n <= 1){
        return n;
    }

    if(got[n-1] == -1){
        got[n-1] = f(n-1)%10007;
    } 
    if(got[n-2] == -1){
        got[n-2] = f(n-2)%10007;
    } 

    
    return got[n-1] + got[n-2];
}

int main(){
    for(int i = 0; i < 1020; i++) got[i] = -1;
    int n;
    cin >> n;
    cout << f(n+1)%10007 << '\n';

    return 0;
}