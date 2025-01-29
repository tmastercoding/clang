#include <iostream>
using namespace std;

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int arr[100000], sum[100001], n, m;
    cin >> n >> m;
    sum[0] = 0;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        sum[i+1] = sum[i]+arr[i];
    }
    
    int start, end;
    for(int i = 0; i < m; i++){
        cin >> start >> end;
        cout << sum[end] - sum[start-1] << '\n';
    }
    return 0;
}