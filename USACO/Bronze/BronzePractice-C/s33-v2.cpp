// Palindrome Game 31648
#include <iostream>
#include <string>
using namespace std;


int main(){

    int size;
    cin >> size;
    for(int cnt = 0; cnt < size; cnt++){
        string num;
        cin >> num;
        if(num[num.length()-1] == '0'){
            cout << "E\n";
        } else{
            cout << "B\n";
        }
    }

    return 0;
}