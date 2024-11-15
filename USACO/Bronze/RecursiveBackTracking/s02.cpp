// N과 M (1) 15649
#include <iostream>
using namespace std;

int n, m;
int arr[100], check[100];
void f(int i){
    if(i == m){
        for(int j = 0; j < m; j++){
            cout << arr[j] << " ";
        }
        cout << '\n';
        return;
    }
    for(int x = 1; x <= n; x++){
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