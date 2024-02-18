#include <iostream>
#include <stdio.h>
using namespace std;

void c_ver();
void cpp_ver();

int main(){
    // c_ver();
    cpp_ver();
    return 0;
}

void c_ver(){
    // declare variables
    int max, maxPos, temp, idx;
    idx = 0;

    // loop 9 times
    while(idx < 9){
        // input temp
        scanf("%d", &temp);

        // if idx = 0 or temp > max
        if((!idx) || (temp > max)){
            // assign vals
            max = temp;
            maxPos = idx+1;
        }
        idx++;
    }

    // output
    printf("%d\n%d\n", max, maxPos);
}

void cpp_ver(){
    // declare variables
    int max, maxPos, temp, idx;
    idx = 0;

    // loop 9 times
    while(idx < 9){
        cin >> temp;

        // if idx = 0 or temp > max
        if((!idx) || (temp > max)){
            // assign vals
            max = temp;
            maxPos = idx+1;
        }
        idx++;
    }

    // output
    cout << max << endl << maxPos << endl;
}