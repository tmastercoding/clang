#include <iostream>
#include <algorithm>
using namespace std;

long long int from[7] = {0, }, arr[3] =  {0,}, check[7] =  {0,0,0,0,0,0,0};
bool done = false;
void f(int cur){
    if(cur == 3){
        int sum, sumab, sumbc, sumac;
        sum = arr[0] + arr[1] + arr[2];
        sumab = arr[0] + arr[1];
        sumbc = arr[1] + arr[2];
        sumac = arr[0] + arr[2];
        
        bool fsum = false, fsumab = false, fsumbc = false, fsumac = false;
        for(int idx = 0; idx < 7; idx++){
            if(check[idx] == 1){
                continue;
            }
            // cout << from[idx] << '\n';
            if((from[idx] == sum) && (!fsum)){
                fsum = true;
            } else if((from[idx] == sumab) && (!fsumab)){
                fsumab = true;
            } else if((from[idx] == sumbc) && (!fsumbc)){
                fsumbc = true;
            } else if((from[idx] == sumac) && (!fsumac)){
                fsumac = true;
            }
        }
        // cout << arr[0] << ' ' << arr[1] << ' ' << arr[2] << ' ' << fsum << ' ' << fsumab << ' ' << fsumbc << ' ' << fsumac << '\n';
        if(fsum && fsumab && fsumbc && fsumac && !done){
            sort(arr, arr+3);
            cout << arr[0] << ' ' << arr[1] << ' ' << arr[2] << '\n';
            done = true;
        }
        return;
    }
    for(int idx = 0; idx < 7; idx++){
        if(check[idx] == 0){
            check[idx] = 1;
            arr[cur] = from[idx];
            f(cur+1);
            check[idx] = 0;
        }
    }
}

int main(){
    // freopen("2.in", "r", stdin);
    // long long int temp = 0;
    for(int idx = 0; idx < 7; idx++){
        cin >> from[idx];

    }

    f(0);
    // cout << "2 2 7\n";
    return 0;
}