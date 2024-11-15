// N과 M (5) 15654
#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int input[100] {0, };
int arr[100], check[100];

void f(int i){
    if(i == m){
        for(int j = 0; j < m; j++){
            cout << arr[j] << " ";
        }
        cout << '\n';
        return;
    } 
    for(int jdx = 0; jdx < n; jdx++){
        if(check[jdx] == 0){
            check[jdx] = 1;
            arr[i] = input[jdx];
            f(i+1);
            check[jdx] = 0;
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> input[i];
    }
    sort(input, input+n);
    f(0);
    // for(int i = 0; i < n; i++){
    //     cout <<  input[i] << '\n';
    // }
    return 0;
}