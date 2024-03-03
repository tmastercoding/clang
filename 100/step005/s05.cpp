#include <iostream>
#include <string>
#include <vector>
using namespace std;

int sum(){
    int size = 0;
    char c;
    int idx = 0;
    int sum = 0;

    cin >> size;
    cin.ignore();

    while((c = cin.get()) != '\n'){
        sum += (c-'0');
        
        idx++;
        
        if( idx > size){
            break;
        }
    } 

    return sum;
}

int main(){
    vector<int> v;
    int size = 0;
    char c;
    int idx = 0;
    int sum = 0;

    cin >> size;
    cin.ignore();

    while((c = cin.get()) != '\n'){
        v.push_back(c-'0');
        
        idx++;
        
        if( idx > size){
            break;
        }
    } 

    for(int i : v){
        cout << i << endl;
    }

    struct Sum {
        void operator() (int n){sum += n;}
        int sum{0};
    };
    
    Sum s = for_each(v.begin(), v.end(), Sum());

    cout << s.sum << endl;

    return 0;
}