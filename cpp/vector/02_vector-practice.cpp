#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    vector<char> v {'a', 'b', 'c'};
    for(char c: v){
        cout << c << endl;
    }

    auto print = [](const char &c) {cout << c << ' ';};
    for_each(v.begin(), v.end(), print);
    cout << endl;

    // auto alphabet = []( char &c ){ }
    v.push_back('d');

    for_each(v.begin(), v.end(), print);
    cout << endl;

    v.pop_back();
    for_each(v.begin(), v.end(), print);
    cout << endl;

    struct Alphabet {
        // void operator() ( int n ){ sum += n; }
        void operator() ( int c ){ nextChar = ++c; }
        int nextChar {0};
    };

    char temp;
    
    Alphabet alphabet = for_each(v.begin(), v.end(), Alphabet());
    v.push_back(alphabet.nextChar);
    temp = alphabet.nextChar;
    cout << temp << endl;

    for_each(v.begin(), v.end(), print );

    return 0;
}
