#include <iostream>
using namespace std;

// sol 1
void solv() {
    // declare variables
    int tot;
    int n;
    int sum =0;
    int a, b;

    // get input for estimated total
    // and number of items
    cin >> tot;
    cin >> n;

    // loop for n
    while( n-- > 0) {
        // get input
        cin >> a >> b;
        // add to sum
        sum += (a * b);
    }

    // tenary based output
    cout << ( ( sum == tot )? "yes" : "no" ) << endl;
}

// sol 2
int main(){
    // declare variables
    int tot;
    int numOfItems;

    // get input
    cin >> tot >> numOfItems;
    int sum = 0;
    int price, quantity;

    // loop for numOfItems
    for(int idx = 0; idx < numOfItems; idx++){
        // get input
        cin >> price >> quantity;
        // add to sum
        sum += price * quantity;
    }

    // if statement for output
    if(sum == tot){
        cout << "Yes" << endl;
    } else{
        cout << "No" << endl;
    }

    return 0;
}