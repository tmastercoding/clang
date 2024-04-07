#include <iostream>
#include <string>
#include <vector>
using namespace std;

/**
 * @date 23.12.31
 * @author Tay Oh
 * @details code explaining how the basics of vector works
*/

int main(){

    // vector is a container
    int i_arr[] = { 1, 2, 3, 4, 5};

    // a vector (basket) that can only store int (cabbage)
    vector<int> v { 1, 2, 3, 4, 5};

    // can loop the same way
    for( int i : i_arr ) {
        cout << i << endl;
    }

    for( int i : v ) {
        cout << i << endl;
    }

    // can use .size() instead to get size
    cout << sizeof(i_arr)/sizeof(int) << endl;
    cout << v.size() << endl;

    // doesn't use index, rather .at()
    for(int idx = 0; idx < v.size(); idx++){
        cout << v.at( idx ) << endl;
    }

    cout << "traverse vector value by iter" << endl;
    
    // iterator only stores pos, starts v.begin()
    vector<int>::iterator iter = v.begin();

    // iter will go till v.end(), goes to next term each time
    for( ; iter != v.end(); iter++ ) {
        // treats like pointer
        cout << *iter << endl;
    }
    
    // auto function, returns array, gets an input of const int
    // and prints each term

    // auto function_name = return type (parameters) {action};
    auto print = []( const int &n ) { cout << n << ' '; };

    // does the print function for each term
    for_each( v.begin(), v.end(), print );

    cout << endl;

    // can just use like lambda, putting function inside for_each
    for_each( v.begin(), v.end(), []( int& n ){ n++; } );

    for_each( v.begin(), v.end(), print );
    cout << endl;

    // auto function that increases each term by 1
    auto incre_fct = []( int& n ){ n++; };

    for_each( v.begin(), v.end(), incre_fct );

    for_each( v.begin(), v.end(), print );

    cout << endl;

    // structure including function
    struct Sum {
        // function takes int as parameter, and adds it to sum
        void operator() ( int n ){ sum += n; }
        // sum is declared here
        int sum {0};
    };

    // creates object of Sum, and calls operator for each term of v
    Sum s = for_each( v.begin(), v.end(), Sum() );

    // prints sum
    cout << "sum: " << s.sum << endl;
    
    return 0;
}