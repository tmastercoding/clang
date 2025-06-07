#include <iostream>
#include <string>
#include <set>
#include <vector>
using namespace std;

int main(){
    int n;
    string name, state;
    set<string> s;
    cin >> n;
    
    for(int i = 0; i < n; i++){
        cin >> name >> state;
        if(s.find(name)!= s.end()){
            s.erase(name);
        } else{
            s.insert(name);
        }
    }

    vector<string> v;
    for(string str: s){
        v.push_back(str);
    }

    for(auto it = v.end()-1; it != v.begin()-1; it--){
        cout << *it << '\n';
    }

    return 0;
}