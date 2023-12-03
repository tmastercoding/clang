#include <iostream>
using namespace std;

void solv() {
    int tot;
    int n;
    int sum =0;
    int a, b;

    cin >> tot;
    cin >> n;


     while( n-- > 0) {
        cin >> a >> b;
        sum += (a * b);
    }

    cout << ( ( sum == tot )? "yes" : "no" ) << endl;
}

int main(){
    int tot;
    int numOfItems;

    cin >> tot >> numOfItems;

    int sum = 0;
    int price, quantity;

    for(int idx = 0; idx < numOfItems; idx++){
        cin >> price >> quantity;
        sum += price * quantity;
    }

    if(sum == tot){
        cout << "Yes" << endl;
    } else{
        cout << "No" << endl;
    }

    return 0;
}