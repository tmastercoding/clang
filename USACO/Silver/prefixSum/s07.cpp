// 합 구하기 11441
#include <iostream>
using namespace std;

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    long long arr[100001] = {};
    int n, m, pre, post;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i+1];
        arr[i+1] += arr[i];
    }
    
    cin >> m;
    for(int i = 0; i < m; i++){
        cin >> pre >> post;
        cout << arr[post]-arr[pre-1] << '\n';
    }
    
    return 0;
}