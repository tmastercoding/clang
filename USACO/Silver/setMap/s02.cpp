// 배부른 마라토너
#include <iostream>
#include <set>
#include <string>
using namespace std;

int main(){
    int n;
    set<string> s;
    string name;
    cin >> n;
    n*=2;
    n--;
    for(int i = 0; i < n; i++){
        cin >> name;
        if(s.find(name) == s.end()){
            s.insert(name);
        } else{
            s.erase(name);
        }
    }

    cout << *(s.begin()) << '\n';
    return 0;
}