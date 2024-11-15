// 1, 2, 3 더하기 9095
#include <iostream>
using namespace std;

int n;
int cnt = 0;
int arr[100];
void f(int i){
    int sum = 0;
    for(int j = 0; j < i; j++){
        sum += arr[j];
    }

    if(sum > n){
        return;
    } 
    if(sum == n){
        cnt++;
    }
    if(i == n){
        return;
    }

    for(int x = 1; x <= 3; x++){
        arr[i] = x;
        f(i+1);
    }
}

int main(){
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> n;
        cnt = 0;
        f(0);
        cout << cnt << '\n';
    }
    return 0;
}