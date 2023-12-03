#include <iostream>
#include <stdlib.h>
using namespace std;

void solv() {
    int n, tot=0;
    int a, b;

    int* parr;
    cin >> n;
    parr =  (int*)malloc(n * sizeof(int));

    while( n-- > 0) {
        cin >> a >> b;        
        parr[tot++] = a + b;
    }
    n++;
    while( tot-- > 0 ) {
        cout << parr[n++] << endl;
    }
}

int main(){
    int cases;
    cin >> cases;

    int *ansArr;
    ansArr = (int *)malloc(cases * sizeof(int));

    int a, b;
    for (int idx = 0; idx < cases; idx++){
        cin >> a >> b;
        ansArr[idx] = a+b; 
    }

    for (int idx = 0; idx < cases; idx++){
        cout << ansArr[idx] << endl; 
    }
    
    return 0;
}