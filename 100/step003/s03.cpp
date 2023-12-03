#include <iostream>
using namespace std;

void solv() {
    int n;
    int sum =0;

    cin >> n;

    while ( n > 0) {
        sum += (n--);
    }

    cout << sum << endl;

}

int main(){
    int n;
    cin >> n;

    int idx = 1;
    int sum = 0;

    while(idx <= n){
        sum += idx;
        idx++;
    }

    cout << sum << endl;

    return 0;
}