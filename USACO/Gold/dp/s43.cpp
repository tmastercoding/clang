#include <iostream>
using namespace std;

int main(){
    int arr[101][10];
    int n;
    cin >> n;
    arr[0][0] = 0;
    for(int i = 1; i < 10; i++){
        arr[0][i] = 1;
    }

    for(int i = 1; i < n; i++){
        for(int j = 0; j < 10; j++){
            if(j == 0){
                arr[i][j] = arr[i-1][1] % 1000000000;
            } else if(j == 9){
                arr[i][j] = arr[i-1][8] % 1000000000;
            } else{
                arr[i][j] = ((arr[i-1][j-1] % 1000000000 )+(arr[i-1][j+1]% 1000000000))% 1000000000;
            }
        }
    }
    
    long long sum = 0;
    for(int i = 0; i < 10; i++){
        sum += arr[n-1][i]% 1000000000;
    }
    cout << sum % 1000000000<< '\n';
    return 0;
}