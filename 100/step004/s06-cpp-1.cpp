#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// void swap( int* basket, int one, int other  );

int main() {

    int one, other;
    int size_basket = 5;
    int count_of_change = 4;

    cin >> size_basket >> count_of_change;

    vector<int> basket;

    cout << size_basket << " " << count_of_change << endl;

    for( int idx = 0; idx < size_basket; idx++ ) {
        basket.push_back(idx+1);
    }

    while( 1 ) {

        scanf( "%d %d", &one, &other );

        if( one != other ) {
            swap( basket[one-1], basket[other-1] );
        }

        printf( "one : %d, other: %d\n", one, other );

        count_of_change--;

        if( !count_of_change ) break;

    }

    for_each(basket.begin(), basket.end(), [](const int &n ) { cout << n << ' '; } );

    cout << endl;

    return 0;
}
