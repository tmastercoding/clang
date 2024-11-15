// 차이를 최대로 10819
#include <iostream>
using namespace std;

int n;
int input[8], arr[8], check[8];
int maxnum = 0;

void f(int i){
    if(i == n){
        int sum = 0;
        for(int j = 0; j < n-1; j++){
            sum += abs(arr[j] - arr[j+1]);
        }
        // cout << arr[n-1] << '\n';
        // cout << sum << '\n';
        if(sum > maxnum){
            maxnum = sum;
        }
        return;
    }

    for(int j = 0; j < n; j++){
        if(check[j] == 0){
            check[j] = 1;
            arr[i] = input[j];
            f(i+1);
            check[j] = 0;
        }
    }
}

int main(){
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> input[i];
    }
    f(0);
    cout << maxnum << '\n';

    return 0;
}