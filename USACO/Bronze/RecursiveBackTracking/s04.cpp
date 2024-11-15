// N과 M (2) 15650
#include <iostream>
using namespace std;

int n, m;
int arr[100], check[100];
void f(int i){
    if(i == m){
        for(int j = 0; j < m; j++){
            cout << arr[j] << ' ';
        }
        cout << '\n';
        return;
    }
    int start = 1;
    if(i != 0){
        start = arr[i-1];
    }
    for(int x = start; x <= n; x++){
        if(check[x] == 0){
            check[x] = 1;
            arr[i] = x;
            f(i+1);
            check[x] = 0;
        }
    }

}

int main(){
    cin >> n >> m;
    f(0);
    return 0;
}