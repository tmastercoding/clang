#include <iostream>
using namespace std;

// sol 1
void solv() {
    // number
    int n;
    // sum of numbers
    int sum =0;

    // get input
    cin >> n;

    // loop from n to 1
    while ( n > 0) {
        // add to sum decreasing
        sum += (n--);
    }

    // output
    cout << sum << endl;

}

// sol 2
int main(){
    // get input
    int n;
    cin >> n;

    int idx = 1;
    int sum = 0;

    // loop from 1 to n
    while(idx <= n){
        // add idx to sum
        sum += idx;
        idx++;
    }

    // output
    cout << sum << endl;

    return 0;
}