// 신기한 소수 2023
#include <iostream>
#include <cmath>
using namespace std;

int n;
int arr[10];
int cnt = 0;

bool isPrime(int num){
    if(num < 2){
        return false;
    }
    for(int idx = 2; idx < num; idx++){
        if(num % idx == 0){
            return false;
        }
    }
    return true;
}

void f(int i){
    if(i == n){
        for(int j = 0; j < n; j++){
            cout << arr[j];
        }
        cout << '\n';
        return;
    }
    for(int x = 0; x <= 9; x++){
        int temp = 0;
        for(int j = 0; j < i; j++){
            temp += arr[j] * pow(10, i-j);
        }
        temp += x;
        if(isPrime(temp)){
            arr[i] = x;
            f(i+1);
        }
    }
}


int main(){
    // cout << isPrime(3) << '\n';
    cin >> n;
    f(0);
    return 0;
}