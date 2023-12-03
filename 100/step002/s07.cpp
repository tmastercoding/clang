#include <iostream>
using namespace std;

void solv() {
    int a, b, c;
    int max = 0;

    cin >> a >> b >> c;

    if( a == b && b == c ) {
        cout << a * 1000 + 10000 << endl; 
    } else if( a == b ) {
        cout << a * 100 + 1000 << endl;
    } else if( b == c ) {
        cout << b * 100 + 1000 << endl;
    } else if( c == a ) {
        cout << c * 100 + 1000 << endl;
    } else {
        max = a;
        if( max < b ) {
            max = b;
        }
        if( max < c ) {
            max = c;
        }

        cout << max * 100 << endl;
    }
}

int ottai_max(int *arr, int size){
    int max = arr[0];
    for(int idx = 0; idx < size; idx++){
        if(max < arr[idx]){
            max = arr[idx];
        }
    }

    return max;
}

int main(){

    int dice1 = 1;
    int dice2 = 3;
    int dice3 = 2;

    cin >> dice1 >> dice2 >> dice3;
    int dice_arr[] = {dice1, dice2, dice3};
    int price = 0;

    if (dice1 == dice2 && dice2 == dice3){
        price = dice1 * 1000 + 10000;

    } else if(dice1 == dice2){
        price = dice1 * 100 + 1000;

    } else if(dice2 == dice3){
        price = dice2 * 100 + 1000;

    } else if(dice1 == dice3){
        price = dice1 * 100 + 1000;

    } else{
        price = ottai_max(dice_arr, 3)*100;
    }

    cout << price << endl;

    return 0;
}