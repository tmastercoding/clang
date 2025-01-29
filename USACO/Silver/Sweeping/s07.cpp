// 아우으 우아으이야!! 15922
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    pair<long, long> arr[100000];
    long long start, end;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> start >> end;
        arr[i] = {start, end};
    }
    // sort(arr, arr+n);
    long long curS = arr[0].first, curE = arr[0].second, sum =abs( curE-curS);
    for(int i = 1; i < n; i++){
        // no overlap
        if(arr[i].first > curE){
            sum+= abs(arr[i].second-arr[i].first);
            curS = arr[i].first;
            curE = arr[i].second;
        // overlap
        } else{
            if( arr[i].second >= curE){
                sum += abs(arr[i].second - curE);
            }
            curE = arr[i].second;
        }
    }
    cout << sum << '\n';

    return 0;
}