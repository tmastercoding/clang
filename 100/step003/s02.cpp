#include <iostream>
#include <stdlib.h>
using namespace std;

// sol 1
void solv() {
    // size and idx
    int n, tot=0;
    // two numbers
    int a, b;

    // arr
    int* parr;
    // get input size
    cin >> n;
    // malloc 
    parr =  (int*)malloc(n * sizeof(int));

    // loop n times
    while( n-- > 0) {
        // get input
        cin >> a >> b; 
        // add sum to arr 
        parr[tot++] = a + b;
    }
    n++;
    // output
    while( tot-- > 0 ) {
        cout << parr[n++] << endl;
    }
}

int main(){
    // get input 
    int cases;
    cin >> cases;

    // arr for sums
    int *ansArr;
    ansArr = (int *)malloc(cases * sizeof(int));

    int a, b;
    // loop for cases
    for (int idx = 0; idx < cases; idx++){
        // input
        cin >> a >> b;
        // add sum to arr
        ansArr[idx] = a+b; 
    }

    for (int idx = 0; idx < cases; idx++){
        // output
        cout << ansArr[idx] << endl; 
    }
    
    return 0;
}