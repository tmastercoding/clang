#include <iostream>
using namespace std;

int returnSize();
int size;
int main(){
    cin >> size;
    cout << returnSize() << '\n';
    return 0;
}

int returnSize(){
    return size;
}