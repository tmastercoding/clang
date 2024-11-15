// N과 M (4) 15652
#include <iostream>
using namespace std;

int n, m;
int arr[100];

void f(int i){
    if(i == m){
        for(int j = 0; j < m; j++){
            cout << arr[j] << ' ';
        }
        cout << '\n';
        return;
    }
    int start = 1;
    if(i > 0){
        start = arr[i-1];
    }
    for(int x = start; x <= n; x++){
        if(i > 0){
            if(arr[i-1] <= x){
                arr[i] = x;
            }
        } else{
            arr[i] = x;
        }
        f(i+1);
    }

}

int main(){
    cin >> n >> m;
    f(0);
    return 0;
}