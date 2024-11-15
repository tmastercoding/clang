// 모든 순열 10974
#include <iostream>
using namespace std;

int arr[100], check[100];
int n;
void f(int i ){
    if(i == n){
        // output arr
        for(int j = 0; j < n; j++){
            cout << arr[j] << ' ';
        }
        cout << '\n';
        return;
    } 
    for(int x = 1; x <= n; x++){
        if(check[x] == 0){
            arr[i] = x;
            check[x] = 1;
            f(i+1);
            check[x] = 0;
            arr[i] = 0;
        }
    }
}

int main(){
    int size;
    cin >> size;
    n = size;
    f(0);

    return 0;
}