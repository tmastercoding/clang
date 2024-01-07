#include <iostream>
#include <map>
#include <string>
using namespace std;

/**
 * @date 23.12.31
 * @author Tay Oh
 * @details Map basics
*/

int main() {

    // map is just like a dictionary
    // int is key type, string is val type
    map<int, string> tMap;

    // can insert a key and value using insert
    // each map is made up of pairs
    tMap.insert( pair<int, string>( 1, "Tay Oh") );

    // can get size using .size() returns how many pairs there are
    cout << "size: " << tMap.size() << endl;

    // can insert a key and value like dictionary
    tMap[2] = "map2";

    cout << "size: " << tMap.size() << endl;

    // create iter using casting (map<int, string>::iterator)
    map<int,string>::iterator iter;

    // iter is the key 1 of tMap( use find() )
    iter = tMap.find( 1 );

    // if iter is tMap.end stop
    if( iter != tMap.end() ) {
        // first is key, second is val
        cout << iter->first << endl;
        cout << iter->second << endl;
    }

    // use loop to print all elements of tMap
    for( map<int, string>::iterator it = tMap.begin(); it != tMap.end(); it++ ) {
        cout << it->first << ' ' << it->second << endl;
    }

    // to delete a key
    tMap.erase(2);

    cout << "size: " << tMap.size() << endl;

    // to completley clear a map
    tMap.clear();

    cout << "size: " << tMap.size() << endl;

    return 0;
}