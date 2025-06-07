// 좌표 압축 18870
#include <iostream>
#include <set>
#include <map>
using namespace std;

long long arr[1000000], sum[1000000] = {};
int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    map<long long, long long> og, m;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        og[arr[i]] = 1;
    }

    int i = 0;
    for(auto it: og){
        // cout << it.first << ' ' << it.second << '\n';
        if(i > 0){
            sum[i] += sum[i-1];
            m[it.first] = sum[i];
        }
        // cout << sum[i] << '\n';
        sum[i+1]+= it.second;
        i++;
    }
    for(int i = 0; i < n; i++){
        cout << m[arr[i]] << ' ';
    }
    cout << '\n';
    return 0;   
}