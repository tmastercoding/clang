#include <iostream>
#include <stdlib.h>
using namespace std;

int main(){
    int length, number;

    cin >> length;
    int *arr = (int*)malloc(sizeof(int) * length);
    for(int idx = 0; idx < length; idx++){
        cin >> arr[idx];
    }
    
    cin >> number;
    int count = 0;

    for(int idx = 0; idx < length; idx++){
        if(arr[idx] == number){
            count++;
        }
    }   

    cout << count << endl;

    return 0;
}