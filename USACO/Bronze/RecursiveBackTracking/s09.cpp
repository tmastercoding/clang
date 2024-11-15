// 로또 6603
#include <iostream>
using namespace std;

int n, m = 6;
int input[100][100], arr[100], idxArr[100], check[100] = {0,};

void f(int i, int c){
    if(i == m){
        for(int j = 0; j < m; j++){
            cout << arr[j] << ' ';
        }
        cout << '\n';
        return;
    }
    int start = 0;
    if(i != 0){
        start = idxArr[i-1];
    }
    for(int x = start; x < n; x++){
        if(check[x] == 0){
            check[x] = 1;
            arr[i] = input[c][x];
            idxArr[i] = x;
            f(i+1, c);
            check[x] = 0;
        }
    }

}

int main(){
    int k;
    int kArr[100];
    int size = 0;
    while(true){
        cin >> k;
        if(k == 0){
            break;
        }
        kArr[size] = k;
        for(int i = 0; i < k; i++){
            cin >> input[size][i];
        }
        size++;
    }

    for(int idx = 0; idx < size; idx++){
        n = kArr[idx];
        f(0, idx);
        if(idx !=size-1){
            cout << '\n';

        }
    }
    return 0;
}