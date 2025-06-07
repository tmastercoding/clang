#include <iostream>
using namespace std;

long long arr[1000001] = {}, rem[1001] = {};
int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    long long n, num, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> num;
        arr[i+1] = (arr[i]+num)%m;
    }

    long long cnt = 0;
    for(int i = 0; i <= n; i++){
        cnt += rem[arr[i]];
        rem[arr[i]]++;
    }
    cout << cnt << '\n';
    return 0;
}