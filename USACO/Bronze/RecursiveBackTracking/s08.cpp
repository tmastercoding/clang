// N-Queen 9663
#include <iostream>
using namespace std;

int n;
int cnt = 0;
// vertical, i+j, i-j
int vcheck[100], ddcheck[100], ducheck[100];

void f(int i){
    if(i == n){
        cnt++;
        return;
    }
    for(int j = 0; j < n; j++){
        if(vcheck[j] == 0 && ddcheck[i+j] == 0 && ducheck[i-j+n] == 0){
            vcheck[j] = 1;
            ddcheck[i+j] = 1;
            ducheck[i-j+n] = 1;
            f(i+1);
            vcheck[j] = 0;
            ddcheck[i+j] = 0;
            ducheck[i-j+n] = 0;
        }
    }
}

int main(){
    cin >> n;
    f(0);
    cout << cnt << '\n';
    return 0;
}