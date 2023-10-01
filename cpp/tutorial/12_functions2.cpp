#include <iostream>
#include <string>
using namespace std;

int plusFunc(int x, int y){return x+y;}

double plusFunc(double x, double y){return x+y;}

int sum(int k){
    if(k > 0){
        return k + sum(k-1);
    } else {
        return 0;
    }
}

int main(){
    // overloading
    int myNum1 = plusFunc(8,5);
    double myNum2 = plusFunc(4.3, 6.26);

    cout << "Int: " << myNum1 << endl;
    cout << "Double: " << myNum2 << endl;
    
    // recursion
    int result = sum(10);
    cout << result << endl;

    return 0;
}


