#include <iostream>
#include <vector>
using namespace std;

long long arr[1000000] = {}, cnts[1000001] = {}, infront[1000001] = {}, visit[1000001] = {}, rem[1000001] = {};
int main(){
    long long n;
    cin >> n;
    // vector<int, long long>::iterator it;
    long long types = 0;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        cout << types << '\n';
        infront[i] = types;
        // if(rem[arr[i]] == 0){
            
            // infront[i]--;
            // types--;
            //     rem[arr[i]] = 1;
        if(visit[arr[i]] == 0 && rem[arr[i]] == 0){
            types++;
        } 
        visit[arr[i]] = 1;
    }
    for(int idx = 0; idx < n; idx++){
        cout << infront[idx] << ' ';
    }
    cout << '\n';
    long long cnt = 0;
    for( int i = n-1; i > -1; i--){
        cnts[arr[i]]++;
        if(visit[arr[i]] == 1 && cnts[arr[i]] >=2){
            // cout << arr[i] << '\n';
            cnt+=infront[i];
            visit[arr[i]] = 2;
        }
    }
    cout << cnt << '\n';
    

    return 0;
}